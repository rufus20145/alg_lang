/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief работа со структурами (программма читает из файла базу данных студентов, записывает её в стурктуру и позволяет вносить изменения, а потом записывает изменения в файл)
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

    system("cls"); //очищаем консоль перед стартом программы

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

    //инициализируем номера студентов
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        students[i].number = -1;
    }

    //выбираем файл, который будет использоваться
    do
    {
        clearArray(fileName, MAXSIZE);
        inputErrorCode = chooseFile(fileName);
    } while (1 == inputErrorCode);

    //проверка наличия базы данных в файле
    while (checkDatabase(fileName))
    {
        printf("В данном файле нет базы данных. Выберите действие:\n1)Инициализировать базу данных (файл будет очищен).\n2)Выбрать новый файл.\n");
        do
        {
            inputErrorCode = enterNumber(&action);
        } while (inputErrorCode == 1);
        switch (action)
        {
        case '1': //инициализация базы данных в файле с предварительной очисткой
        {
            char refString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail";
            FILE *currFile = fopen(fileName, "w");
            fputs(refString, currFile);
            fclose(currFile);
            break;
        }
        case '2': //выбор нового файла
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

    //чтение базы данных из файла и запись их в структуру
    readDatabase(fileName, students, &numberOfStudents);
    printf("Данные успешно прочитаны и записаны в структуру. Количество студентов: %d\n", numberOfStudents);

    //основное меню программы
    do
    {
        printf("\nВыберите действие:\n1)Вывести информацию о студентах на экран.\n2)Добавить студента в базу данных.\n3)Удалить информацию о студенте из базы данных.\n4)Очистить базу данных.\n5)Выбрать новый файл\n0)Выход из программы.\n");
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
                printf("В структуре нет данных о студентах. Для начала добавьте их.\n");
            }
            printf("Вывод заверешен. Нажмите Enter, чтобы продолжить.");
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

            //проверка наличия базы данных в файле
            while (checkDatabase(fileName))
            {
                printf("В данном файле нет базы данных. Выберите действие:\n1)Инициализировать базу данных (файл будет очищен).\n2)Выбрать новый файл.\n");
                do
                {
                    inputErrorCode = enterNumber(&action);
                } while (inputErrorCode == 1);
                switch (action)
                {
                case '1': //инициализация базы данных в файле с предварительной очисткой
                {
                    char refString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail";
                    FILE *currFile = fopen(fileName, "w");
                    fputs(refString, currFile);
                    fclose(currFile);
                    break;
                }
                case '2': //выбор нового файла
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
            printf("Данные успешно прочитаны и записаны в структуру. Количество студентов: %d\n", numberOfStudents);
            break;
        }
        }
        fflush(stdin);
    } while ('0' != action);

    printf("\n\nКонец программы.\n");
    return 0;
}