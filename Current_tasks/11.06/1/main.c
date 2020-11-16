/**
 * @file main.c
 * @author rufus20145 ()
 * @brief ������ �� �����������
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAXSIZE 256
#define NUMBER_OF_STUDENTS 32

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

#include "input.c"
#include "parser.c"
#include "output.c"

int main()
{
    struct studentStuct
    {
        int listNumber;
        char surName[MAXSIZE];
        char name[MAXSIZE];
        char middleName[MAXSIZE];
        char group[MAXSIZE];
        int birthDay, birthMonth, birthYear;
        char email[MAXSIZE];
    };
    struct studentStuct students[NUMBER_OF_STUDENTS];
    char fileName[MAXSIZE] = "";
    FILE *currFile;
    char action;

    setlocale(LC_ALL, "RUSSIAN");
    // if (GetConsoleCP() != 1251)
    // {
    //     SetConsoleCP(1251);
    //     SetConsoleOutputCP(1251);
    //     printf("ConsoleCP was changed.\n");
    // }

    do
    {
        // printf("������� 1, ����� ������� ������������ ����, ��� 2, ����� ������� ����. ");
        printf("�������� ����� ����:\n1)������� ������������ ����.\n2)������� ����� ����/�������� ������������.\n");
        action = getch();
        fflush(stdin);
        switch (action)
        {
        case '1': //����� ������������� �����
        {
            printf("������� ��� ������������� �����: ");
            enterCredential(fileName);
            if (fopen(fileName, "r") == NULL)
            {
                printf("������ �������� �����. ��������� �������.\n\n");
                action = '-';
            }
            else
            {
                printf("���� ������� ������.\n");
            }
            break;
        }
        case '2': //�������� ������ �����
        {
            printf("������� ��� �����, ������� ���������� �������: ");
            enterCredential(fileName);
            if (fopen(fileName, "r") != NULL)
            {
                printf("����� ���� ��� ����������, ������� 1, ���� �� ������ �������� ���, ����� ����� ����� �������.\n");
                if (getch() == '1')
                {
                    currFile = fopen(fileName, "w");
                    fclose(currFile);
                    printf("���� ������� ������.\n");
                }
                else {
                    printf("���� �� ��� ������.\n");
                }
                fflush(stdin);
            }
            else
            {
                currFile = fopen(fileName, "w");
                fclose(currFile);
                printf("���� ������� ������.\n");
            }
            break;
        }
        default://������ ������ ������
        {
            printf("����������� ��������. ��������� �������:\n");
            action = '-';
            break;
        }
        }
        if ('1' == action || '2' == action)
        {
            break;
        }
    } while ('-' == action);
    printf("�����!");
    return 0;
}