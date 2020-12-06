#ifndef OUTPUT
#define OUTPUT
#define BIGSTRING_SIZE 1024

#include "struct.c"

/**
 * @brief 
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
        if ('\0' == array[i])
            printf("\nСимвол конца строки\n");
    }
    if (array[arraySize - 1] != '\n')
    {
        printf("\n");
    }
}

/**
 * @brief функция для вывода информации о студенте на экран
 * 
 * @param structure структура с данными студента
 * @return int 
 */
void printStudentData(const studentStruct structure)
{
    char resultString[BIGSTRING_SIZE] = "", buffer[MAXSIZE] = "";

    sprintf(buffer, "%d", structure.number);
    strcat(resultString, buffer);
    strcat(resultString, ".");
    strcat(resultString, structure.surName);

    strcat(resultString, "  ");
    strcat(resultString, structure.name);

    strcat(resultString, "  ");
    strcat(resultString, structure.middleName);

    strcat(resultString, "  ");
    strcat(resultString, structure.group);

    strcat(resultString, "  ");
    if (structure.birthDay < 10) //нужно получить 06., а не 6.
    {
        char temp[MAXSIZE / 8];
        strcpy(buffer, "0");
        sprintf(temp, "%d", structure.birthDay);
        strcat(buffer, temp);
    }
    else
    {
        sprintf(buffer, "%d", structure.birthDay);
    }
    strcat(resultString, buffer);
    strcat(resultString, ".");
    if (structure.birthMonth < 10) //нужно получить 06., а не 6.
    {
        char temp[MAXSIZE / 8];
        strcpy(buffer, "0");
        sprintf(temp, "%d", structure.birthMonth);
        strcat(buffer, temp);
    }
    else
    {
        sprintf(buffer, "%d", structure.birthMonth);
    }
    strcat(resultString, buffer);
    strcat(resultString, ".");
    sprintf(buffer, "%d", structure.birthYear);
    strcat(resultString, buffer);

    strcat(resultString, "  ");
    strcat(resultString, structure.email);

    printArray(resultString);
}
#endif // !OUTPUT