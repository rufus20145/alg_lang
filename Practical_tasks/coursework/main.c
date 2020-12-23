/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief работа со структурами (программма читает из файла базу данных студентов, записывает её в стурктуру и позволяет вносить изменения, а потом записывает изменения в файл)
 * @version 0.1
 * @date 2020-11-06
 * @todo добавление файлов в структуру из другого файла, удаление данных нескольких студентов одновременно
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
    int inputErrorCode = 0, numberOfStudents = 0, showMenu = 0, action = 5;

    system("cls");     //очищаем консоль перед стартом программы
    srand(time(NULL)); //задаем новый seed для генератора случайных чисел

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

    //инициализируем номера и количество оценок студентов
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        students[i].number = -1;
        students[i].numberOfSubjects = 0;
    }

    //основное меню программы
    do
    {
        if (showMenu > 5 && 0 == skipMenuFlag) //при первом запуске skipMenuFlag == 1 и меню не выводится
        {
            showMenu = 0;
            printf("\nВыберите действие:\n1)Вывести информацию о студентах на экран.\n2)Добавить студента в базу данных.\n3)Удалить информацию о студенте из базы данных.\n4)Очистить базу данных.\n5)Выбрать новый файл\n6)Ввести оценки\n7)Вывести оценки\n8)Считать массив, отсортировать его, и записать всё в файл\n0)Выход из программы.\n");
        }
        if (0 == skipMenuFlag) //при первом запуске skipMenuFlag == 1 и action == 5, т.к. необходимо сразу перейти к выбору файла
        {
            do
            {
                inputErrorCode = enterNumber(&action);
            } while (1 == inputErrorCode);
        }
        switch (action) //основное меню программы
        {
        case 1: //вывод информации о всех студентах
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
                printf("В структуре нет данных о студентах. Для начала добавьте их.");
                showMenu++;
            }
            break;
        }
        case 2: //добавление студента в базу данных
        {
            int numberOfAddedStudents = 0;
            printf("Введите количество добавляемых студентов или 0, чтобы выйти в главное меню: ");
            do
            {
                inputErrorCode = enterNumber(&numberOfAddedStudents);
            } while (1 == inputErrorCode);
            if (0 == numberOfAddedStudents)
            {
                printf("Добавление студентов отменено. ");
                showMenu += 2;
            }
            else if (numberOfStudents + numberOfAddedStudents > NUMBER_OF_STUDENTS)
            {
                printf("К сожалению, памяти на такое количество студентов не хватит. Начните заново.\n");
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
        case 3: //удаление студента из базы данных
        {
            int selectedStudent = 0;
            if (numberOfStudents > 0)
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfStudents; currStudentNumber++)
                {
                    printStudentData(students[currStudentNumber]);
                    showMenu++;
                }
                printf("Введите № студента, инфрмацию о котором надо удалить или 0, чтобы выйти в главное меню ");
                do
                {
                    inputErrorCode = enterNumber(&selectedStudent);
                } while (1 == inputErrorCode);
                if (selectedStudent == 0)
                {
                    printf("Удаление отменено.");
                    showMenu += 2;
                } // выходим, если нажат 0
                else
                {
                    if (selectedStudent <= numberOfStudents)
                    {
                        deleteStudentData(&students[selectedStudent - 1]);
                        numberOfStudents--;
                        printf("Удаление прошло успешно.\n");
                        for (int i = selectedStudent - 1; i < numberOfStudents; i++)
                        {
                            moveStudentData(&students[i], students[i + 1]);
                            printf("Сдвигаем студента %d в %d. ", i + 2, i + 1);
                            deleteStudentData(&students[i + 1]);
                            printf("Удаляем дубликат данных студента %d. \n", i + 1);
                            showMenu += 2;
                        }
                        showMenu++;
                    }
                    else
                    {
                        printf("Студента с таким номером нет в базе данных.\n");
                        showMenu += 2;
                    }
                }
            }
            else
            {
                printf("В структуре нет данных о студентах. Невозможно  удалить информацию.");
                showMenu++;
            }
            break;
        }
        case 4: //очистка базы данных
        {
            int deleteKey = rand() % 100, number = 0, wrongPasses = 0, numberOfPasses = 3;
            if (numberOfStudents > 0)
            {
                printf("Это действие нельзя отменить. Введите %d, чтобы очистить базу данных. Количество попыток: %d.\n", deleteKey, numberOfPasses);
                do
                {
                    printf("Ваше число: ");
                    inputErrorCode = enterNumber(&number);
                    if (number != deleteKey && 0 == inputErrorCode)
                    {
                        printf("Неверно, оставшиеся попытки: %d шт.\n", numberOfPasses - wrongPasses);
                        wrongPasses++;
                        showMenu++;
                    }
                } while ((inputErrorCode == 1) || ((number != deleteKey) && (wrongPasses < numberOfPasses)));
                showMenu += 2;
                if (number == deleteKey)
                {
                    printf("Начинаю очистку массива структур.\n");
                    for (int i = 0; i < numberOfStudents; i++)
                    {
                        deleteStudentData(&students[i]);
                        printf("Удалены данные студента %d\n", i + 1);
                        showMenu++;
                    }
                    numberOfStudents = 0;
                    printf("Очистка завершена.");
                    showMenu += 2;
                }
                else
                {
                    printf("Очистка отменена.");
                    showMenu += 2;
                }
            }
            else
            {
                printf("В структуре нет данных о студентах. Очистка невозможна.");
                showMenu++;
            }
            break;
        }
        case 5: //смена рабочего файла
        {
            skipMenuFlag = 0;
            //выбираем файл, который будет использоваться
            printf("Выберите файл.\n");
            do
            {
                showMenu++;
                clearArray(fileName, MAXSIZE);
                inputErrorCode = chooseFile(fileName);
            } while (1 == inputErrorCode);
            showMenu++;
            //проверка наличия базы данных в файле
            while (checkDatabase(fileName))
            {
                printf("В данном файле нет базы данных. Выберите действие:\n1)Инициализировать базу данных (ФАЙЛ БУДЕТ ОЧИЩЕН).\n2)Выбрать новый файл.\n");
                do
                {
                    inputErrorCode = enterNumber(&action);
                    showMenu++;
                } while (inputErrorCode == 1);
                switch (action)
                {
                case 1: //инициализация базы данных в файле с предварительной очисткой
                {
                    char refString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
                    FILE *currFile = fopen(fileName, "w");
                    fputs(refString, currFile);
                    fclose(currFile);
                    printf("Файл успешно очищен.");
                    break;
                }
                case 2: //выбор нового файла
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
                    printf("\nНеизвестная операция. Повторите попытку.\n");
                    break;
                }
                }
            }
            printf("База данных обнаружена в файле. Начинаю чтение данных.\n");

            //очистка структуры для записи данных из нового файла
            int currStudentNumber = 0;
            while (students[currStudentNumber].number != -1)
            {
                deleteStudentData(&students[currStudentNumber]);
                currStudentNumber++;
            }

            //чтение базы данных из файла и запись их в структуру
            readDatabase(fileName, students, &numberOfStudents);
            showMenu += 6;
            printf("Данные успешно прочитаны и записаны в структуру. Количество студентов: %d.", numberOfStudents);

            break;
        }
        case 6: //добавление оценок к студенту
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
                printf("Введите номер студента, которому вы хотите добавить оценки, или 0, чтобы выйти в главное меню ");
                do
                {
                    inputErrorCode = enterNumber(&selectedStudent);
                } while (1 == inputErrorCode);
                if (0 == selectedStudent)
                {
                    printf("Добавление оценок отменено.");
                    showMenu += 2;
                }
                else
                {
                    if (selectedStudent <= numberOfStudents)
                    {
                        printf("Введите количество предметов: ");
                        do
                        {
                            if (numberOfSubjects > NUMBER_OF_SUBJECTS)
                            {
                                printf("Я не могу хранить такое количество предметов, повторите попытку ");
                                numberOfSubjects = 0;
                                showMenu += 2;
                            }
                            inputErrorCode = enterNumber(&numberOfSubjects);
                        } while (1 == inputErrorCode || numberOfSubjects > NUMBER_OF_SUBJECTS);
                        students[selectedStudent - 1].numberOfSubjects = numberOfSubjects;
                        for (int currSubject = 0; currSubject < numberOfSubjects; currSubject++)
                        {
                            printf("Введите название предмета %d: ", currSubject + 1);
                            fgets(students[selectedStudent - 1].subjectName[currSubject], SUBJECT_NAME_SIZE, stdin);
                            students[selectedStudent - 1].subjectName[currSubject][strlen(students[selectedStudent - 1].subjectName[currSubject]) - 1] = '\0';
                            printf("Введите строку с оценками по предмету %d: ", currSubject + 1);
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
                                    printf("Для следующей оценки не хватит памяти. Ввод принудительно остановлен");
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
                        printf("Студента с таким номером нет в базе данных.\n");
                        showMenu += 4;
                    }
                }
            }
            else
            {
                printf("В структуре нет данных о студентах. Для начала добавьте их.");
                showMenu++;
            }
            break;
        }
        case 7: //вывод оценок студента
        {
            int selectedStudent;
            if (numberOfStudents > 0)
            {
                for (int currStudentNumber = 0; currStudentNumber < numberOfStudents; currStudentNumber++)
                {
                    printStudentData(students[currStudentNumber]);
                    showMenu++;
                }
                printf("Введите номер студента, оценки которого вы хотите вывести, или 0, чтобы выйти в главное меню ");
                do
                {
                    inputErrorCode = enterNumber(&selectedStudent);
                } while (1 == inputErrorCode);
                if (0 == selectedStudent)
                {
                    printf("Вывод оценок отменен.");
                    showMenu += 2;
                }
                else
                {
                    if (selectedStudent <= numberOfStudents)
                    {
                        if (students[selectedStudent - 1].numberOfSubjects > 0)
                        {
                            printf("\n");
                            for (int currSubject = 0; currSubject < students[selectedStudent - 1].numberOfSubjects; currSubject++)
                            {
                                printf("Оценки студента %d по предмету %s ", selectedStudent, students[selectedStudent - 1].subjectName[currSubject]);
                                for (int currMark = 0; currMark < students[selectedStudent - 1].numberOfMarks[currSubject]; currMark++)
                                {
                                    printf("%d ", students[selectedStudent - 1].marks[currSubject][currMark]);
                                }
                                printf(" Средний балл = %.2f.", students[selectedStudent - 1].averageMark[currSubject]);
                                printf("\n");
                                showMenu += 2;
                            }
                            printf("Общий средний балл = %.2f\n", students[selectedStudent - 1].totalAverageMark);
                        }
                        else
                        {
                            printf("У данного студента нет данных об оценках. Для начала добавьте их.");
                            showMenu += 2;
                        }
                    }
                    else
                    {
                        printf("Студента с таким номером нет в базе данных.\n");
                        showMenu += 2;
                    }
                }
            }
            else
            {
                printf("В структуре нет данных о студентах. Для начала добавьте их.");
                showMenu++;
            }
            break;
        }
        case 8: //запись всех данных в файл
        {
            int arraySize = 0;
            int *array = NULL;
            char exportFileName[FILENAME_SIZE];
            //выбор файла для экспорта данных и экспорт данных студентов
            do
            {
                clearArray(exportFileName, MAXSIZE);
                inputErrorCode = chooseFile(exportFileName);
            } while (1 == inputErrorCode);
            for (int i = 0; i < numberOfStudents; i++)
            {
                exportSudentData(students[i], exportFileName);
            }

            //ввод и сортировка массива (задание куросовой работы)
            printf("Введите размер массива: ");
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
            fprintf(exportFile, "\nОтсортированный  по убыванию масив из %d элементов:\n", arraySize);
            fprintf(stdout, "\nОтсортированный  по убыванию масив из %d элементов:\n", arraySize);
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
        case 0: //выход из программы
        {

            inProgram = 0;
            break;
        }
        default: //неизвестная операция
        {
            printf("Неизвестная операция. Повторите попытку.");
            showMenu++;
            break;
        }
        }
        if (1 == inProgram) //ожидание нажатия Enter для выхода в главное меню
        {
            printf("\nНажмите Enter, чтобы выйти в главное меню. ");
            getchar();
            fflush(stdin);
        }
    } while (0 != action);

    printf("\nКонец программы.\nСпасибо за использование!\n");
    return 0;
}