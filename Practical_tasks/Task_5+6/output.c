#ifndef OUTPUT
#define OUTPUT
#define BIGSTRING_SIZE 1024
#define MAXSIZE 256

#include <stdio.h>
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

/**
 * @brief функция записи данных студента в файл
 * 
 * @param structure структура с данными студента
 * @param fileName имя файла, в который необходимо записать данные
 */
void exportSudentData(const studentStruct structure, char *fileName)//изменить после курсовой 
{
    char resultString[BIGSTRING_SIZE] = "", buffer[MAXSIZE] = "";
    FILE *currFile = fopen(fileName, "a");

    //вывод анкетных данных студента
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

    fputs(resultString, currFile); //конец вывода анкетных данных студента

    //теперь выводим оценки и средний балл, если они были введены
    if (structure.numberOfSubjects > 0)
    {
        strcpy(resultString, "");
        for (int currSubject = 0; currSubject < structure.numberOfSubjects; currSubject++)
        {
            sprintf(buffer, "    Оценки по предмету %s: ", structure.subjectName[currSubject]);
            strcat(resultString, buffer);
            for (int currMark = 0; currMark < structure.numberOfMarks[currSubject]; currMark++)
            {
                sprintf(buffer, "%d ", structure.marks[currSubject][currMark]);
                strcat(resultString, buffer);
            }
            sprintf(buffer, "Средний балл = %.2f", structure.averageMark[currSubject]);
            strcat(resultString, buffer);
            strcat(resultString, "\n");
        }
        sprintf(buffer, "    Общий средний балл = %.2f\n\n", structure.totalAverageMark);
        strcat(resultString, buffer);
        fputs(resultString, currFile); //конец вывода оценок
    }
    else
    {
        fputs("    У данного студента нет данных об оценках.\n\n", currFile);
    }

    fclose(currFile);
}

#endif // !OUTPUT