/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief 8 практическая работа - сортировка двумерного массива с использованием указателей для обмена элементов 
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "input.c"
#include "numSwapper.c"

// с помощью одного из двух define в слеюущих строках выберите тип ввода (по умолчанию с клавиатуры)
// #define INPUT_FROM_KEYBOARD
#define INPUT_FROM_FILE

#define INPUT_BUFFER_SIZE 256
#define MATRIX_SIZE 32
#define MAX_SIZE 256

int main()
{
    // переменные, необходимые при вводе из файла
#ifdef INPUT_FROM_FILE
    FILE *currFile;
    char inputBuffer[INPUT_BUFFER_SIZE] = "", fileName[INPUT_BUFFER_SIZE] = "";
#endif // INPUT_FROM_FILE

#ifdef INPUT_FROM_KEYBOARD
int inputErrorCode = 0;
#endif // INPUT_FROM_KEYBOARD

    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int plainArray[MATRIX_SIZE * MATRIX_SIZE];
    int matrixHeight = 0, matrixWidth = 0, plainSize = 0, minElementIndex = 0;

    system("cls"); //очищаем консоль перед стартом программы

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

#ifdef INPUT_FROM_FILE
    //ввод массива из файла
    printf("Введите название файла: ");
    fgets(fileName, INPUT_BUFFER_SIZE, stdin);
    fileName[strlen(fileName) - 1] = '\0';
    currFile = fopen(fileName, "r");
    matrixHeight = -1;
    while (!feof(currFile))
    {
        fgets(inputBuffer, INPUT_BUFFER_SIZE, currFile);
        inputBuffer[strlen(inputBuffer) - 1] = '\0';
        if (!feof(currFile))
        {

            char *separatedBuffer = "";
            separatedBuffer = strtok(inputBuffer, " ");
            if (NULL != separatedBuffer)
                matrixWidth = 0;
            while (NULL != separatedBuffer)
            {
                matrix[matrixHeight + 1][matrixWidth] = atoi(separatedBuffer);
                matrixWidth++;
                separatedBuffer = strtok(NULL, " ");
            }

            matrixWidth = matrixWidth;
        }
        matrixHeight++;
    }
    fclose(currFile);
#endif //INPUT_FROM_FILE

#ifdef INPUT_FROM_KEYBOARD
    // ввод размеров матрицы
    printf("Введите высоту матрицы ");
    do
    {
        inputErrorCode = enterNumber(&matrixHeight);
        if (matrixHeight < 1 || matrixHeight > 32)
        {
            printf("Высота матрицы не может быть меньше 1 или больше 32, повторите попытку ");
            inputErrorCode = 1;
        }
    } while (1 == inputErrorCode);
    printf("Введите ширину матрицы ");
    do
    {
        inputErrorCode = enterNumber(&matrixWidth);
        if (matrixWidth < 1 || matrixWidth > 32)
        {
            printf("Ширина матрицы не может быть меньше 1 или больше 32, повторите попытку ");
            inputErrorCode = 1;
        }
    } while (1 == inputErrorCode);

    //ввод значений элементов
    for (int i = 0; i < matrixHeight; i++)
    {
        for (int j = 0; j < matrixWidth; j++)
        {
            do
            {
                printf("matrix[%d][%d] = ", i + 1, j + 1);
                inputErrorCode = enterNumber(&matrix[i][j]);
            } while (1 == inputErrorCode);
        }
    }
    printf("\n");

#endif // INPUT_FROM_KEYBOARD

    //преобразуем двумерный массив в одномерный
    plainSize = matrixHeight * matrixWidth;
    for (int i = 0; i < matrixHeight; i++)
    {
        for (int j = 0; j < matrixWidth; j++)
        {
            plainArray[i * matrixWidth + j] = matrix[i][j];
        }
    }

    //начинаем сортировку массива
    for (int i = 0; i < plainSize - 1; i++)
    {
        minElementIndex = i;
        for (int j = i; j < plainSize; j++)
        {
            if (plainArray[j] < plainArray[minElementIndex])
                minElementIndex = j;
        }
        swapNumbers(&plainArray[minElementIndex], &plainArray[i]);
    }

    //преобразуем одномерный массив обратно в двумерный
    for (int i = 0; i < matrixHeight; i++)
    {
        for (int j = 0; j < matrixWidth; j++)
        {
            matrix[i][j] = plainArray[i * matrixWidth + j];
        }
    }

    //вывод итоговой матрицы
    printf("Отсортированная матрица:\n");
    for (int i = 0; i < matrixHeight; i++)
    {
        for (int j = 0; j < matrixWidth; j++)
        {
            printf("matrix[%d][%d]\t= %d\n", i + 1, j + 1, matrix[i][j]);
        }
    }
    printf("А теперь в матричном виде:\n");
    for (int i = 0; i < matrixHeight; i++)
    {
        for (int j = 0; j < matrixWidth; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}