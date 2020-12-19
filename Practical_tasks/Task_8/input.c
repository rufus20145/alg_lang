#ifndef INPUT
#define INPUT
/**
 * @file input.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief файл с дополнительными функциями ввода с клавиатуры
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAX_SIZE 256
#include <stdio.h>

/**
 * @brief функция ввода числа с проверкой корректности ввода
 * 
 * @param *number указатель на число в вызывающей функции
 * @return int код ошибки
 */
int enterNumber(int *number)
{
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    int bufferLength = strlen(buffer);
    if (bufferLength && strcmp(buffer, "-"))
    {
        for (int i = 0; i < bufferLength; i++)
        {
            if (!isdigit(buffer[i]) && buffer[i] != '-')
            {
                printf("Ошибка! Во вводе обнаружены символы, отличные от цифр.\n");
                return 1; //ошибка, в строке есть не только цифры
            }
        }
        *number = atoi(buffer);
        return 0;//ошибки нет, выходим из функции
    }
    else
    {
        printf("Вы не ввели ни одного символа, повторите попытку. ");
        return 1;//ошибка, введенная строка пуста
    }
}
#endif // !INPUT
