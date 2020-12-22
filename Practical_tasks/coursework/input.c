#ifndef INPUT
#define INPUT
/**
 * @file input.c
 * @author your name (you@domain.com)
 * @brief ���� � ��������� ����� � ������� �������
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

#define MAXSIZE 256

/**
 * @brief ������� ����� ����� � ��������� �����
 * 
 * @param *number ��������� �� ����� � ���������� �������
 * @return int ��� ������
 */
int enterNumber(int *number)
{
    char buffer[MAXSIZE] = "";
    fgets(buffer, MAXSIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    int bufferLength = strlen(buffer);
    if (bufferLength && strcmp(buffer, "-")) 
    {
        for (int i = 0; i < bufferLength; i++)
        {
            if (!isdigit(buffer[i]) && buffer[i] != '-')
            {
                printf("������! �� ����� ���������� �������, �������� �� ����.\n");
                return 1; //������, � ������ ���� �� ������ �����
            }
        }
        *number = atoi(buffer);
        return 0;
    }
    else
    {
        printf("�� �� ����� �� ������ �������, ��������� �������. ");
        return 1;
    }
}

/**
 * @brief ������� ����� ��� � ������ ������
 * 
 * @param array ������, ���� ������ ��������� ������
 * @return void
 */
void enterArray(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
            break;
        }
        else
        {
            array[i] = buffer;
        }
    }
}

/**
 * @brief ������� ��� ������� �������
 * 
 * @param array - ������ ��� �������
 */
void clearArray(char *array, int arraySize)
{

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '\0';
    }
}

/**
 * @brief ������� ����� ����� ������������� ��� �������� ������ �����
 * 
 * @return int ��� ������ (0 ��� ������, 1 ���� ������, 2 ���� ������)
 */
int chooseFile(char *fileName)
{
    FILE *currFile = NULL;
    int action;
    int inputErrorCode = 0;

    printf("1)������� ������������ ����.\n2)������� ����� ����/�������� ������������.\n0)����� �� ������ ���������� �����\n");
    do
    {
        inputErrorCode = enterNumber(&action);
    } while (inputErrorCode == 1);
    switch (action)
    {
    case 1: //����� ������������� �����
    {
        printf("������� ��� ������������� �����: ");
        enterArray(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            printf("���� �� ������. ��������� �������.\n");
            return 1;
        }
        else
        {
            currFile = fopen(fileName, "r");
            printf("���� ������� ������.\n");
            fclose(currFile);
            return 0;
        }
        break;
    }
    case 2: //�������� ������ �����
    {
        printf("������� ��� �����, ������� ���������� �������: ");
        enterArray(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            currFile = fopen(fileName, "w");
            if (NULL == currFile)
            {
                printf("������ �������� �����. ��������� �������.\n");
                return 1;
            }
            else
            {
                char refString[MAXSIZE / 4] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
                fputs(refString, currFile);
                fclose(currFile);
                printf("���� ������� ������. ���� ������ ����������������.\n");
                return 0;
            }
        }
        else
        {
            printf("����� ���� ��� ����������, ������� 1, ���� �� ������ �������� ���, ����� ����� ����� �������.\n");
            if (getchar() == '1')
            {
                currFile = fopen(fileName, "w");
                char refString[MAXSIZE / 4] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
                fputs(refString, currFile);
                fclose(currFile);
                fflush(stdin);
                printf("���� ������� ������. ���� ������ ����������������.\n");
                return 0;
            }
            else
            {
                currFile = fopen(fileName, "r");
                fclose(currFile);
                fflush(stdin);
                printf("���� �� ��� ������.\n");
                return 0;
            }
        }
        break;
    }
    case 0:
    {
        printf("����� ����� ������.\n");
        return 2;
    }
    default: //������ ������ ������
    {
        printf("\n����������� ��������. ��������� �������.\n");
        return 1;
        break;
    }
    }
}
#endif // !INPUT