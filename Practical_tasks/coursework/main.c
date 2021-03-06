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
#include "sorter.c"
#include "output.c"

int main()
{

    studentStruct students[NUMBER_OF_STUDENTS];
    char fileName[FILENAME_SIZE] = "";
    // FILE *currFile = NULL;
    int skipMenuFlag = 1, inProgram = 1;
    int inputErrorCode = 0, numberOfStudents = 0, showMenu = 0, action = 4;

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
            printf("\n�������� ��������:\n1)������� ���������� � ��������� �� �����.\n2)�������� �������� � ���� ������.\n3)�������� ���� ������.\n4)������� ����� ����\n5)������ ������\n6)������� ������, ������������� ���, � �������� �� � ����\n0)����� �� ���������.\n");
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
        case 4: //����� �������� �����
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

            printf("������� ������ ������.\n");
            //������ ���� ������ �� ����� � ������ �� � ���������
            readDatabase(fileName, students, &numberOfStudents);
            showMenu += 6;
            printf((numberOfStudents > 0) ? "������ ������� ��������� � �������� � ���������. ���������� ���������: %d." : "���� ������.", numberOfStudents);
            break;
        }
        case 5: //���������� ������ � ��������
        {
            float tempSum = 0, totalSum = 0;
            int selectedStudent, numberOfSubjects = 0, markNumber = 0, totalMarkNumber = 0;
            char buffer[MAXSIZE];

            if (numberOfStudents > 0)
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfStudents; currStudentNumber++)
                {
                    printStudentData(students[currStudentNumber]);
                    showMenu++;
                }
                printf("������� ����� ��������, �������� �� ������ �������� ������, ��� 0, ����� ����� � ������� ���� ");
                do
                {
                    inputErrorCode = enterNumber(&selectedStudent);
                } while (1 == inputErrorCode);
                if (0 == selectedStudent)
                {
                    printf("���������� ������ ��������.");
                    showMenu += 2;
                }
                else
                {
                    if (selectedStudent <= numberOfStudents)
                    {
                        printf("������� ���������� ���������: ");
                        do
                        {
                            inputErrorCode = enterNumber(&numberOfSubjects);
                            if (numberOfSubjects > NUMBER_OF_SUBJECTS)
                            {
                                printf("� �� ���� ������� ����� ���������� ���������, ��������� ������� ");
                                numberOfSubjects = 0;
                                showMenu += 2;
                            }
                        } while (1 == inputErrorCode || numberOfSubjects > NUMBER_OF_SUBJECTS);
                        students[selectedStudent - 1].numberOfSubjects = numberOfSubjects;
                        for (int currSubject = 0; currSubject < numberOfSubjects; currSubject++)
                        {
                            printf("������� �������� �������� %d: ", currSubject + 1);
                            fgets(students[selectedStudent - 1].subjectName[currSubject], SUBJECT_NAME_SIZE, stdin);
                            students[selectedStudent - 1].subjectName[currSubject][strlen(students[selectedStudent - 1].subjectName[currSubject]) - 1] = '\0';
                            printf("������� ������ � �������� �� �������� %d: ", currSubject + 1);
                            fgets(buffer, MAXSIZE, stdin);
                            char *separatedBuffer = strtok(buffer, " ");
                            while (NULL != separatedBuffer)
                            {
                                if (markNumber < NUMBER_OF_MARKS)
                                {
                                    students[selectedStudent - 1].marks[currSubject][markNumber] = atoi(separatedBuffer);
                                    tempSum += students[selectedStudent - 1].marks[currSubject][markNumber];
                                    totalSum += students[selectedStudent - 1].marks[currSubject][markNumber];
                                    markNumber++;
                                    separatedBuffer = strtok(NULL, " ");
                                }
                                else
                                {
                                    printf("��� ��������� ������ �� ������ ������. ���� ������������� ����������");
                                }
                            }
                            students[selectedStudent - 1].numberOfMarks[currSubject] = markNumber;
                            students[selectedStudent - 1].averageMark[currSubject] = tempSum / markNumber;
                            totalMarkNumber += markNumber;
                            tempSum = 0;
                            markNumber = 0;
                            showMenu += 2;
                        }
                        students[selectedStudent - 1].totalAverageMark = totalSum / totalMarkNumber;
                    }
                    else
                    {
                        printf("�������� � ����� ������� ��� � ���� ������.\n");
                        showMenu += 4;
                    }
                }
            }
            else
            {
                printf("� ��������� ��� ������ � ���������. ��� ������ �������� ��.");
                showMenu++;
            }
            break;
        }
        case 6: //������ ���� ������ � ����
        {
            int arraySize = 0;
            int *array = NULL;
            char exportFileName[FILENAME_SIZE];
            // strcpy(exportFileName, fileName);//������ ������� �� � �������� �� ��������� ����
            // ����� ����� ��� �������� ������ � ������� ������ ���������
            do
            {
                clearArray(exportFileName, MAXSIZE);
                inputErrorCode = chooseFile(exportFileName);
            } while (1 == inputErrorCode);
            for (int i = 0; i < numberOfStudents; i++)
            {
                exportSudentData(students[i], exportFileName);
            }

            //���� � ���������� ������� (������� ��������� ������)
            printf("������� ������ �������: ");
            do
            {
                inputErrorCode = enterNumber(&arraySize);
            } while (1 == inputErrorCode);
            array = malloc(arraySize * sizeof(int));
            for (int i = 0; i < arraySize; i++)
            {
                printf("array[%d] = ", i + 1);
                do
                {
                    inputErrorCode = enterNumber(&array[i]);
                } while (1 == inputErrorCode);
            }
            sortArray(array, arraySize);
            printf("\n");
            FILE *exportFile = fopen(exportFileName, "a");
            fprintf(exportFile, "\n���������������  �� �������� ����� �� %d ���������:\n", arraySize);
            fprintf(stdout, "\n���������������  �� �������� ����� �� %d ���������:\n", arraySize);
            for (int i = 0; i < arraySize; i++)
            {
                fprintf(exportFile, "array[%d] = %d\n", i + 1, array[i]);
                printf("array[%d] = %d\n", i + 1, array[i]);
            }
            fclose(exportFile);
            free(array);
            array = NULL;
            showMenu += 6;
            break;
        }
        case 0: //����� �� ���������
        {
            // printf("�� �� ��������� ��������� � ����. ���� ������ ��������� ��, ������� 1 ");
            inProgram = 0;
            break;
        }
        default: //����������� ��������
        {
            printf("����������� ��������. ��������� �������.");
            showMenu++;
            break;
        }
        }
        if (1 == inProgram) //�������� ������� Enter ��� ������ � ������� ����
        {
            printf("\n������� Enter, ����� ����� � ������� ����. ");
            showMenu += 2;
            getchar();
            fflush(stdin);
        }
    } while (0 != action);

    printf("\n����� ���������.\n������� �� �������������!\n");
    return 0;
}