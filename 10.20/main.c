#include <stdio.h>
#include <string.h>
#include "input.c"
#define MAX_SIZE 256

int main()
{
    int array[MAX_SIZE][MAX_SIZE];
    int arrayHeight, arrayWidth;
    int maxElementRaw = 0, maxElementColumn = 0, minElementRaw = 0, minElementColumn = 0, sum;
    enterNumbers(1, 256, 1, &arrayHeight, "Enter array height.");
    enterNumbers(1, 256, 1, &arrayWidth, "Enter array width.");
    for (int i = 0; i < arrayWidth; i++)
    {
        for (int j = 0; j < arrayHeight; j++)
        {
            printf("element[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
            if (array[i][j] > array[maxElementRaw][maxElementColumn])
            {
                maxElementRaw = i;
                maxElementColumn = j;
            }
            if (array[i][j] < array[minElementRaw][minElementColumn])
            {

                minElementRaw = i;
                minElementColumn = j;
            }
            sum += array[i][j];
        }
    }
    printf("Min element is %d\n", array[minElementRaw][minElementColumn]);
    printf("Max element is %d\n", array[maxElementRaw][maxElementColumn]);
    printf("Sum is %d\n", sum);
    return 0;
}