/**
 * @file parser.c
 * @author your name (you@domain.com)
 * @brief файл с функцями проверки введенных значений
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief функция проверки номера группы
 * 
 * @param array массив с номером группы для проверки
 * @return int результат проверки
 */
int checkGroup(char *array)
{
    int arraySize = strlen(array);
    arraySize--; // при вводе мы добавляем пробел в конеци его не надо проверять на букву
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha(array[i]))
        {
            printf("Ошибка ввода. Повторите попытку. ");
            clearArray(array);
            return 0;
        }
    }
    return 1;
}

/**
 * @brief функция проверки ФИО
 * 
 * @param array массив для проверки
 * @return int результат проверки
 */
int checkCredential(char *array)
{
    int arraySize = strlen(array);
    arraySize--; // при вводе мы добавляем пробел в конеци его не надо проверять на букву
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha(array[i]))
        {
            // printf("%c не является буквой ", array[i]);
            printf("Ошибка ввода. Повторите попытку. ");
            clearArray(array);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}
