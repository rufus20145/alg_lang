#include <stdio.h>
#define MAX_SIZE 256

int main()
{
    int array[MAX_SIZE], temp = 0, size = 0, check = 0, swapNumber = 0, compare = 0;
    long sum = 0;
    printf("Enter array size from 5 to 15: ");
    do
    {
        scanf("%d", &temp);
        if (temp >= 5 && temp <= 15)
        {
            size = temp;
            temp = 0;
            break;
        }
        else
        {
            if (temp > 0)
            {
                if (temp < 5)
                    printf("Array size is too small. Try again.\n");
                else
                    printf("Array size is too big. Try again.\n");
            }
            else
                printf("Array size can`t be less than 1. Try again.\n");
            continue;
        }
    } while (1);
    printf("Now enter the array. Elements must be bigger than 0 and less than 100.\n");
    for (int i = 0; i < size; i++)
    {
        do
        {
            scanf("%d", &temp);
            if (temp > 0 && temp < 100)
            {
                array[i] = temp;
                temp = 0;
                break;
            }
            else
            {
                printf("Try again.\n");
                continue;
            }
        } while (1);
        sum += array[i];
    }
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
                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
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


