/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief Программа принимает на вход анкетные данные(ФИО, номер группы, номер факультета), а затем выводит их в файл
 * @version 0.1
 * @date 2020-10-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#include "input.c"
#include "parser.c"
#include "output.c"

#define MAXSIZE 256

/**
 * @brief основная функция
 *
 * @return int код ошибки в систему
 */
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }
    char fileName[MAXSIZE] = "";
    FILE *currFile;
    int action;
    char surName[MAXSIZE] = "", name[MAXSIZE] = "", middleName[MAXSIZE] = "", group[MAXSIZE] = "", resultString[MAXSIZE * MAXSIZE] = "";
    printf("Введите имя файла:");
    enterCredential(fileName);
    while (fopen(fileName, "r") == NULL)
    {
        printf("Ошибка в имени файла. Повторите попытку:");
        enterCredential(fileName);
    }
    printf("Выберите действие:\n1.Добавить данные студента\n2.Вывести данные всех студентов\n3.Очистить файл\n0.Выход из программы\n");
    do
    {
        scanf("%d", &action);
        fflush(stdin);
        // getchar(); // skip \n
        switch (action)
        {
        case 1: //ввод данных нового студента
        {
            currFile = fopen(fileName, "a");
            printf("Введите фамилию: ");
            do
            {
                enterCredential(surName);
            } while (0 == checkCredential(surName));
            printf("Введите имя: ");
            do
            {
                enterCredential(name);
            } while (0 == checkCredential(name));
            printf("Введите отчество: ");
            do
            {
                enterCredential(middleName);
            } while (0 == checkCredential(middleName));
            printf("Введите номер группы: ");
            enterCredential(group); //в формате М3О-135Б-20 (3 символ - буква)
            while (!isalpha(group[0]) || !isalpha(group[7]) || !isdigit(group[1]) || !isalpha(group[2]) || !isdigit(group[4]) || !isdigit(group[5]) || !isdigit(group[6]) || !isdigit(group[9]) || !isdigit(group[10]))
            {
                printf("Ошибка ввода. Повторите попытку.");
                clearArray(group);
                enterCredential(group);
            }

            strcat(resultString, "Студент "); //объединяем строки с ФИО и номером группы в одну
            strcat(resultString, surName);
            strcat(resultString, name);
            strcat(resultString, middleName);
            strcat(resultString, group);

            fprintf(currFile, "%s\n", resultString); //записываем готовую строку в файл
            fclose(currFile);
            strcat(resultString, "записан в файл.");
            printArray(resultString);

            clearArray(surName); //очищаем строки после использования
            clearArray(name);
            clearArray(middleName);
            clearArray(group);
            clearArray(resultString);
            break;
        }
        case 2: //вывод данных студентов из файла
        {
            printf("Содержимое файла %s:\n", fileName);
            currFile = fopen(fileName, "r");
            char tempString[MAXSIZE];
            if (currFile == NULL)
            {
                printf("Ошибка открытия файла.\n");
            }
            else
            {
                while (!feof(currFile))
                {
                    fgets(tempString, MAXSIZE, currFile);
                    if (!feof(currFile))
                    {
                        printArray(tempString);
                    }
                }
                fclose(currFile);
            }
            break;
        }
        case 3: //очистка файла
        {
            currFile = fopen(fileName, "w");
            fclose(currFile);
            printf("Файл успешно очищен.\n");
            break;
        }
        case 0:
        {
            printf("Выход из программы.\n");
            return 0;
        }
        default:
        {
            printf("Ошибка. Повторите попытку");
            break;
        }
        }
    } while (action != 0);
    return 0;
}
