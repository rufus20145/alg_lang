/**
 * @file functions.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

void clearArray(char *array)
{

    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '\0';
    }
}