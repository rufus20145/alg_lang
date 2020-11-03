/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief Программа принимает на вход анкетные данные(ФИО, номер группы, номер факультета), а затем выводит их
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
    printf("\n");
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
        array[i] = '0';
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
            printf("%c не является буквой ", array[i]);
            printf("Error. Try again. ");
            clearArray(array);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
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
            printf("%c не является буквой ", array[i]);
            printf("Error. Try again. ");
            clearArray(array);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}

/**
 * @brief основная функция
 * 
 * @return int код ошибки в систему
 */
int main()
{
    printf("%d\n", GetConsoleCP());
    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }
    printf("%d\n", GetConsoleCP());

    char surName[MAXSIZE] = "", name[MAXSIZE] = "", middleName[MAXSIZE] = "", group[MAXSIZE] = "", resultString[MAXSIZE * MAXSIZE] = "";
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
    do
    {
        enterGroup(group);
    } while (0 == checkGroup(group));

    strcat(resultString, "Студент ");
    strcat(resultString, surName);
    strcat(resultString, name);
    strcat(resultString, middleName);
    strcat(resultString, group);
    return 0;
}
