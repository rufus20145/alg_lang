/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberOfIterations = 0/*enteredNumber = 1*/;

    printf("Введите количество итераций:");
    scanf("%d", &numberOfIterations);

    for (int i = 0; i < numberOfIterations; i++)
    {
        malloc(i * sizeof(int));
    }
    getchar();
    getchar();
}