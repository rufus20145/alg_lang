/**
 * @file main.c
 * @author rufus20145 ()
 * @brief работа со структурами
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
#include <conio.h>
#include <locale.h>
#include <windows.h>

#include "input.c"
#include "parser.c"
#include "output.c"

int main()
{
    struct studentStuct
    {
        int listNumber;
        char surName[MAXSIZE];
        char name[MAXSIZE];
        char middleName[MAXSIZE];
        char group[MAXSIZE];
        int birthDay, birthMonth, birthYear;
        char email[MAXSIZE];
    };
    struct studentStuct students[NUMBER_OF_STUDENTS];
    char fileName[MAXSIZE] = "";
    FILE *currFile;
    char action;

    setlocale(LC_ALL, "RUSSIAN");
    // if (GetConsoleCP() != 1251)
    // {
    //     SetConsoleCP(1251);
    //     SetConsoleOutputCP(1251);
    //     printf("ConsoleCP was changed.\n");
    // }

    do
    {
        // printf("Нажмите 1, чтобы выбрать существующий файл, или 2, чтобы создать файл. ");
        printf("Выберите пункт меню:\n1)Выбрать существующий файл.\n2)Создать новый файл/очистить существующий.\n");
        action = getch();
        fflush(stdin);
        switch (action)
        {
        case '1': //выбор существующего файла
        {
            printf("Введите имя существующего файла: ");
            enterCredential(fileName);
            if (fopen(fileName, "r") == NULL)
            {
                printf("Ошибка открытия файла. Повторите попытку.\n\n");
                action = '-';
            }
            else
            {
                printf("Файл успешно найден.\n");
            }
            break;
        }
        case '2': //создание нового файла
        {
            printf("Введите имя файла, который необходимо создать: ");
            enterCredential(fileName);
            if (fopen(fileName, "r") != NULL)
            {
                printf("Такой файл уже существует, нажмите 1, если вы хотите очистить его, иначе любую другю клавишу.\n");
                if (getch() == '1')
                {
                    currFile = fopen(fileName, "w");
                    fclose(currFile);
                    printf("Файл успешно очищен.\n");
                }
                else {
                    printf("Файл не был очищен.\n");
                }
                fflush(stdin);
            }
            else
            {
                currFile = fopen(fileName, "w");
                fclose(currFile);
                printf("Файл успешно создан.\n");
            }
            break;
        }
        default://введен другой символ
        {
            printf("Незивестная операция. Повторите попытку:\n");
            action = '-';
            break;
        }
        }
        if ('1' == action || '2' == action)
        {
            break;
        }
    } while ('-' == action);
    printf("Успех!");
    return 0;
}