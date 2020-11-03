/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ��������� ��������� �� ���� �������� ������(���, ����� ������, ����� ����������), � ����� ������� ��
 * @version 0.1
 * @date 2020-10-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define MAXSIZE 256
/**
 * @brief ������� ������ ������� ��������
 * 
 * @param array ������ ��� ������
 */
void printArray(char *array)
{
    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%c", array[i]);
    }
    printf("\n");
}
/**
 * @brief ������� ��� ������� �������
 * 
 * @param array - ������ ��� �������
 */
void clearArray(char *array)
{
    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '0';
    }
}

/**
 * @brief ������� ����� ������ ������
 * 
 * @param array ������ ���� ������ ��������� ������
 */
void enterGroup(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
            array[i] = ' ';
            break;
        }
        else
        {
            array[i] = buffer;
        }
    }
}

/**
 * @brief ������� ����� ���
 * 
 * @param array ������, ���� ������ ��������� ������
 * @return void
 */
void enterCredential(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
            array[i] = ' ';
            break;
        }
        else
        {
            array[i] = buffer;
        }
    }
}
/**
 * @brief ������� �������� ������ ������
 * 
 * @param array ������ � ������� ������ ��� ��������
 * @return int ��������� ��������
 */
int checkGroup(char *array)
{
    int arraySize = strlen(array);
    arraySize--; // ��� ����� �� ��������� ������ � ������ ��� �� ���� ��������� �� �����
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha(array[i]))
        {
            printf("%c �� �������� ������ ", array[i]);
            printf("Error. Try again. ");
            clearArray(array);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}

/**
 * @brief ������� �������� ���
 * 
 * @param array ������ ��� ��������
 * @return int ��������� ��������
 */
int checkCredential(char *array)
{
    int arraySize = strlen(array);
    arraySize--; // ��� ����� �� ��������� ������ � ������ ��� �� ���� ��������� �� �����
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha(array[i]))
        {
            printf("%c �� �������� ������ ", array[i]);
            printf("Error. Try again. ");
            clearArray(array);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}

/**
 * @brief �������� �������
 * 
 * @return int ��� ������ � �������
 */
int main()
{
    printf("%d\n", GetConsoleCP());
    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }
    printf("%d\n", GetConsoleCP());

    char surName[MAXSIZE] = "", name[MAXSIZE] = "", middleName[MAXSIZE] = "", group[MAXSIZE] = "", resultString[MAXSIZE * MAXSIZE] = "";
    printf("������� �������: ");
    do
    {
        enterCredential(surName);
    } while (0 == checkCredential(surName));
    printf("������� ���: ");
    do
    {
        enterCredential(name);
    } while (0 == checkCredential(name));
    printf("������� ��������: ");
    do
    {
        enterCredential(middleName);
    } while (0 == checkCredential(middleName));
    printf("������� ����� ������:");
    do
    {
        enterGroup(group);
    } while (0 == checkGroup(group));

    strcat(resultString, "������� ");
    strcat(resultString, surName);
    strcat(resultString, name);
    strcat(resultString, middleName);
    strcat(resultString, group);
    return 0;
}
