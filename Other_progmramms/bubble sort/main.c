#include <stdio.h>
#define MAX_SIZE 256

int main()
{
    int size, buffer, check = 0;
    int array[MAX_SIZE];

    printf("Enter array size: ");
    scanf("%d", &size);

    printf("Now enter array values\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("Array was:");
    for (int i = 0; i < size; i++)
        printf("%d", array[i]);
    printf("\n");

    //now sort
    do
    {
        check = 0;
        for (int i = 0; i < size - 1; i++)
        {
            printf("Iteration %d\n", i + 1);
            if (array[i] > array[i + 1])
            {
                printf("Changed elements %d and %d\n", i, i + 1);
                buffer = array[i];
                array[i] = array[i + 1];
                array[i + 1] = buffer;
                check++;
            }
            printf("Check is %d.\nNow array is:", check);
            for (int i = 0; i < size; i++)
                printf("%d ", array[i]);
            printf("\n\n");
        }
    } while (check > 0);

    printf("Result array is:");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    return 0;
}