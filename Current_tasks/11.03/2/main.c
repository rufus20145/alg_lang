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
#define MAXSIZE 256
/**
 * @brief функция вывода массива символов
 * 
 * @param array массив для вывода
 */
void printArray(char *array)
{
    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%c", array[i]);
    }
    if (array[arraySize - 1] != '\n')
    {
        printf("\n");
    }
}
/**
 * @brief функция для очистки массива
 * 
 * @param array - массив для очистки
 */
void clearArray(char *array)
{
    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '\0';
    }
}

/**
 * @brief фугкция ввода номера группы
 * 
 * @param array массив куда класть введенные данные
 */
void enterGroup(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
            array[i] = ' ';
            break;
        }
        else
        {
            array[i] = buffer;
        }
    }
}

/**
 * @brief функция ввода ФИО
 * 
 * @param array массив, куда класть введенные данные
 * @return void
 */
void enterCredential(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
            array[i] = ' ';
            break;
        }
        else
        {
            array[i] = buffer;
        }
    }
}
/**
 * @brief функция проверки номера группы
 * 
 * @param array массив с номером группы для проверки
 * @return int результат проверки
 */
int checkGroup(char *array)
{
    int arraySize = strlen(array);
    arraySize--; // при вводе мы добавляем пробел в конеци его не надо проверять на букву
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha(array[i]))
        {
            printf("Ошибка ввода. Повторите попытку. ");
            clearArray(array);
            return 0;
        }
    }
    return 1;
}

/**
 * @brief функция проверки ФИО
 * 
 * @param array массив для проверки
 * @return int результат проверки
 */
int checkCredential(char *array)
{
    int arraySize = strlen(array);
    arraySize--; // при вводе мы добавляем пробел в конеци его не надо проверять на букву
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha(array[i]))
        {
            // printf("%c не является буквой ", array[i]);
            printf("Ошибка ввода. Повторите попытку. ");
            clearArray(array);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    // printf("%d\n", GetConsoleCP());
    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }
    // printf("%d\n", GetConsoleCP());

    FILE *currFile;
    int action;
    char surName[MAXSIZE] = "", name[MAXSIZE] = "", middleName[MAXSIZE] = "", group[MAXSIZE] = "", resultString[MAXSIZE * MAXSIZE] = "";

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
            currFile = fopen(argv[1], "a");
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
            printf("Введите номер группы:");
            enterGroup(group); //М3О-135Б-20
            while (!isalpha(group[0]) || !isalpha(group[7]) || !isdigit(group[1]) || !isalpha(group[2]) || !isdigit(group[4]) || !isdigit(group[5]) || !isdigit(group[6]) || !isdigit(group[9]) || !isdigit(group[10]))
            {
                clearArray(group);
                enterGroup(group);
            }

            strcat(resultString, "Студент ");
            strcat(resultString, surName);
            strcat(resultString, name);
            strcat(resultString, middleName);
            strcat(resultString, group);
            fprintf(currFile, "%s\n", resultString);
            fclose(currFile);
            strcat(resultString, "записан в файл.");
            printArray(resultString);
            clearArray(surName);
            clearArray(name);
            clearArray(middleName);
            clearArray(group);
            clearArray(resultString);
            break;
        }
        case 2: //вывод данных студентов из файла
        {
            printf("Содержимое файла %s:\n", argv[1]);
            currFile = fopen(argv[1], "r");
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
            currFile = fopen(argv[1], "w");
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
