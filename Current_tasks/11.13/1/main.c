/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ������������� ������������ ������
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAX_SIZE 255 
#include <stdio.h>

int main() {
    int a;
    int array[MAX_SIZE];
    scanf("%d", &a);
    printf("%d", a);
    clearArray(array);
}

