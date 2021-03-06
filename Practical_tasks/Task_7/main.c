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
#define MATRIX_SIZE 500
#define BUFFER_SIZE 2500
typedef struct
{
    int array[MATRIX_SIZE][MATRIX_SIZE];
    int height, width;
    int maxElementRaw, maxElementColumn, minElementRaw, minElementColumn, firstSum, secondSum;
} matrixes;

void printMatrix(matrixes matrix)
{
    for (int i = 0; i < matrix.height; i++)
    {
        for (int j = 0; j < matrix.width; j++)
        {
            printf("%d\t", matrix.array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    if (GetConsoleCP() != 65001)
    {
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);
        printf("ConsoleCP was changed.\n");
    }
    setlocale(LC_ALL, "RUSSIAN");
    // _wsetlocale(LC_ALL, (wchar_t *)"RUSSIAN");
    matrixes matrix;
    wchar_t fileName[MAXSIZE];
    char buffer[BUFFER_SIZE] = "";
    FILE *currFile = NULL;
    int inputErrorCode = 0, errorCode = 0, flag = 0, matrixWidth = 0;

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
        else
        {
            printf("Матрица обнаружена. Начинаю запись в структуру.\n");
        }
    } while (1 == errorCode);

    fflush(stdin);
    currFile = fopen((char *)fileName, "r");

    matrix.width = 0;
    matrix.height = -1;

    while (!feof(currFile))
    {
        if (0 == flag)
        {
            fgets(buffer, BUFFER_SIZE, currFile);
            flag = 1;
        }
        fgets(buffer, BUFFER_SIZE, currFile);
        buffer[strlen(buffer) - 1] = '\0';
        if (!feof(currFile))
        {
            char *separatedBuffer = "";
            separatedBuffer = strtok(buffer, ";");
            while (NULL != separatedBuffer)
            {
                matrix.array[matrix.height + 1][matrixWidth] = atoi(separatedBuffer);
                matrixWidth++;
                separatedBuffer = strtok(NULL, ";");
            }

            matrix.width = matrixWidth;
            matrixWidth = 0;
        }
        matrix.height++;
    }

    //поиск минимального и максимального элементов, а также суммы четных и нечетных
    matrix.minElementRaw = matrix.minElementColumn = 0;
    matrix.maxElementRaw = matrix.maxElementColumn = 0;
    matrix.firstSum = matrix.secondSum = 0;

    for (int i = 0; i < matrix.height; i++)
    {
        for (int j = 0; j < matrix.width; j++)
        {
            if (matrix.array[i][j] > matrix.array[matrix.maxElementRaw][matrix.maxElementColumn])
            {
                matrix.maxElementRaw = i;
                matrix.maxElementColumn = j;
            }
            if (matrix.array[i][j] < matrix.array[matrix.minElementRaw][matrix.minElementColumn])
            {
                matrix.minElementRaw = i;
                matrix.minElementColumn = j;
            }
            if ((matrix.array[i][j] % 2) == 0)
            {
                matrix.firstSum += matrix.array[i][j];
            }
            else
            {
                matrix.secondSum += matrix.array[i][j];
            }
        }
    }
    printf("\nПрочитана следующая матрица:\n");
    printMatrix(matrix);
    printf("Ширина: %d\n", matrix.width);
    printf("Высота: %d\n", matrix.height);
    printf("Минимальный элемент [%d][%d] = %d, максимальный элемент [%d][%d] = %d\n", matrix.minElementRaw + 1, matrix.minElementColumn + 1, matrix.array[matrix.minElementRaw][matrix.minElementColumn], matrix.maxElementRaw + 1, matrix.maxElementColumn + 1, matrix.array[matrix.maxElementRaw][matrix.maxElementColumn]);
    printf("Сумма четных элементов: %d, сумма нечетных: %d\n", matrix.firstSum, matrix.secondSum);
    fclose(currFile);
    printf("Конец.\n");
    return 0;
}
