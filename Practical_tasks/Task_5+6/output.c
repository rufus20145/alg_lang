#ifndef OUTPUT
#define OUTPUT
#define BIGSTRING_SIZE 1024
#define MAXSIZE 256

#include <stdio.h>
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

/**
 * @brief ������� ������ ������ �������� � ����
 * 
 * @param structure ��������� � ������� ��������
 * @param fileName ��� �����, � ������� ���������� �������� ������
 */
void exportSudentData(const studentStruct structure, char *fileName)//�������� ����� �������� 
{
    char resultString[BIGSTRING_SIZE] = "", buffer[MAXSIZE] = "";
    FILE *currFile = fopen(fileName, "a");

    //����� �������� ������ ��������
    sprintf(buffer, "%d", structure.number);
    strcat(resultString, buffer);
    strcat(resultString, ".");

    strcat(resultString, structure.surName);
    strcat(resultString, " ");

    strcat(resultString, structure.name);
    strcat(resultString, " ");

    strcat(resultString, structure.middleName);
    strcat(resultString, " ");

    strcat(resultString, structure.group);
    strcat(resultString, " ");

    sprintf(buffer, "%02d", structure.birthDay);
    strcat(resultString, buffer);
    strcat(resultString, ".");

    sprintf(buffer, "%02d", structure.birthMonth);
    strcat(resultString, buffer);
    strcat(resultString, ".");

    sprintf(buffer, "%02d", structure.birthYear);
    strcat(resultString, buffer);
    strcat(resultString, " ");

    strcat(resultString, structure.email);
    strcat(resultString, "\n");

    fputs(resultString, currFile); //����� ������ �������� ������ ��������

    //������ ������� ������ � ������� ����, ���� ��� ���� �������
    if (structure.numberOfSubjects > 0)
    {
        strcpy(resultString, "");
        for (int currSubject = 0; currSubject < structure.numberOfSubjects; currSubject++)
        {
            sprintf(buffer, "    ������ �� �������� %s: ", structure.subjectName[currSubject]);
            strcat(resultString, buffer);
            for (int currMark = 0; currMark < structure.numberOfMarks[currSubject]; currMark++)
            {
                sprintf(buffer, "%d ", structure.marks[currSubject][currMark]);
                strcat(resultString, buffer);
            }
            sprintf(buffer, "������� ���� = %.2f", structure.averageMark[currSubject]);
            strcat(resultString, buffer);
            strcat(resultString, "\n");
        }
        sprintf(buffer, "    ����� ������� ���� = %.2f\n\n", structure.totalAverageMark);
        strcat(resultString, buffer);
        fputs(resultString, currFile); //����� ������ ������
    }
    else
    {
        fputs("    � ������� �������� ��� ������ �� �������.\n\n", currFile);
    }

    fclose(currFile);
}

#endif // !OUTPUT