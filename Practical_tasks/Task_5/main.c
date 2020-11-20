/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ������ �� ����������� (���������� ������ �� ����� ���� ������ ���������, ���������� � � ��������� � ��������� ������� ���������, � ���������� ��������� � ����)
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
// #include <conio.h>
#include <locale.h>
#include <windows.h>

#include "input.c"
#include "parser.c"
#include "output.c"
#include "functions.c"

typedef struct
{
    int number;
    char surName[MAXSIZE];
    char name[MAXSIZE];
    char middleName[MAXSIZE];
    char group[MAXSIZE];
    int birthDay, birthMonth, birthYear;
    char email[MAXSIZE];
} studentStuct;

void readDatabase(char *fileName, studentStuct *students)
{
    char buffer[MAXSIZE];
    FILE *currFile;
    int studentNumber = 0;

    currFile = fopen(fileName, "r");
    fgets(NULL, MAXSIZE, currFile); //���������� ������ ������, �.�. ��� ����������� ������
    while (!feof(currFile))
    {
        fgets(buffer, MAXSIZE, currFile);
        students[studentNumber].number = buffer[0];
        printArray(buffer);
        strcpy(buffer, strtok(buffer, ";"));
        printArray(buffer);
        // strncpy(students[studentNumber].name, )
        studentNumber++;
    }
}

int main()
{

    studentStuct students[NUMBER_OF_STUDENTS];
    char fileName[MAXSIZE] = "";
    FILE *currFile = NULL;
    char action = '\0';
    int errorCode = 0;

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
        errorCode = chooseFile(fileName);
    } while (1 == errorCode);

    //�������� ������� ���� ������ � �����
    while (checkDatabase(fileName))
    {
        printf("� ������ ����� ��� ���� ������. �������� ����� ����:\n1)���������������� ���� ������.\n2)������� ����� ����");
        action = getchar();
        switch (action)
        {
        case '1':
            currFile = fopen(fileName, "a");
            fputs("0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n", currFile);
            fclose(currFile);
            break;
        case '2':
        {
            do
            {
                errorCode = chooseFile(fileName);
            } while (1 == errorCode);
            break;
        }
        }
    }
    printf("���� ������ ���������� � �����. ������� ������ ������.\n");

    //������ ���� ������ �� ����� � ������ �� � ���������
    readDatabase(fileName, students);

    printf("\n\n�����!");
    return 0;
}