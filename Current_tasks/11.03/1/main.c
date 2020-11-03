/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief ������ � ������� (fopen fclose fpintf 
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
        fprintf(inputFile, "������ �����: %d\n", first);
        // printf("������ �����: %d\n", first);
        fprintf(inputFile, "������ �����: %d\n", second);
        // printf("������ �����: %d\n", second);
        fclose(inputFile);
    }
    return 0;
}