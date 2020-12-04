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
    int action = 0;
    int inputErrorCode = 0, numberOfStudents = 0;

    system("cls"); //������� ������� ����� ������� ���������

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

    //�������������� ������ ���������
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        students[i].number = -1;
    }

    //�������� ����, ������� ����� ��������������
    do
    {
        clearArray(fileName, MAXSIZE);
        inputErrorCode = chooseFile(fileName);
    } while (1 == inputErrorCode);

    //�������� ������� ���� ������ � �����
    while (checkDatabase(fileName))
    {
        printf("� ������ ����� ��� ���� ������. �������� ��������:\n1)���������������� ���� ������ (���� ����� ������).\n2)������� ����� ����.\n");
        do
        {
            inputErrorCode = enterNumber(&action);
        } while (inputErrorCode == 1);
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
                clearArray(fileName, MAXSIZE);
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
    readDatabase(fileName, students, &numberOfStudents);
    printf("������ ������� ��������� � �������� � ���������. ���������� ���������: %d\n", numberOfStudents);

    //�������� ���� ���������
    do
    {
        printf("\n�������� ��������:\n1)������� ���������� � ��������� �� �����.\n2)�������� �������� � ���� ������.\n3)������� ���������� � �������� �� ���� ������.\n4)�������� ���� ������.\n5)������� ����� ����\n0)����� �� ���������.\n");
        action = getchar();
        fflush(stdin);
        switch (action)
        {
        case '1':
        {
            int currStudentNumber = 0;
            if (students[currStudentNumber].number != -1)
            {
                while (students[currStudentNumber].number != -1)
                {
                    printStudentData(students[currStudentNumber]);
                    currStudentNumber++;
                }
            }
            else
            {
                printf("� ��������� ��� ������ � ���������. ��� ������ �������� ��.\n");
            }
            printf("����� ���������. ������� Enter, ����� ����������.");
            getchar();
            fflush(stdin);
            break;
        }
        case '2':
        {
            break;
        }
        case '5':
        {
            do
            {
                clearArray(fileName, MAXSIZE);
                inputErrorCode = chooseFile(fileName);
            } while (1 == inputErrorCode);

            //�������� ������� ���� ������ � �����
            while (checkDatabase(fileName))
            {
                printf("� ������ ����� ��� ���� ������. �������� ��������:\n1)���������������� ���� ������ (���� ����� ������).\n2)������� ����� ����.\n");
                do
                {
                    inputErrorCode = enterNumber(&action);
                } while (inputErrorCode == 1);
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
                        clearArray(fileName, MAXSIZE);
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

            //������� ��������� ��� ������ ������ �� ������ �����
            int currStudentNumber = 0;
            while (students[currStudentNumber].number != -1)
            {
                deleteStudentData(&students[currStudentNumber]);
                currStudentNumber++;
            }

            //������ ���� ������ �� ����� � ������ �� � ���������
            readDatabase(fileName, students, &numberOfStudents);
            printf("������ ������� ��������� � �������� � ���������. ���������� ���������: %d\n", numberOfStudents);
            break;
        }
        }
        fflush(stdin);
    } while ('0' != action);

    printf("\n\n����� ���������.\n");
    return 0;
}