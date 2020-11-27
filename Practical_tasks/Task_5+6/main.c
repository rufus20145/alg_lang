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
    char action = '\0';
    int inputErrorCode = 0;

    system("cls"); //очищаем консоль перед стартом программы

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

    //выбираем файл, который будет использоваться
    do
    {
        inputErrorCode = chooseFile(fileName);
    } while (1 == inputErrorCode);

    //проверка наличия базы данных в файле
    while (checkDatabase(fileName))
    {
        printf("В данном файле нет базы данных. Выберите действие:\n1)Инициализировать базу данных (файл будет очищен).\n2)Выбрать новый файл.\n");
        action = getchar();
        fflush(stdin);
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
    readDatabase(fileName, students);
    printf("Данные успешно прочитаны и записаны в структуру.\n");

    do
    {
        printf("\nВыберите действие:\n1)Вывести информацию о студентах на экран.\n2)Добавить студента в базу данных.\n3)Удалить информацию о студенте из базы данных.\n4)Очистить базу данных.\n0)Выход из программы.\n");
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

    printf("\n\nКонец программы.\n");
    return 0;
}