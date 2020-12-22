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
    int skipMenuFlaG = 1, inProgram = 1;
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

    //�������������� ������ ���������
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        students[i].number = -1;
    }

    //�������� ���� ���������
    do
    {
        if (showMenu > 5 && 0 == skipMenuFlaG) //��� ������ ������� skipMenuFlaG == 1 � ���� �� ���������
        {
            showMenu = 0;
            printf("\n�������� ��������:\n1)������� ���������� � ��������� �� �����.\n2)�������� �������� � ���� ������.\n3)������� ���������� � �������� �� ���� ������.\n4)�������� ���� ������.\n5)������� ����� ����\n6)������ ������\n7)������� ������\n8)������� ������, ������������� ���, � �������� �� � ����\n0)����� �� ���������.\n");
        }
        if (0 == skipMenuFlaG) //��� ������ ������� skipMenuFlaG == 1 � action == 5, �.�. ���������� ����� ������� � ������ �����
        {
            do
            {
                inputErrorCode = enterNumber(&action);
            } while (1 == inputErrorCode);
        }
        switch (action) //�������� ���� ���������
        {
        case 1: //�������, ��������
        {
            if (numberOfStudents > 0)
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfStudents; currStudentNumber++)
                {
                    printStudentData(students[currStudentNumber]);
                    showMenu += 2;
                }
            }
            else
            {
                printf("� ��������� ��� ������ � ���������. ��� ������ �������� ��.");
                showMenu++;
            }
            break;
        }
        case 2: //�������, ��������
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
        case 3: //�������, ��������
        {
            int currStudentNumber = 0, selectedStudent = 0;
            if (numberOfStudents > 0)
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfStudents; currStudentNumber++)
                {
                    printStudentData(students[currStudentNumber]);
                    showMenu += 2;
                }
                printf("������� � ��������, ��������� � ������� ���� ������� ��� 0, ����� ����� � ������� ���� ");
                do
                {
                    inputErrorCode = enterNumber(&selectedStudent);
                } while (1 == inputErrorCode);
                if (selectedStudent == 0)
                {
                    printf("�������� ��������.");
                    showMenu += 2;
                } // �������, ���� ����� 0
                else
                {
                    if (selectedStudent <= numberOfStudents)
                    {
                        deleteStudentData(&students[selectedStudent - 1]);
                        numberOfStudents--;
                        printf("�������� ������ �������.\n");
                        for (int i = selectedStudent - 1; i < numberOfStudents; i++)
                        {
                            moveStudentData(&students[i], students[i + 1]);
                            printf("�������� �������� %d � %d. ", i + 2, i + 1);
                            deleteStudentData(&students[i + 1]);
                            printf("������� �������� ������ �������� %d. \n", i + 1);
                            showMenu += 2;
                        }
                        showMenu++;
                    }
                    else
                    {
                        printf("�������� � ����� ������� ��� � ���� ������.\n");
                        showMenu += 2;
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
            int deleteKey = rand() % 100, number = 0, wrongPasses = 0, numberOfPasses = 3;
            if (numberOfStudents > 0)
            {
                printf("��� �������� ������ ��������. ������� %d, ����� �������� ���� ������. ���������� �������: %d.\n", deleteKey, numberOfPasses);

                do
                {
                    printf("���� �����: ");
                    inputErrorCode = enterNumber(&number);
                    if (number != deleteKey)
                    {
                        wrongPasses++;
                        printf("�������, ���������� �������: %d ��.\n", numberOfPasses - wrongPasses);
                        showMenu += 3;
                    }
                } while ((inputErrorCode == 1) || ((number != deleteKey) && (wrongPasses < numberOfPasses)));
                if (number == deleteKey)
                {
                    printf("������� ������� ������� ��������.\n");
                    showMenu++;
                    for (int i = 0; i < numberOfStudents; i++)
                    {
                        deleteStudentData(&students[i]);
                        printf("������� ������ �������� %d\n", i + 1);
                        showMenu++;
                    }
                    numberOfStudents = 0;
                    printf("������� ���������.");
                    showMenu++;
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
        case 5: //�������, ��������
        {
            skipMenuFlaG = 0;
            //�������� ����, ������� ����� ��������������
            printf("�������� ����.\n");
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
                    showMenu++;
                } while (inputErrorCode == 1);
                switch (action)
                {
                case 1: //������������� ���� ������ � ����� � ��������������� ��������
                {
                    char refString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
                    FILE *currFile = fopen(fileName, "w");
                    fputs(refString, currFile);
                    fclose(currFile);
                    printf("���� ������� ������.");
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
            showMenu += 6;
            printf("������ ������� ��������� � �������� � ���������. ���������� ���������: %d.", numberOfStudents);

            break;
        }
        case 6:
        {
            float tempSum = 0;
            int selectedStudent, numberOfSubjects = 0, markNumber = 0;
            char buffer[MAXSIZE];

            if (numberOfStudents > 0)
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfStudents; currStudentNumber++)
                {
                    printStudentData(students[currStudentNumber]);
                }
                printf("������� ����� ��������, �������� �� ������ �������� ������, ��� 0, ����� ����� � ������� ���� ");
                do
                {
                    inputErrorCode = enterNumber(&selectedStudent);
                } while (1 == inputErrorCode);
                if (0 == selectedStudent)
                {
                    printf("���������� ������ ��������.");
                }
                else
                {

                    if (selectedStudent <= numberOfStudents)
                    {
                        printf("������� ���������� ���������:");
                        do
                        {
                            if (numberOfSubjects > NUMBER_OF_SUBJECTS)
                            {
                                printf("� �� ���� ������� ����� ���������� ���������, ��������� ������� ");
                            }
                            inputErrorCode = enterNumber(&numberOfSubjects);
                        } while (1 == inputErrorCode || numberOfSubjects > NUMBER_OF_SUBJECTS);
                        students[selectedStudent - 1].numberOfSubjects = numberOfSubjects;
                        for (int currSubject = 0; currSubject < numberOfSubjects; currSubject++)
                        {
                            printf("������� �������� �������� %d: ", currSubject + 1);
                            fgets(students[selectedStudent - 1].subjectName[currSubject], SUBJECT_NAME_SIZE, stdin);
                            students[selectedStudent - 1].subjectName[currSubject][strlen(students[selectedStudent - 1].subjectName[currSubject]) - 1] = '\0';
                            printf("������� ������ � �������� �� �������� %d: ", currSubject + 1);
                            fgets(buffer, 256, stdin);
                            char *separatedBuffer = strtok(buffer, " ");
                            while (NULL != separatedBuffer)
                            {
                                students[selectedStudent - 1].marks[currSubject][markNumber] = atoi(separatedBuffer);
                                tempSum += students[selectedStudent - 1].marks[currSubject][markNumber];
                                markNumber++;
                                separatedBuffer = strtok(NULL, " ");
                            }
                            students[selectedStudent - 1].numberOfMarks[currSubject] = markNumber;
                            students[selectedStudent - 1].averageMark[currSubject] = tempSum / markNumber;
                            tempSum = 0;
                            markNumber = 0;
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
                printf("� ��������� ��� ������ � ���������. ��� ������ �������� ��.");
            }
            break;
        }
        case 7:
        {
            int selectedStudent;
            if (numberOfStudents > 0)
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfStudents; currStudentNumber++)
                {
                    printStudentData(students[currStudentNumber]);
                }
                printf("������� ����� ��������, ������ �������� �� ������ �������, ��� 0, ����� ����� � ������� ���� ");
                do
                {
                    inputErrorCode = enterNumber(&selectedStudent);
                } while (1 == inputErrorCode);
                if (0 == selectedStudent)
                {
                    printf("����� ������ �������.");
                }
                else
                {
                    if (selectedStudent <= numberOfStudents)
                    {
                        if (students[selectedStudent - 1].numberOfSubjects > 0)
                        {
                            for (int currSubject = 0; currSubject < students[selectedStudent - 1].numberOfSubjects; currSubject++)
                            {
                                printf("������ �������� %d �� �������� %s\t", selectedStudent, students[selectedStudent - 1].subjectName[currSubject]);
                                for (int currMark = 0; currMark < students[selectedStudent - 1].numberOfMarks[currSubject]; currMark++)
                                {
                                    printf("%d ", students[selectedStudent - 1].marks[currSubject][currMark]);
                                }
                                printf("\t������� ���� = %.2f", students[selectedStudent - 1].averageMark[currSubject]);
                                printf("\n");
                            }
                        }
                        else
                        {
                            printf("� ������� �������� ��� ������ �� �������. ��� ������ �������� ��.");
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
                printf("� ��������� ��� ������ � ���������. ��� ������ �������� ��.");
            }
            break;
        }
        case 8: //�������, ��������
        {
            int arraySize = 0;
            int *array = NULL;
            char exportFileName[FILENAME_SIZE];
            do
            {
                clearArray(exportFileName, MAXSIZE);
                inputErrorCode = chooseFile(exportFileName);
            } while (1 == inputErrorCode);
            for (int i = 0; i < numberOfStudents; i++)
            {
                exportSudentData(students[i], exportFileName);
            }

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
            fprintf(exportFile, "\n��������������� ����� �� %d ���������:\n", arraySize);
            for (int i = 0; i < arraySize; i++)
            {
                fprintf(exportFile, "array[%d] = %d\n", i + 1, array[i]);
                printf("array[%d] = %d\n", i + 1, array[i]);
            }
            fclose(exportFile);
            free(array);
            array = NULL;
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