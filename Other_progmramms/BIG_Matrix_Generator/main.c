/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief программа, генерирующая случайную матрицу введенного размера
 * @version 0.1
 * @date 2020-12-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

void clearArray(char *array, int arraySize)
{

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '\0';
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int main()
{
    srand(time(NULL));
    int a, b;
    FILE *currFile = NULL;
    char fileName[256] = "", buffer[256] = "", array[65536] = "";

    printf("Enter fileName: ");
    scanf("%s", fileName);
    printf("Enter matrix size: ");
    scanf("%d %d", &a, &b);

    currFile = fopen(fileName, "w");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            int tmp = 1 + rand() % 100;
            sprintf(buffer, "%d", tmp);
            strcat(array, buffer);
            if (j < b - 1)
            {
                strcat(array, ";");
            }
            // Sleep(100);
        }
        strcat(array, "\n");
        fputs(array, currFile);
        clearArray(array, 1024);
        clearArray(buffer, 256);
    }
    fclose(currFile);
    printf("End.\n");
    return 0;
}