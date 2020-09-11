#include <stdio.h>
#include <locale.h>
#define N 10
/*
    программа выводит числа от 1 до n-10, если введенное число больше 10, и числа от 1 до n+10, если оно меньше-равно 10
*/
int main() {
    setlocale(LC_ALL, "");
    long num;
    scanf("%ld", &num);
    printf("\n");
    if(num <= N) {
        num += N;
    } else num -= N;
    for(int i = 0; i < num; i++) {
        printf("%d\n", i+1);
    }
    printf("Конец");
    return 0;
}