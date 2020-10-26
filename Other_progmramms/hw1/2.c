#include <stdio.h>
// программа выводит введенное число
int main() {
    int number = 0;
    printf("give me a number\n");
    scanf("%d", &number);
    printf("You wrote %d\n", number);
    return 0;
}