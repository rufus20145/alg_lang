#include <stdio.h>

int main() {
    int num1, num2;
    char letter[1];
    printf("Hello!\n");
    do {
        printf("Please enter two numbers:\n");
        scanf("%d %d", &num1, &num2);
        printf("Sum is %d\n", num1 + num2);
        printf("Do you want to continue? (Y or N)\n");
        scanf("%1s", &letter[1]);
    }
    while (letter[1] == 'Y');
    printf("Bye!\n");
    return 0;
}