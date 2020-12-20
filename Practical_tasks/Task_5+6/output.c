#ifndef OUTPUT
#define OUTPUT
#define BIGSTRING_SIZE 1024
#define MAXSIZE 256

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
    }
}

/**
 * @brief ������� ��� ������ ���������� � �������� �� �����
 * 
 * @param structure ��������� � ������� ��������
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