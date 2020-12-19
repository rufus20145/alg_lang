/**
 * @file numSwapper.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief файл с функцией обмена элементов
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

void swapNumbers(int *num1, int *num2)
{
    int buffer = *num1;
    *num1 = *num2;
    *num2 = buffer;
}