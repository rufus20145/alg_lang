#define MAX_SIZE 256

/*
функция ввода
*/
void enterNumbers(int minValue, int maxValue, int numberOfElements, int destination[MAX_SIZE], char welcomeMessage[MAX_SIZE])
{
#ifdef DEBUG
    printf("    Entered enterNumber function with such arguments:\n    minValue = %d, maxValue = %d, numberOfElements = %d, welcomeMessage = %s\n", minValue, maxValue, numberOfElements, welcomeMessage);
    if (numberOfElements == 1)
    {
        printf("    Single number mode.\n");
    }
    else
    {
        printf("    Multi number mode.\n");
    }
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
            for (int i = 0; i < numberOfElements; i++)
            {
                do
                {
                    printf("Enter %d element: ", i + 1);
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
            scanf("%d", &enteredValue);
#ifdef DEBUG
            printf("    You entered %d.\n", enteredValue);
#endif
            if (enteredValue >= minValue && enteredValue <= maxValue)
            {
                destination[0] = enteredValue;
                break;
            }
            else
            {
                printf("You entered wrong value. It must be bigger than %d and less than %d. Try again.\n", minValue, maxValue);
            }
        }
    } while (1);
#ifdef DEBUG
    printf("    Function enterNumber was completed.\n");
    if (numberOfElements == 1)
        printf("    Number is %d\n\n", *destination);
#endif
}