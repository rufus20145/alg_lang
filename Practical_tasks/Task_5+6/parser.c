#ifndef PARSER
#define PARSER
/**
 * 
 * @file parser.c
 * @author your name (you@domain.com)
 * @brief ���� � �������� �������� ��������� ��������
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "output.c"

/**
 * @brief ������� �������� ���
 * 
 * @param array ������ ��� ��������
 * @return int ��������� ��������
 */
int checkCredential(char *array)
{
    int arraySize = strlen(array);
    arraySize--; // ��� ����� �� ��������� ������ � ������ ��� �� ���� ��������� �� �����
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha(array[i]))
        {
            // printf("%c �� �������� ������ ", array[i]);
            printf("������ �����. ��������� �������. ");
            clearArray(array, MAXSIZE);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}

/**
 * @brief �������, ����������� ������� ���� ������ � �������� �����
 * 
 * @param fileName ��� ����� ��� ��������
 * @return int ��� ������ (0 - ������ ���, 1 - ������ ����)
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
        return 0; //������ ����
    }
    else
    {
        fclose(currFile);
        return 1; //������ ���
    }
}

/**
 * @brief ������� ������ ���� ������ ��������� �� ����� � ������ 
 * 
 * @param fileName ��� ����� � ����� ������
 * @param students ���������, � ������� ���� �������� ���������
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
        if (0 == trashString) //���������� �������� 1 ������, �.�. � ��� �������
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
 * @brief ������� ��� ������� ��������� � ������� � �������� 
 * 
 * @param structure ��������� �� ���������, � ������� ���� ������� ������
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
 * @brief ������� ��� �������� ������ � �������� �� ����� ��������� ������� � ������ (��������, ��� �������� ������� ���� �������� ���� ��������� �� 1 � ������)
 * 
 * @param *destination ��������� �� �������� ���������
 * @param source ������ �� �������� ���������
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