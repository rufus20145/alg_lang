#ifndef PARSER
#define PARSER
/**
 * 
 * @file parser.c
 * @author your name (you@domain.com)
 * @brief файл с функциями проверки введенных значений
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <string.h>
#include "output.c"
#include "struct.c"

/**
 * @brief функция для проверки email на корректность
 * 
 * @param array указатель на массив с введенной почтой
 * @return int результат проверки (0 - ввод верен, 1 - присутствуют ошибки)
 */
int checkEmail(char *array)
{
    int length = strlen(array), numberOfDogs = 0, dogPosition = -1, firstDotPosition = -1;
    // dogPosition - номер ячейки с @, firstDotPosition - номер ячейки с первой точкой после @

    for (int i = 0; i < length; i++)
    {
        if (array[i] == '@')
        {
            numberOfDogs++;
            dogPosition = i;
            //printf("Found dog.It`s on %d place\n", dogPosition + 1);//кусок дебага
        }
        if (numberOfDogs > 0 && array[i] == '.' && firstDotPosition == -1)
        {
            firstDotPosition = i;
            //printf("Found first dot after dog. It`s on %d place\n", firstDotPosition + 1);//кусок дебага
        }
    }
    if (length < 7)
    {
        printf("Email слишком короткий. Повторите попытку ");
        return 1;
    }
    else if (numberOfDogs != 1)
    {
        printf("Количество символов @ не может отличаться от 1. Повторите попытку ");
        return 1;
    }
    else if ('@' == array[0]) //если первый символ - @
    {
        printf("Символ @ не может находиться на 1 месте, перед ним должна быть хотя бы одна буква или цифра. Повторите попытку ");
        return 1;
    }
    else if (firstDotPosition - dogPosition < 3) //если между @ и первой точкой после нее меньше 2 символов
    {
        printf("Домен второго уровня не может быть меньше 2 символов. Повторите попытку ");
        return 1;
    }
    else if (length - firstDotPosition - 1 < 3)
    {
        printf("Домен первого уровня не может быть меньше 2 символов. Повторите попытку ");
        return 1;
    }
    else
    {
        array[length - 1] = '\0';
    }
    return 0;
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
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha((unsigned char)array[i]))
        {
            printf("%c не является буквой ", array[i]);
            printf("Ошибка ввода. Повторите попытку. ");
            clearArray(array, MAXSIZE);
            return 1;
        }
    }
    array[0] = toupper(array[0]);
    return 0;
}

/**
 * @brief функция чтения базы данных студентов из файла и записи 
 * 
 * @param fileName имя файла с базой данных
 * @param students структура, в которую надо записать студентов
 */
void readDatabase(const char *fileName, studentStruct *students, int *NumberOfStudents)
{
    char buffer[MAXSIZE] = "";
    char *flag = NULL;
    FILE *currFile = NULL;
    int studentNumber = 0, trashString = 0, fieldNumber = 0;

    currFile = fopen(fileName, "r");
    while (!feof(currFile))
    {
        if (0 == trashString) //необходимо выкинуть 1 строку, т.к. в ней образец
        {
            fgets(buffer, MAXSIZE, currFile);
            trashString = 1;
        }
        flag = fgets(buffer, MAXSIZE, currFile);
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        if (flag != NULL)
        {
            char *separatedBuffer = "";
            separatedBuffer = strtok(buffer, ";");
            while (NULL != separatedBuffer)
            {
                switch (fieldNumber)
                {
                case 0:
                {
                    students[studentNumber].number = atoi(separatedBuffer);
                    break;
                }
                case 1:
                {
                    strcpy(students[studentNumber].surName, separatedBuffer);
                    break;
                }
                case 2:
                {
                    strcpy(students[studentNumber].name, separatedBuffer);
                    break;
                }
                case 3:
                {
                    strcpy(students[studentNumber].middleName, separatedBuffer);
                    break;
                }
                case 4:
                {
                    strcpy(students[studentNumber].group, separatedBuffer);
                    break;
                }
                case 5:
                {
                    students[studentNumber].birthDay = atoi(separatedBuffer);
                    break;
                }
                case 6:
                {
                    students[studentNumber].birthMonth = atoi(separatedBuffer);
                    break;
                }
                case 7:
                {
                    students[studentNumber].birthYear = atoi(separatedBuffer);
                    break;
                }
                case 8:
                {
                    strcpy(students[studentNumber].email, separatedBuffer);
                    break;
                }
                default:
                    break;
                }
                separatedBuffer = strtok(NULL, ";");
                fieldNumber++;
            }
            studentNumber++;
            fieldNumber = 0;
            Sleep(200);
        }
    }
    *NumberOfStudents = studentNumber;
}

/**
 * @brief функция для очистки структуры с данными о студента 
 * 
 * @param structure указатель на структуру, в которой надо удалить данные
 */
void deleteStudentData(studentStruct *structure)
{
    structure->number = -1;
    clearArray(structure->name, MAXSIZE);
    clearArray(structure->surName, MAXSIZE);
    clearArray(structure->middleName, MAXSIZE);
    clearArray(structure->group, MAXSIZE);
    structure->birthDay = 0;
    structure->birthMonth = 0;
    structure->birthYear = 0;
    clearArray(structure->email, MAXSIZE);
    Sleep(200);
}

/**
 * @brief функция для переноса данных о студенте из одной структуры массива в другую (например, при удалении первого надо сдвинуть всех остальных на 1 к началу)
 * 
 * @param *destination указатель на конечную структуру
 * @param source данные из исходной структуры
 */
void moveStudentData(studentStruct *destination, const studentStruct source)
{
    destination->number = source.number - 1;
    strcpy(destination->name, source.name);
    strcpy(destination->surName, source.surName);
    strcpy(destination->middleName, source.middleName);
    strcpy(destination->group, source.group);
    destination->birthDay = source.birthDay;
    destination->birthMonth = source.birthMonth;
    destination->birthYear = source.birthYear;
    strcpy(destination->email, source.email);
    Sleep(200);
}

/**
 * @brief функция для ввода с клавиатуры анкетных данных студента и последующей записи их в структуру
 * 
 * @param destination указатель на структуру, куда необходимо записать полученные данные
 */
void addStudentData(studentStruct *destination, int numberOfStudent)
{
    numberOfStudent++;
    char buffer[MAXSIZE] = "";
    printf("Введите фамилию студента %d: ", numberOfStudent);
    do
    {
        fgets(buffer, MAXSIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
    } while (1 == checkCredential(buffer));
    strcpy(destination->surName, buffer);

    printf("Введите имя студента %d: ", numberOfStudent);
    do
    {
        fgets(buffer, MAXSIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
    } while (1 == checkCredential(buffer));
    strcpy(destination->name, buffer);

    printf("Введите отчество студента %d: ", numberOfStudent);
    do
    {
        fgets(buffer, MAXSIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
    } while (1 == checkCredential(buffer));
    strcpy(destination->middleName, buffer);

    printf("Введите номер группы студента %d: ", numberOfStudent);
    do
    {
        fgets(buffer, MAXSIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        if (!isalpha((unsigned char)buffer[0]) || !isalpha((unsigned char)buffer[7]) || !isdigit(buffer[1]) || !isalpha((unsigned char)buffer[2]) || !isdigit(buffer[4]) || !isdigit(buffer[5]) || !isdigit(buffer[6]) || !isdigit(buffer[9]) || !isdigit(buffer[10]))
        {
            printf("Ошибка в номере группы. Повторите попытку ");
        }
    } while (!isalpha((unsigned char)buffer[0]) || !isalpha((unsigned char)buffer[7]) || !isdigit(buffer[1]) || !isalpha((unsigned char)buffer[2]) || !isdigit(buffer[4]) || !isdigit(buffer[5]) || !isdigit(buffer[6]) || !isdigit(buffer[9]) || !isdigit(buffer[10]));
    strcpy(destination->group, buffer);

    printf("Введите дату рождения студента %d в формате ДД.ММ.ГГГГ: ", numberOfStudent);
    fgets(buffer, MAXSIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    char *separatedBuffer = "";
    separatedBuffer = strtok(buffer, ".");
    int fieldNumber = 0;
    while (separatedBuffer != NULL)
    {
        switch (fieldNumber)
        {
        case 0:
        {
            destination->birthDay = atoi(separatedBuffer);
            break;
        }
        case 1:
        {
            destination->birthMonth = atoi(separatedBuffer);
            break;
        }
        case 2:
        {
            destination->birthYear = atoi(separatedBuffer);
        }
        }
        separatedBuffer = strtok(NULL, ".");
        fieldNumber++;
    }

    printf("Введите электронную почту студента %d: ", numberOfStudent);
    do
    {
        fgets(buffer, MAXSIZE, stdin);
    } while (1 == checkEmail(buffer));
    strcpy(destination->email, buffer);
}

#endif // !PARSER