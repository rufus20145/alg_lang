/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief использование заголовочных файлов
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAX_SIZE 255 
#include <stdio.h>
#include "header.h"

int main() {
    int a;
    char array[MAX_SIZE];
    scanf("%d", &a);
    printf("%d", a);
    clearArray(array);
}

