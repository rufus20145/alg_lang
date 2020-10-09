void sortArray(int *array, int size, int sortingType, int *extCompare, int *extSwapNumber)
{
    int swapCheck, compare = 0, swapNumber = 0;
#ifdef DEBUG
    printf("    Entered sortArray function with such arguments:\n    array pointer, size = %d, sortingType = %d, extCompare and extSwapNumber pointers.\n", size, sortingType);
#endif
    switch (sortingType)
    {
    case 1: //stupid sort
        do
        {
#ifdef DEBUG
            printf("Entered 1 case: stupid sorting\n\n");
#endif
            swapCheck = 0;
            for (int i = 0; i < size - 1;)
            {
                compare++;
#ifdef DEBUG
                printf("Before if i = %d\n", i);
#endif
                if (array[i] > array[i + 1])
                {
                    swapNumbers(array[i], array[i + 1], &array[i], &array[i + 1]);
                    // #ifdef DEBUG
                    //                     printf("Changed elements %d and %d\n", i, i + 1);
                    // #endif
                    swapCheck++;
                    i = 0;
                }
                else i++;
#ifdef DEBUG
                printf("After if i = %d\n", i);
#endif
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

        break;
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