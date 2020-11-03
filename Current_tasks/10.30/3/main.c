/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief Задание на использование string.h: strlen, strcpy, strcat
 * @version 0.1
 * @date 2020-10-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 256

int main()
{
    int size1, size2;
    char array1[MAX_SIZE], array2[MAX_SIZE];

    printf("Enter 1 array size: ");
    scanf("%d", &size1);
    printf("Enter 2 array size: ");
    scanf("%d", &size2);

    printf("Now enter 1 string: ");
    for (int i = 0; i < size1; i++)
    {
        scanf("%c", &array1[i]);
    }
    printf("Now enter 2 string: ");
    for (int i = 0; i < size2; i++)
    {
        scanf("%c", &array2[i]);
    }

    printf("Arrays were: %s %s\n", array1, array2);
    strcat(array1, array2);
    printf("Now arrays are: %s \n123\n%s\n", array1, array2);
}