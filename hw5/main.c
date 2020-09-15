/*
    программа, изменяющая вывод в зависимости от введенных значений
    если 1 число больше, выводим разность двух чисел
    иначе выводим их сумму
*/

#include <stdio.h>

int main() {
    int num1, num2, tmp;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    if(num1 > num2) {
        printf("Num1 is greater.\nDifference is %d.", num1 - num2);
    }
    else {
        printf("Num2 is greater.\nSum is %d.", num1 + num2);
    }
    return 0;
}