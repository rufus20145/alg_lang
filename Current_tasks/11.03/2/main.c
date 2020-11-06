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

#include "input.c"
#include "parser.c"
#include "output.c"

#define MAXSIZE 256

/**
 * @brief �������� �������
 *
 * @return int ��� ������ � �������
 */
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }
    char fileName[MAXSIZE] = "";
    FILE *currFile;
    int action;
    char surName[MAXSIZE] = "", name[MAXSIZE] = "", middleName[MAXSIZE] = "", group[MAXSIZE] = "", resultString[MAXSIZE * MAXSIZE] = "";
    printf("������� ��� �����:");
    enterCredential(fileName);
    while (fopen(fileName, "r") == NULL)
    {
        printf("������ � ����� �����. ��������� �������:");
        enterCredential(fileName);
    }
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
            currFile = fopen(fileName, "a");
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
            printf("������� ����� ������: ");
            enterCredential(group); //� ������� �3�-135�-20 (3 ������ - �����)
            while (!isalpha(group[0]) || !isalpha(group[7]) || !isdigit(group[1]) || !isalpha(group[2]) || !isdigit(group[4]) || !isdigit(group[5]) || !isdigit(group[6]) || !isdigit(group[9]) || !isdigit(group[10]))
            {
                printf("������ �����. ��������� �������.");
                clearArray(group);
                enterCredential(group);
            }

            strcat(resultString, "������� "); //���������� ������ � ��� � ������� ������ � ����
            strcat(resultString, surName);
            strcat(resultString, name);
            strcat(resultString, middleName);
            strcat(resultString, group);

            fprintf(currFile, "%s\n", resultString); //���������� ������� ������ � ����
            fclose(currFile);
            strcat(resultString, "������� � ����.");
            printArray(resultString);

            clearArray(surName); //������� ������ ����� �������������
            clearArray(name);
            clearArray(middleName);
            clearArray(group);
            clearArray(resultString);
            break;
        }
        case 2: //����� ������ ��������� �� �����
        {
            printf("���������� ����� %s:\n", fileName);
            currFile = fopen(fileName, "r");
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
            currFile = fopen(fileName, "w");
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
