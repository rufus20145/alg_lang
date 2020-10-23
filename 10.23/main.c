#include <stdio.h>
#include <string.h>
#include "input.c"
#include "numSwapper.c"

#define MAX_SIZE 256

int main()
{
    int array[MAX_SIZE][MAX_SIZE];
    int arrayHeight, arrayWidth, numberOfElements, minElementRaw = 0, minElementColumn = 0, maxElementRaw = 0, maxElementColumn = 0, buffer;
    enterNumbers(1, 256, 1, &arrayHeight, "Enter array height.");
    enterNumbers(1, 256, 1, &arrayWidth, "Enter array width.");
    for (int i = 0; i < arrayHeight; i++)
    {
        for (int j = 0; j < arrayWidth; j++)
        {
            printf("array[%d][%d] = ", i + 1, j + 1);
            enterNumbers(-10000, 10000, 1, &array[i][j], "");
        }
    }
    printf("Array size is %d * %d\n", arrayHeight, arrayWidth);
    printf("\nStarting array sort.\n");

    numberOfElements = arrayHeight * arrayWidth;
    for (int startElement = 0; startElement < numberOfElements; startElement++)
    {
        printf("Start element is %d\n", startElement);
        for (int currentRaw = 0; currentRaw < arrayHeight; currentRaw++)
        {
            for (int currentColumn = 0; currentColumn < arrayWidth; currentColumn++)
            {
                // if (array[currentRaw][currentColumn] > array[maxElementRaw][maxElementColumn])
                // {
                //     maxElementRaw = currentRaw;
                //     maxElementColumn = currentColumn;
                // }
                if (array[currentRaw][currentColumn] < array[minElementRaw][minElementColumn])
                {
                    minElementRaw = currentRaw;
                    minElementColumn = currentColumn;
                }
                printf("Current min element is %d, minElementRaw = %d, minminElementColumn = %d\n\n", array[minElementRaw][minElementColumn], minElementRaw, minElementColumn);
            }
        }
        // printf("Current max element is %d, maxElementRaw = %d, maxElementColumn = %d\n", array[maxElementRaw][maxElementColumn], maxElementRaw + 1, maxElementColumn + 1)
        printf("Started exchange.\n");
        buffer = array[minElementRaw][minElementColumn];
        array[minElementRaw][minElementColumn] = array[startElement / arrayWidth][startElement % arrayWidth];
        array[startElement / arrayWidth][startElement % arrayWidth] = buffer;
        printf("Exchange done.Now array is:\n");
        for (int i = 0; i < arrayHeight; i++)
        {
            for (int j = 0; j < arrayWidth; j++)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("Done sort. Array size is %d * %d. Result array is:\n", arrayHeight, arrayWidth);
    for (int i = 0; i < arrayHeight; i++)
    {
        for (int j = 0; j < arrayWidth; j++)
        {
            printf("element[%d][%d] = %d\n", i, j, array[i][j]);
        }
    }

    return 0;
}