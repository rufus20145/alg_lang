#include <stdio.h>
#include <string.h>
#include "operations.c"
#include "input.c"
#include "numSwapper.c"
#include "transposer.c"
#define MAX_SIZE 256

int main()
{
    int errorCode = 0;
    int operation;
    int matrixSize, matrix1Width, matrix1Height, matrix2Width, matrix2Height, resultMatrixHeight, resultMatrixWidth;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];

    printf("Choose operation\n");//выбор операции
    scanf("%d", &operation);

    enterNumbers(1, 256, 1, &matrix1Height, "Enter first matrix height.");
    enterNumbers(1, 256, 1, &matrix1Width, "Enter first matrix width.");
    for (int i = 0; i < matrix1Width; i++)
    {
        // for (int j = 0; j < matrix1Height; j++)
        // {
        //     printf("element[%d][%d] = ", i, j);
        //     scanf("%d", &matrix1[i][j]);
        // }
        enterNumbers(-1000, 1000, matrix1Height, matrix1[i], "Enter matrix elements");
    }

    enterNumbers(1, 256, 1, &matrix2Height, "Enter second matrix height.");
    enterNumbers(1, 256, 1, &matrix2Width, "Enter second matrix width.");
    for (int i = 0; i < matrix2Width; i++)
    {
        for (int j = 0; j < matrix2Height; j++)
        {
            printf("element[%d][%d] = ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("First matrix was:\n"); // вывод оригинальных матриц
    for (int i = 0; i < matrix1Width; i++)
    {
        for (int j = 0; j < matrix2Height; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Second matrix was:\n");
    for (int i = 0; i < matrix2Width; i++)
    {
        for (int j = 0; j < matrix2Height; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }



    switch (operation)
    {
    case '1':
        errorCode = sumMatrix((int **)matrix1, (int **)matrix2, (int **)resultMatrix, matrix1Width, matrix1Height, matrix2Width, matrix2Height, &resultMatrixHeight, &resultMatrixWidth);
        break;
    // case '*':
    //     // multiplyMatrix((int **)matrix1, (int **)matrix2, (int **)resultMatrix, matrixSize);
    //     break;
    // case 'T':
    //     break;
    default:
        printf("Error was encountered during parsing operation.\n");
        break;
    }
    if (0 == errorCode)
    {
        printf("Result matrix is:\n");
        for (int i = 0; i < resultMatrixHeight; i++)
        {
            for (int j = 0; j < resultMatrixHeight; j++)
            {
                printf("%d ", resultMatrix[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Programm encountered an erorr.\n");
    }
    return 0;
}
