#include <stdio.h>
#include <string.h>
#include "numSwapper.c"
#include "input.c"
#include "transposer.c"
#define MAXSIZE 256

int main()
{
    int matrix[MAXSIZE][MAXSIZE];
    int matrixHeight, matrixLenth;
    int minElementRaw = 0, minElementColumn = 0, maxElementRaw = 0, maxElementColumn = 0;
    enterNumbers(1, 256, 1, &matrixHeight, "Enter matrix height.");
    enterNumbers(1, 256, 1, &matrixLenth, "Enter matrix lenth.");
    for (int i = 0; i < matrixLenth; i++)
    {
        for (int j = 0; j < matrixHeight; j++)
        {
            printf("element[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] > matrix[maxElementRaw][maxElementColumn])
            {
                maxElementRaw = i;
                maxElementColumn = j;
            }
            if (matrix[i][j] < matrix[minElementRaw][minElementColumn])
            {
                minElementRaw = i;
                minElementColumn = j;
            }
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

    transposeMatrix((int **)matrix, matrixHeight, matrixLenth);

    printf("After transpose matrix is:\n");
    for (int i = 0; i < matrixHeight; i++)
    {
        for (int j = 0; j < matrixLenth; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Minimum elemnt is [%d][%d] which is %d.\n", minElementRaw + 1, minElementColumn + 1, matrix[minElementColumn][minElementRaw]);
    printf("Maximum elemnt is [%d][%d] which is %d.\n", maxElementRaw + 1, maxElementColumn + 1, matrix[maxElementColumn][maxElementRaw]);
    printf("End of program.\n");
    return 0;
}