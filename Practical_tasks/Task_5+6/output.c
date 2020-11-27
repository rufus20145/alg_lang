#ifndef OUTPUT
#define OUTPUT

#include "struct.c"


/**
 * @brief 
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ���� � ��������� ������
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief ������� ������ ������� ��������
 * 
 * @param array ������ ��� ������
 */
void printArray(char *array)
{
    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%c", array[i]);
        if ('\0' == array[i])
            printf("\n������ ����� ������\n");
    }
    if (array[arraySize - 1] != '\n')
    {
        printf("\n");
    }
}

int printStudentData(studentStuct *structure)
{
    printf("%d %s %s %s %s %d %d %d %s", structure->number, structure->surName, structure->name, structure->middleName, structure->group, structure->birthDay, structure->birthMonth, structure->birthYear, structure->email);
    return 0;
}
#endif // !OUTPUT