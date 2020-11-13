/**
 * @file input.c
 * @author your name (you@domain.com)
 * @brief файл с функциями ввода и очистки массива
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAXSIZE 256

/**
 * @brief функция ввода ФИО и номера группы
 * 
 * @param array массив, куда класть введенные данные
 * @return void
 */
void enterCredential(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
            array[i] = ' ';
            break;
        }
        else
        {
            array[i] = buffer;
        }
    }
}

/**
 * @brief функция для очистки массива
 * 
 * @param array - массив для очистки
 */
void clearArray(char *array)
{

    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '\0';
    }
}
