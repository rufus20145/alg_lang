#include <stdio.h>
#include <string.h>


int main() {
    int num1, num2;
    char letter[3];
    printf("Hello!\n");
    do {
        printf("Please enter two numbers:\n");
        scanf("%d %d", &num1, &num2);
        if(num1 > num2) printf("Num1 is greater than num2 by %d.\n", num1 - num2);
        else printf("Num2 is greater than num1, their sum is: %d.\n", num1 + num2);
        printf("Do you want to continue? (YES or NO). Default is YES\n");
        scanf("%3s", letter);// %c doesn`t work
        // if(letter == 'n') break;
    }
    while (!strcmp(letter, "YES"));//two conditions at the same time doesn`t work - ((letter != 'N') || (letter != 'n'))
    printf("Bye!\n");
    return 0;
}