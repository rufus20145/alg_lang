/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief Задание на использование isalpha, isdigit, toupper, tolower
 * @version 0.1
 * @date 2020-10-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <ctype.h>

int main()
{
    int first, second;
    printf("Enter 2 simbols for getchar() ");
    first = getchar();
    getchar();
    second = getchar();

    // first = toupper(first); // поднимает регистр введенной буквы
    printf("\n");

    switch (isalpha(first))
    {
    case 1:
        printf("First is BIG simbol.\n");
        break;
    case 2:
        printf("First is small simbol.\n");
        break;
    case 0:
        printf("First is not a simbol.\n");
        break;
    default:
        printf("Error.\n");
        break;
    }

    switch (isalpha(second))
    {
    case 1:
        printf("Second is BIG simbol.\n");
        break;
    case 2:
        printf("Second is small simbol.\n");
        break;
    case 0:
        printf("Second is not a simbol.\n");
        break;
    default:
        printf("Error.\n");
        break;
    }
    /*
    if (isalpha(first))
    {
        printf("First is alpha. %d\n", isalpha(first));
    }
    else
    {
        printf("First is not alpha. %d\n", isalpha(first));
    }
    if (isalpha(second))
    {
        printf("Second is alpha. %d\n", isalpha(second));
    }
    else
    {
        printf("Second is not alpha. %d\n", isalpha(second));
    }
    */
    return 0;
}











