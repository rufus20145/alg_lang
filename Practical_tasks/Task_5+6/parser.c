#ifndef PARSER
#define PARSER
/**
 * 
 * @file parser.c
 * @author your name (you@domain.com)
 * @brief файл с функцями проверки введенных значений
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "output.c"

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
            clearArray(array, MAXSIZE);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}

/**
 * @brief функция, проверяющая наличие базы данных в указаном файле
 * 
 * @param fileName имя файла для проверки
 * @return int код ошибки (0 - ошибки нет, 1 - ошибка есть)
 */
int checkDatabase(const char *fileName)
{
    FILE *currFile = NULL;
    char buffer[MAXSIZE] = "", referenceString[MAXSIZE] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";

    currFile = fopen(fileName, "r");
    fgets(buffer, MAXSIZE, currFile);
    if (!strcmp(buffer, referenceString))
    {
        fclose(currFile);
        return 0; //строка есть
    }
    else
    {
        fclose(currFile);
        return 1; //строки нет
    }
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
            Sleep(300);
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

void addStudentData(studentStruct *destination) {
    printf("HW");
}

#endif // !PARSER