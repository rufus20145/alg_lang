#ifndef OUTPUT
#define OUTPUT
#define BIGSTRING_SIZE 1024
#define MAXSIZE 256

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
    sprintf(buffer, "%02d", structure.birthDay);
    strcat(resultString, buffer);
    strcat(resultString, ".");
    sprintf(buffer, "%02d", structure.birthMonth);
    strcat(resultString, buffer);
    strcat(resultString, ".");
    sprintf(buffer, "%04d", structure.birthYear);
    strcat(resultString, buffer);

    strcat(resultString, "  ");
    strcat(resultString, structure.email);
    strcat(resultString, "\n");

    printArray(resultString);
}
#endif // !OUTPUT