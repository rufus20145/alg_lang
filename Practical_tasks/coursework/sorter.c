/**
 * @file sorter.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @param location1 
 * @param location2 
 */
void swapNumbers(int *location1, int *location2)
{
    int buffer = *location1;
    *location1 = *location2;
    *location2 = buffer;
}

/**
 * @brief функция, сортирующая переданный массив плным перебором по убыванию
 * 
 * @param num 
 * @param size 
 */
void sortArray(int *num, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (num[i] > num[j])
            {
                swapNumbers(&num[i], &num[j]);
            }
        }
    }
}