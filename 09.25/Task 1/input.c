#define MAX_SIZE 256
void enterNumbers(int minValue, int maxValue, int numberOfElements, int destination[MAX_SIZE], char welcomeMessage[MAX_SIZE])
{
#ifdef DEBUG
    printf("    Entered enterNumber function with such arguments:\n    minValue = %d, maxValue = %d, numberOfElements = %d, welcomeMessage = %s\n", minValue, maxValue, numberOfElements, welcomeMessage);
#endif
    int enteredValue;
    if (strlen(welcomeMessage) > 0)
    {
        printf("%s It must be bigger than %d and less than %d: ", welcomeMessage, minValue, maxValue);
    }
    do
    {
        if (numberOfElements - 1) //если 1 элемент - идём в режим ввода 1 числа, иначе - в режим ввода массива
        {
#ifdef DEBUG
            printf("Multi number mode.\n");
#endif
            for (int i = 0; i < numberOfElements; i++)
            {
                do
                {
                    printf("Enter %d element: ", i+1);
                    scanf("%d", &enteredValue);
#ifdef DEBUG
                    printf("    You entered %d.\n", enteredValue);
#endif
                    if (enteredValue >= minValue && enteredValue <= maxValue)
                    {
                        destination[i] = enteredValue;
                        break;
                    }
                    else
                    {
                        printf("You entered wrong value. It must be bigger than %d and less than %d. Try again.\n", minValue, maxValue);
                    }
                } while (1);
            }
            break;
        }
        else
        {
#ifdef DEBUG
            printf("Single number mode.\n");
#endif
            scanf("%d", &enteredValue);
            if (enteredValue >= minValue && enteredValue <= maxValue)
            {
                destination[0] = enteredValue;
                break;
            }
            else
            {
                printf("You entered wrong value. It must be bigger than %d and less than %d. Try again.\n", minValue, maxValue);
            }
#ifdef DEBUG
            printf("    You entered %d.\n", enteredValue);
#endif
        }
    } while (1);
#ifdef DEBUG
    printf("    Function enterNumber was completed.\n\n");
#endif
}