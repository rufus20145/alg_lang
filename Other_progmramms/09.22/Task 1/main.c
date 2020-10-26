#include <stdio.h>
#define MAX_SIZE 256

int main() {
    int array[MAX_SIZE], temp = 0, size = 0;
    long sum = 0;
    printf("Enter array size from 5 to 15: ");
    do
    {
        scanf("%d", &temp);
        if (temp >= 5 && temp <= 15) {
            size = temp;
            temp = 0;
            break;
        } else {
            if(temp > 0) {
                if(temp < 5) printf("Array size is too small. Try again.\n");
                else printf("Array size is too big. Try again.\n");
            }
            else printf("Array size can`t be less than 1. Try again.\n");
            continue;
        }
    } while (1);
    printf("Now enter the array. Elements must be bigger than 0 and less than 100.\n");
    for(int i = 0; i < size; i++) {
        do {
            scanf("%d", &temp);
            if(temp > 0 && temp < 100) {
                array[i] = temp;
                temp = 0;
                break;
            } else {
                printf("Try again.\n");
                continue;
            }
        } while(1);
        sum += array[i];
    }
    printf("\n");
    printf("Array is: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Array sum is %ld.\n", sum);
    return 0;
}