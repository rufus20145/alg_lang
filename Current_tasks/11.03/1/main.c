/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief работа с файлами (fopen fclose fpintf 
 * @version 0.1
 * @date 2020-11-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    int first, second;
    FILE *inputFile;
    inputFile = fopen(argv[1], argv[2]);
    scanf("%d %d", &first, &second);
    if (inputFile == NULL)
    {
        printf("Error opening file");
    }
    else
    {
        fprintf(inputFile, "Первое число: %d\n", first);
        // printf("Первое число: %d\n", first);
        fprintf(inputFile, "Второе число: %d\n", second);
        // printf("Второе число: %d\n", second);
        fclose(inputFile);
    }
    return 0;
}