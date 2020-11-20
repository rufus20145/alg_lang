/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief задание на работу с матрицей с помощью структуры
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAXSIZE 256

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#include "input.c"
#include "output.c"
#include "functions.c"

#define MAXSIZE 256

int checkFile(char *fileName)
{
    // printf("File 123recieved: %s\n", fileName);
    FILE *currFile = NULL;
    char buffer[MAXSIZE] = "", refString[MAXSIZE] = "matrix";

    currFile = fopen(fileName, "r");
    fgets(buffer, MAXSIZE, currFile);
    if (!strcmp(buffer, refString))
    {
        printf("Матрица найдена.\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
typedef struct
{
    char array[MAXSIZE][MAXSIZE];
    int maxElementRaw, maxElementColumn, firstSum, secondSum;
} matrixes;

int main()
{
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }
    setlocale(LC_ALL, "RUSSIAN");
    matrixes matrix;
    char fileName[MAXSIZE] = "";
    FILE *currFile = NULL;
    int inputErrorCode = 0, errorCode = 0;

    do //ввод имени файла
    {
        inputErrorCode = chooseFile(fileName);
    } while (1 == inputErrorCode);

    printf("Переход к парсингу\n");
    do
    {
        errorCode = checkFile(fileName);
        if (1 == errorCode)
        {
            printf("В данном файле нет матрицы. Выберите другой файл.\n");
            do //ввод имени файла
            {
                inputErrorCode = chooseFile(fileName);
            } while (1 == inputErrorCode);
        }
    } while (1 == errorCode);
}