void sortArray(int *array, int size, int sortingType, int *extCompare, int *extSwapNumber)
{
    int swapCheck, compare = 0, swapNumber = 0;
#ifdef DEBUG
    printf("    Entered sortArray function with such arguments:\n    array pointer, size = %d, sortingType = %d, extCompare and extSwapNumber pointers.\n", size, sortingType);
#endif
    switch (sortingType)
    {
    case 1: //stupid sort
#ifdef DEBUG
        printf("Entered 1 case: stupid sorting\n\n");
#endif
        do
        {

            swapCheck = 0;
            for (int i = 0; i < size - 1;)
            {
                compare++;
                if (array[i] > array[i + 1])
                {
                    swapNumbers(array[i], array[i + 1], &array[i], &array[i + 1]);
#ifdef DEBUG
                    printf("Changed elements %d and %d\n", i, i + 1);
#endif
                    swapCheck++;
                    i = 0;
                }
                else
                    i++;
                // #ifdef DEBUG
                //                 printf("Check is %d.\nNow array is:", swapCheck);
                //                 for (int i = 0; i < size; i++)
                //                     printf("%d ", array[i]);
                //                 printf("\n\n");
                // #endif
                continue;
            }
            swapNumber += swapCheck;
        } while (swapCheck > 0);
#ifdef DEBUG
        printf("End of silly sorting.\n");
#endif
        break;
    case 2: //поиск минимума
    {
#ifdef DEBUG
        printf("Entered case 2: minmax sort.\n");
#endif
        int minElementIndex = 0;
        do
        {
            swapCheck = 0;
            compare++;
            for (int i = 0; i < size; i++)
            {
                printf("Compare elements %d and %d, they are %d and %d.\n", i, minElementIndex, array[i], array[minElementIndex]);
                if (array[i] > array[minElementIndex])
                {
                    printf("Changed elements %d and %d", i, minElementIndex);
                    swapNumbers(array[i], array[minElementIndex], &array[i], &array[minElementIndex]);
                    minElementIndex = i;
                    swapCheck++;
                }
            }
        } while (swapCheck > 0);
        break;
    }
    case 3: //bubble sort
#ifdef DEBUG
        printf("Entered 3 case: bubble sort.\n");
#endif
        do
        {
            swapCheck = 0;
            for (int i = 0; i < size - 1; i++)
            {
                compare++;
                if (array[i] > array[i + 1])
                {
                    swapNumbers(array[i], array[i + 1], &array[i], &array[i + 1]);
#ifdef DEBUG
                    printf("Changed elements %d and %d\n", i, i + 1);
#endif
                    swapCheck++;
                }
#ifdef DEBUG
                printf("Check is %d.\nNow array is:", swapCheck);
                for (int i = 0; i < size; i++)
                    printf("%d ", array[i]);
                printf("\n\n");
#endif
            }
            swapNumber += swapCheck;
        } while (swapCheck > 0);
        break;
        //     case -1:
        // #ifdef DEBUG
        //         printf("Entered comparing mode\n");
        // #endif
        //         sortArray(array, size, 1, extCompare, extSwapNumber);
        //         sortArray(array, size, 2, extCompare, extSwapNumber);
        //         sortArray(array, size, 3, extCompare, extSwapNumber);
    default:
        break;
    }
#ifdef DEBUG
    printf("Number of compares:%d\nNumber of swaps:%d\n", compare, swapNumber);
#endif
    *extCompare = compare;
    *extSwapNumber = swapNumber;
#ifdef DEBUG
    printf("Function sortArray was completed.\n\n");
#endif
}