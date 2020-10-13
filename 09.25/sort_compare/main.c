#include <stdio.h>
#include <string.h>
#include "numSwapper.c"
#include "input.c"
#include "sorter.c"
#define MAX_SIZE 256

int main()
{
#ifdef DEBUG
    printf("This is DEBUG version of the program.\n\n");
#endif
    int array[MAX_SIZE], size = 0, swapNumber = 0, compare = 0, sortingType = 0;
    int minValue = 5, maxValue = 15, minArrayValue = 0, maxArrayValue = 100;
    printf("Choose type of sorting:\n1.Standart\n2.Minimax\n3.Bubble\n");
    scanf("%d", &sortingType);
    enterNumbers(minValue, maxValue, 1, &size, "Enter array size.");//ввод размера массива
    printf("Now enter the array values. They must be bigger than %d and less than %d.\n", minArrayValue, maxArrayValue);
    enterNumbers(minArrayValue, maxArrayValue, size, array, "");//ввода массива
    // printf("Array was:       ");
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    printf("\n");//here sort array
    sortArray(array, size, sortingType, &compare, &swapNumber);
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
