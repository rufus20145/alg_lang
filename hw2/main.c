#include <stdio.h>

int main() {
    int num1, num2;
    printf("Please enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    if(num1 == num2) printf("Numbers are qual.\n");
    else if(num1 > num2) printf("First number is bigger.\n");
    else printf("Second number is bigger.\n");
    return 0;
}