#include <stdio.h>
#include <string.h>
#include "numSwapper.c"
#include "input.c"
#define MAX_SIZE 256

int main()
{
#ifdef DEBUG
    printf("This is DEBUG version of the program.\n\n");
#endif
    int array[MAX_SIZE], size = 0, check = 0, swapNumber = 0, compare = 0;
    int minValue = 5, maxValue = 15, minArrayValue = 0, maxArrayValue = 100;
    enterNumbers(minValue, maxValue, 1, &size, "Enter array size.");
    printf("Now enter the array values. They must be bigger than %d and less than %d.\n", minArrayValue, maxArrayValue);
    enterNumbers(minArrayValue, maxArrayValue, size, array, "");
    printf("Array was:       ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    //sorting the array - сортировка пузырьком
    do
    {
        check = 0;
        for (int i = 0; i < size - 1; i++)
        {
            compare++;
            if (array[i] > array[i + 1])
            {
                swapNumbers(array[i], array[i + 1], &array[i], &array[i + 1]);
                check++;
            }
        }
        swapNumber += check;
    } while (check > 0);
    printf("Sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    if (1 == swapNumber)
        printf("%d swap was made.\n", swapNumber);
    else
        printf("%d swaps were made.\n", swapNumber);
    if (1 == compare)
        printf("%d compare was made.\n", compare);
    else
        printf("%d compares were made.\n", compare);
    return 0;
}
