#ifndef OUTPUT
#define OUTPUT

#ifndef PARSER

typedef struct
{
    int number;
    char surName[MAXSIZE];
    char name[MAXSIZE];
    char middleName[MAXSIZE];
    char group[MAXSIZE];
    int birthDay, birthMonth, birthYear;
    char email[MAXSIZE];
} studentStuct;

#endif // !PARSER



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

printStudentData(studentStuct *structure)
{
    printf("%d %s %s %s %s %d %d %d %s", structure->number, structure->surName, structure->name, structure->middleName, structure->group, structure->birthDay, structure->birthMonth, structure->birthYear, structure->email);
}
#endif // !OUTPUT