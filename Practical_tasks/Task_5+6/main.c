/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief работа со структурами (программма читает из файла базу данных студентов, записывает её в стурктуру и позволяет вносить изменения, а потом записывает изменения в файл)
 * @version 0.1
 * @date 2020-11-06
 * @todo добавление файлов в структуру из другого файла
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
#include <time.h>

#include "input.c"
#include "parser.c"
#include "output.c"

int main()
{

    studentStruct students[NUMBER_OF_STUDENTS];
    char fileName[MAXSIZE] = "";
    // FILE *currFile = NULL;
    int inputErrorCode = 0, numberOfStudents = 0, showMenu = 6, action = 0;

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
        printf("В данном файле нет базы данных. Выберите действие:\n1)Инициализировать базу данных (ФАЙЛ БУДЕТ ОЧИЩЕН).\n2)Выбрать новый файл.\n");
        do
        {
            inputErrorCode = enterNumber(&action);
        } while (inputErrorCode == 1);
        printf("%d\n", action);
        switch (action)
        {
        case 1: //инициализация базы данных в файле с предварительной очисткой
        {
            printf("Entered case 1");
            char refString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
            FILE *currFile = fopen(fileName, "w");
            fputs(refString, currFile);
            fclose(currFile);
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

    //чтение базы данных из файла и запись их в структуру
    readDatabase(fileName, students, &numberOfStudents);
    printf("Данные успешно прочитаны и записаны в структуру. Количество студентов: %d\n", numberOfStudents);

    //основное меню программы
    do
    {
        if (showMenu > 5)
        {
            showMenu = 0;
            printf("\nВыберите действие:\n1)Вывести информацию о студентах на экран.\n2)Добавить студента в базу данных.\n3)Удалить информацию о студенте из базы данных.\n4)Очистить базу данных.\n5)Выбрать новый файл\n0)Выход из программы.\n");
        }
        do
        {
            inputErrorCode = enterNumber(&action);
        } while (1 == inputErrorCode);
        switch (action)
        {
        case 1: //кажется, работает
        {
            int currStudentNumber = 0;
            if (students[currStudentNumber].number != -1)
            {
                while (students[currStudentNumber].number != -1)
                {
                    printStudentData(students[currStudentNumber]);
                    currStudentNumber++;
                    showMenu += 2;
                }
            }
            else
            {
                printf("В структуре нет данных о студентах. Для начала добавьте их.\n");
            }
            printf("Вывод заверешен. Нажмите Enter, чтобы продолжить. ");
            getchar();
            fflush(stdin);
            break;
        }
        case 2:
        {

            break;
        }
        case 3: //кажется, работает
        {
            int currStudentNumber = 0, deletedStudentNumber = 0;
            if (students[currStudentNumber].number != -1)
            {
                while (students[currStudentNumber].number != -1)
                {
                    printStudentData(students[currStudentNumber]);
                    currStudentNumber++;
                    showMenu += 2;
                }
                printf("Введите № студента, инфрмацию о котором надо удалить: ");
                do
                {
                    inputErrorCode = enterNumber(&deletedStudentNumber);
                } while (1 == inputErrorCode);
                if (deletedStudentNumber == 0)
                {
                    printf("Удаление отменено.\n");
                    break;
                } // выходим, если нажат 0
                deleteStudentData(&students[deletedStudentNumber - 1]);
                numberOfStudents--;
                printf("Удаление прошло успешно.\n");
                for (int i = deletedStudentNumber - 1; i < numberOfStudents; i++)
                {
                    moveStudentData(&students[i], students[i + 1]);
                    printf("Сдвигаем студента %d в %d. ", i + 2, i + 1);
                    deleteStudentData(&students[i + 1]);
                    printf("Удаляем данные студента %d (дубликат).\n", i + 1);
                }
            }
            else
            {
                printf("В структуре нет данных о студентах. Невозможно  удалить информацию.\n");
                showMenu += 2;
            }
            break;
        }
        case 4:
        {
            srand(time(NULL));
            int deleteKey = rand() % 100, number = 0, wrongPasses = 0, numberOfPasses = 3;
            printf("Это действие нельзя отменить. Введите %d, чтобы очистить базу данных.\nКоличество попыток: %d.\n", deleteKey, numberOfPasses);

            do
            {
                printf("Ваше число: ");
                inputErrorCode = enterNumber(&number);
                if (number != deleteKey)
                {
                    wrongPasses++;
                    printf("Неверно, оставшиеся попытки: %d шт.\n", numberOfPasses - wrongPasses);
                    showMenu += 2;
                }
            } while ((inputErrorCode == 1) || ((number != deleteKey) && (wrongPasses < numberOfPasses)));
            if (number == deleteKey)
            {
                printf("Начинаю очистку массива структур.\n");
                for (int i = 0; i < numberOfStudents; i++)
                {
                    deleteStudentData(&students[i]);
                }
                numberOfStudents = 0;
                printf("Очистка завершена. Нажмите Enter, чтобы продолжить.\n");
                showMenu += 6;
                getchar();
                fflush(stdin);
            }
            else
            {
                printf("Очистка отменена. Нажмите Enter, чтобы продолжить.\n");
                getchar();
                fflush(stdin);
                showMenu += 2;
            }
            break;
        }
        case 5: //кажется, работает
        {
            //выбираем другой файл, который будет использоваться
            printf("Выбираем другой файл. ");
            do
            {
                clearArray(fileName, MAXSIZE);
                inputErrorCode = chooseFile(fileName);
            } while (1 == inputErrorCode);

            //проверка наличия базы данных в файле
            while (checkDatabase(fileName))
            {
                printf("В данном файле нет базы данных. Выберите действие:\n1)Инициализировать базу данных (ФАЙЛ БУДЕТ ОЧИЩЕН).\n2)Выбрать новый файл.\n");
                do
                {
                    inputErrorCode = enterNumber(&action);
                } while (inputErrorCode == 1);
                switch (action)
                {
                case 1: //инициализация базы данных в файле с предварительной очисткой
                {
                    char refString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
                    FILE *currFile = fopen(fileName, "w");
                    fputs(refString, currFile);
                    fclose(currFile);
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
            printf("Данные успешно прочитаны и записаны в структуру. Количество студентов: %d\n", numberOfStudents);
            showMenu = 6;
            break;
        }
        case 0:
            break;
        default:
        {
            printf("Неизвестная операция. Повторите попытку.\n");
            showMenu += 2;
            break;
        }
        }
    } while (0 != action);

    printf("\nКонец программы.\n");
    return 0;
}