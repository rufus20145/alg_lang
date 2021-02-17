/**
 * @file output.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief файл с функциями вывода
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief функция вывода массива символов
 * 
 * @param array массив для вывода
 */
void printArray(char *array)
{
    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%c", array[i]);
        if( '\0' == array[i]) printf("\nСимвол конца строки\n");
    }
    if (array[arraySize - 1] != '\n')
    {
        printf("\n");
    }
}
