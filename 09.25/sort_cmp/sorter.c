#define MAX_SIZE 256
void sortArray(int array[MAX_SIZE], int size, int sortingType, int *extCompare, int *extSwapNumber)
{
    int swapCheck, compare = 0, swapNumber = 0;
    switch (sortingType)
    {
    case 1: //полный перебор
        do
        {
        } while (1);
        break;
    case 2: //поиск минимума

        break;
    case 3: //пузырьком
        do
        {
            swapCheck = 0;
            for (int i = 0; i < size - 1; i++)
            {
                compare++;
                if (array[i] > array[i + 1])
                {
                    swapNumbers(array[i], array[i + 1], &array[i], &array[i + 1]);
                    swapCheck++;
                }
            }
            swapNumber += swapCheck;
        } while (swapCheck > 0);
        break;
    case -1:
        sortArray(array, size, 1, extCompare, extSwapNumber);
        sortArray(array, size, 2, extCompare, extSwapNumber);
        sortArray(array, size, 3, extCompare, extSwapNumber);
    default:
        break;
    }
#ifdef DEBUG
    printf("Number of compares:%d\nNumber of swaps:%d\n", compare, swapNumber);
#endif
    *extCompare = compare;
#ifdef DEBUG
    printf("Pushed compares\n");
#endif
    *extSwapNumber = swapNumber;
#ifdef DEBUG
    printf("Pushed swaps\n");
    printf("End of sortArray\n");
#endif
}