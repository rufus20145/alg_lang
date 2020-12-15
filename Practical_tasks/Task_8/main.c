/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief 8 ������������ ������ - ���������� ���������� ������� � �������������� ���������� ��� ������ ��������� 
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "input.h"

#define MAX_SIZE 256

int main()
{
    int **array;
    int arrayHeight = 0, arrayWidth = 0, inputErrorCode = 0;

    system("cls"); //������� ������� ����� ������� ���������

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

    printf("������� ������ �������");
    do
    {
        inputErrorCode = enterNumber(&arrayHeight);
    } while (1 == inputErrorCode);
    do
    {
        inputErrorCode = enterNumber(&arrayWidth);
    } while (1 == inputErrorCode);
    printf("��������: %d � %d", arrayWidth, arrayHeight);
}