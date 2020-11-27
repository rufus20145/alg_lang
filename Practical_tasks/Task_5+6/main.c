/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ������ �� ����������� (���������� ������ �� ����� ���� ������ ���������, ���������� � � ��������� � ��������� ������� ���������, � ����� ���������� ��������� � ����)
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
#include <locale.h>
#include <windows.h>

#include "input.c"
#include "parser.c"
#include "output.c"

int main()
{

    studentStuct students[NUMBER_OF_STUDENTS];
    char fileName[MAXSIZE] = "";
    // FILE *currFile = NULL;
    char action = '\0';
    int inputErrorCode = 0;

    system("cls"); //������� ������� ����� ������� ���������

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

    //�������� ����, ������� ����� ��������������
    do
    {
        inputErrorCode = chooseFile(fileName);
    } while (1 == inputErrorCode);

    //�������� ������� ���� ������ � �����
    while (checkDatabase(fileName))
    {
        printf("� ������ ����� ��� ���� ������. �������� ��������:\n1)���������������� ���� ������ (���� ����� ������).\n2)������� ����� ����.\n");
        action = getchar();
        fflush(stdin);
        switch (action)
        {
        case '1': //������������� ���� ������ � ����� � ��������������� ��������
        {
            char refString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail";
            FILE *currFile = fopen(fileName, "w");
            fputs(refString, currFile);
            fclose(currFile);
            break;
        }
        case '2': //����� ������ �����
        {
            do
            {
                inputErrorCode = chooseFile(fileName);
            } while (1 == inputErrorCode);
            break;
        }
        default:
        {
            printf("\n����������� ��������. ��������� �������.\n");
            break;
        }
        }
    }
    printf("���� ������ ���������� � �����. ������� ������ ������.\n");

    //������ ���� ������ �� ����� � ������ �� � ���������
    readDatabase(fileName, students);
    printf("������ ������� ��������� � �������� � ���������.\n");

    do
    {
        printf("\n�������� ��������:\n1)������� ���������� � ��������� �� �����.\n2)�������� �������� � ���� ������.\n3)������� ���������� � �������� �� ���� ������.\n4)�������� ���� ������.\n0)����� �� ���������.\n");
        action = getchar();
        fflush(stdin);
        switch (action)
        {
        case '1':
        {
            printStudentData(students[0]);
            printStudentData(students[1]);
        }
        case '2':
        {
        }
        }
        fflush(stdin);
    } while ('0' != action);

    printf("\n\n����� ���������.\n");
    return 0;
}