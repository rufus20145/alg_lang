/**
 * @file main.c
 * @author rufus20145 (ivan2002774@gmail.com)
 * @brief Задание на использование getchar(), getch(), putch(), putchar()
 * @version 1.0
 * @date 2020-10-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <conio.h>

int main()
{
    char character, first, second;
    printf("Enter 1 simbol for getchar() ");
    character = getchar();
    putchar(character);
    printf("\nEnter 2 simbols getch() ");
    first = getch();
    putch(first);
    second = getch();
    putch(second);
    printf("\n(%c) (%c)\n", first, second);
    printf("Enter 2 simbols getchar() ");
    getchar();
    first = getchar();
    getchar();
    second = getchar();
    printf("(%c) (%c)\n", first, second);
    printf("(%d) (%d)\n", first - '0', second - '0');
    return 0;
}