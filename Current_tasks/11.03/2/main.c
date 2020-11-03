/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ��������� ��������� �� ���� �������� ������(���, ����� ������, ����� ����������), � ����� ������� �� � ����
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
    if (array[arraySize - 1] != '\n')
    {
        printf("\n");
    }
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
        array[i] = '\0';
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
            printf("������ �����. ��������� �������. ");
            clearArray(array);
            return 0;
        }
    }
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
            // printf("%c �� �������� ������ ", array[i]);
            printf("������ �����. ��������� �������. ");
            clearArray(array);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    // printf("%d\n", GetConsoleCP());
    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }
    // printf("%d\n", GetConsoleCP());

    FILE *currFile;
    int action;
    char surName[MAXSIZE] = "", name[MAXSIZE] = "", middleName[MAXSIZE] = "", group[MAXSIZE] = "", resultString[MAXSIZE * MAXSIZE] = "";

    printf("�������� ��������:\n1.�������� ������ ��������\n2.������� ������ ���� ���������\n3.�������� ����\n0.����� �� ���������\n");
    do
    {
        scanf("%d", &action);
        fflush(stdin);
        // getchar(); // skip \n
        switch (action)
        {
        case 1: //���� ������ ������ ��������
        {
            currFile = fopen(argv[1], "a");
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
            enterGroup(group); //�3�-135�-20
            while (!isalpha(group[0]) || !isalpha(group[7]) || !isdigit(group[1]) || !isalpha(group[2]) || !isdigit(group[4]) || !isdigit(group[5]) || !isdigit(group[6]) || !isdigit(group[9]) || !isdigit(group[10]))
            {
                clearArray(group);
                enterGroup(group);
            }

            strcat(resultString, "������� ");
            strcat(resultString, surName);
            strcat(resultString, name);
            strcat(resultString, middleName);
            strcat(resultString, group);
            fprintf(currFile, "%s\n", resultString);
            fclose(currFile);
            strcat(resultString, "������� � ����.");
            printArray(resultString);
            clearArray(surName);
            clearArray(name);
            clearArray(middleName);
            clearArray(group);
            clearArray(resultString);
            break;
        }
        case 2: //����� ������ ��������� �� �����
        {
            printf("���������� ����� %s:\n", argv[1]);
            currFile = fopen(argv[1], "r");
            char tempString[MAXSIZE];
            if (currFile == NULL)
            {
                printf("������ �������� �����.\n");
            }
            else
            {
                while (!feof(currFile))
                {
                    fgets(tempString, MAXSIZE, currFile);
                    if (!feof(currFile))
                    {
                        printArray(tempString);
                    }
                }
                fclose(currFile);
            }
            break;
        }
        case 3: //������� �����
        {
            currFile = fopen(argv[1], "w");
            fclose(currFile);
            printf("���� ������� ������.\n");
            break;
        }
        case 0:
        {
            printf("����� �� ���������.\n");
            return 0;
        }
        default:
        {
            printf("������. ��������� �������");
            break;
        }
        }
    } while (action != 0);
    return 0;
}
