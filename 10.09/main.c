#include <stdio.h>
#include <string.h>
#include "numSwapper.c"
#include "input.c"
#define MAXSIZE 256

int main()
{
    int matrix[MAXSIZE][MAXSIZE];
    int matrixHeight, matrixLenth, tempSize;
    enterNumbers(1, 256, 1, &matrixHeight, "Enter matrix height.");
    enterNumbers(1, 256, 1, &matrixLenth, "Enter matrix lenth.");
    for (int i = 0; i < matrixLenth; i++)
    {
        for (int j = 0; j < matrixHeight; j++)
        {
            printf("element[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix was:\n");
    for (int i = 0; i < matrixLenth; i++)
    {
        for (int j = 0; j < matrixHeight; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (matrixHeight > matrixLenth)
        tempSize = matrixHeight;
    else
        tempSize = matrixLenth;
    for (int i = 0; i < tempSize - 1; i++)//идём по строкам
    {
        for (int j = i + 1; j < tempSize; j++)//идём по столбцам
        {
            swapNumbers(matrix[i][j], matrix[j][i], &matrix[i][j], &matrix[j][i]);
        }
    }

    printf("After transpose matrix is:\n");
    for (int i = 0; i < matrixHeight; i++)
    {
        for (int j = 0; j < matrixLenth; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("End of program.\n");
    return 0;
}