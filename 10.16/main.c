#include <stdio.h>
#include "operations.c"
#include "input.c"
#include "numSwapper.c"
#include "transposer.c"
#define MAX_SIZE 256

int main()
{
    int errorCode = 0;
    int operation;
    int matrixSize, matrix1Length, matrix1Height, matrix2Length, matrix2Height, resultMatrixHeight, resultMatrixLength;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];

    enterNumbers(1, 256, 1, &matrix1Height, "Enter first matrix height.");
    enterNumbers(1, 256, 1, &matrix1Length, "Enter first matrix lenth.");
    for (int i = 0; i < matrix1Length; i++)
    {
        for (int j = 0; j < matrix1Height; j++)
        {
            printf("element[%d][%d] = ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    enterNumbers(1, 256, 1, &matrix2Height, "Enter second matrix height.");
    enterNumbers(1, 256, 1, &matrix2Length, "Enter second matrix lenth.");
    for (int i = 0; i < matrix2Length; i++)
    {
        for (int j = 0; j < matrix2Height; j++)
        {
            printf("element[%d][%d] = ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("Choose operation\n");
    scanf("%d", &operation);

    printf("First matrix was:\n");
    for (int i = 0; i < matrix1Length; i++)
    {
        for (int j = 0; j < matrix2Height; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Second matrix was:\n");
    for (int i = 0; i < matrix2Length; i++)
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
        errorCode = sumMatrix((int **)matrix1, (int **)matrix2, (int **)resultMatrix, matrix1Length, matrix1Height, matrix2Length, matrix2Height, &resultMatrixHeight, &resultMatrixLength);
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
