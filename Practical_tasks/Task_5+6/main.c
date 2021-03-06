/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ������ �� ����������� (���������� ������ �� ����� ���� ������ ���������, ���������� � � ��������� � ��������� ������� ���������, � ����� ���������� ��������� � ����)
 * @version 0.1
 * @date 2020-11-06
 * @todo ���������� ������ � ��������� �� ������� �����, �������� ������ ���������� ��������� ������������
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAXSIZE 256
#define FILENAME_SIZE 128
#define NUMBER_OF_STUDENTS 32

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

#include "input.c"
#include "parser.c"
#include "output.c"

int main()
{

    studentStruct students[NUMBER_OF_STUDENTS];
    char fileName[FILENAME_SIZE] = "";
    // FILE *currFile = NULL;
    int skipMenuFlag = 1, inProgram = 1;
    int inputErrorCode = 0, numberOfStudents = 0, showMenu = 0, action = 5;

    system("cls");     //������� ������� ����� ������� ���������
    srand(time(NULL)); //������ ����� seed ��� ���������� ��������� �����

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

    //�������������� ������ � ���������� ������ ���������
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        students[i].number = -1;
        students[i].numberOfSubjects = 0;
    }

    //�������� ���� ���������
    do
    {
        if (showMenu > 5 || 0 == skipMenuFlag) //��� ������ ������� skipMenuFlag == 1 � ���� �� ���������
        {
            showMenu = 0;
            printf("\n�������� ��������:\n1)������� ���������� � ��������� �� �����.\n2)�������� �������� � ���� ������.\n3)������� ���������� � �������� �� ���� ������.\n4)�������� ���� ������.\n5)������� ����� ����\n6)�������� ������ � ����\n0)����� �� ���������.\n");
        }
        if (0 == skipMenuFlag) //��� ������ ������� skipMenuFlag == 1 � action == 5, �.�. ���������� ����� ������� � ������ �����
        {
            do
            {
                inputErrorCode = enterNumber(&action);
            } while (1 == inputErrorCode);
        }
        switch (action) //�������� ���� ���������
        {
        case 1: //����� ���������� � ���� ���������
        {
            if (numberOfStudents > 0)
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfStudents; currStudentNumber++)
                {
                    printStudentData(students[currStudentNumber]);
                    showMenu++;
                }
            }
            else
            {
                printf("� ��������� ��� ������ � ���������. ��� ������ �������� ��.");
                showMenu++;
            }
            break;
        }
        case 2: //���������� �������� � ���� ������
        {
            int numberOfAddedStudents = 0;
            printf("������� ���������� ����������� ��������� ��� 0, ����� ����� � ������� ����: ");
            do
            {
                inputErrorCode = enterNumber(&numberOfAddedStudents);
            } while (1 == inputErrorCode);
            if (0 == numberOfAddedStudents)
            {
                printf("���������� ��������� ��������. ");
                showMenu += 2;
            }
            else if (numberOfStudents + numberOfAddedStudents > NUMBER_OF_STUDENTS)
            {
                printf("� ���������, ������ �� ����� ���������� ��������� �� ������. ������� ������.\n");
                showMenu += 2;
            }
            else
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfAddedStudents; currStudentNumber++)
                {
                    students[numberOfStudents + currStudentNumber].number = numberOfStudents + currStudentNumber + 1;
                    addStudentData(&students[numberOfStudents + currStudentNumber], currStudentNumber);
                }
                numberOfStudents += numberOfAddedStudents;
                showMenu += 6;
            }

            break;
        }
        case 3: //������� ���� ������
        {
            int currStudentNumber = 0, deletedStudentNumber = 0;
            if (students[currStudentNumber].number != -1)
            {
                while (students[currStudentNumber].number != -1) //���������� � for � numberOfStudents
                {
                    printStudentData(students[currStudentNumber]);
                    currStudentNumber++;
                    showMenu += 2;
                }
                printf("������� � ��������, ��������� � ������� ���� ������� ��� 0, ����� ����� � ������� ���� ");
                do
                {
                    inputErrorCode = enterNumber(&deletedStudentNumber);
                } while (1 == inputErrorCode);
                if (deletedStudentNumber == 0)
                {
                    printf("�������� ��������.");
                } // �������, ���� ����� 0
                else
                {
                    if (deletedStudentNumber <= numberOfStudents)
                    {
                        deleteStudentData(&students[deletedStudentNumber - 1]);
                        numberOfStudents--;
                        printf("�������� ������ �������.\n");
                        for (int i = deletedStudentNumber - 1; i < numberOfStudents; i++)
                        {
                            moveStudentData(&students[i], students[i + 1]);
                            printf("�������� �������� %d � %d. ", i + 2, i + 1);
                            deleteStudentData(&students[i + 1]);
                            printf("������� �������� ������ �������� %d. \n", i + 1);
                        }
                    }
                    else
                    {
                        printf("�������� � ����� ������� ��� � ���� ������.\n");
                    }
                }
            }
            else
            {
                printf("� ��������� ��� ������ � ���������. ����������  ������� ����������.");
                showMenu += 2;
            }
            break;
        }
        case 4: //�������, ��������
        {
            // srand(time(NULL));
            int deleteKey = rand() % 100, number = 0, wrongPasses = 0, numberOfPasses = 3;
            if (numberOfStudents > 0)
            {
                printf("��� �������� ������ ��������. ������� %d, ����� �������� ���� ������. ���������� �������: %d.\n", deleteKey, numberOfPasses);
                do
                {
                    printf("���� �����: ");
                    inputErrorCode = enterNumber(&number);
                    if (number != deleteKey && 0 == inputErrorCode)
                    {
                        wrongPasses++;
                        printf("�������, ���������� �������: %d ��.\n", numberOfPasses - wrongPasses);
                        showMenu++;
                    }
                } while ((inputErrorCode == 1) || ((number != deleteKey) && (wrongPasses < numberOfPasses)));
                showMenu += 2;
                if (number == deleteKey)
                {
                    printf("������� ������� ������� ��������.\n");
                    for (int i = 0; i < numberOfStudents; i++)
                    {
                        deleteStudentData(&students[i]);
                        printf("������� ������ �������� %d\n", i + 1);
                        showMenu++;
                    }
                    numberOfStudents = 0;
                    printf("������� ���������.");
                    showMenu += 2;
                }
                else
                {
                    printf("������� ��������.");
                    showMenu += 2;
                }
            }
            else
            {
                printf("� ��������� ��� ������ � ���������. ������� ����������.");
                showMenu++;
            }
            break;
        }
        case 5: //����� �������� �����
        {
            skipMenuFlag = 0;
            //�������� ����, ������� ����� ��������������
            printf("�������� ����.\n");
            do
            {
                showMenu++;
                clearArray(fileName, MAXSIZE);
                inputErrorCode = chooseFile(fileName);
            } while (1 == inputErrorCode);
            showMenu++;

                while (checkDatabase(fileName))
                {
                    printf("� ������ ����� ��� ���� ������. �������� ��������:\n1)���������������� ���� ������ (���� ����� ������).\n2)������� ����� ����.\n");
                    do
                    {
                        inputErrorCode = enterNumber(&action);
                    } while (inputErrorCode == 1);
                    switch (action)
                    {
                    case 1: //������������� ���� ������ � ����� � ��������������� ��������
                    {
                        char refString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
                        FILE *currFile = fopen(fileName, "w");
                        fputs(refString, currFile);
                        fclose(currFile);
                        break;
                    }
                    case 2: //����� ������ �����
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
                showMenu = 6;
                printf("������ ������� ��������� � �������� � ���������. ���������� ���������: %d.", numberOfStudents);
            break;
        }
        case 6:
        {

            break;
        }
        case 0:
        {

            inProgram = 0;
            break;
        }
        default:
        {
            printf("����������� ��������. ��������� �������.");
            showMenu += 2;
            break;
        }
        }
        if (1 == inProgram) //�������� ������� Enter ��� ������ � ������� ����
        {
            printf("\n������� Enter, ����� ����� � ������� ����. ");
            getchar();
            fflush(stdin);
        }
    } while (0 != action);

    printf("\n����� ���������.\n������� �� �������������!\n");
    return 0;
}