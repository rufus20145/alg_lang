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
 * @brief ������� ����� ��� � ������ ������
 * 
 * @param array ������, ���� ������ ��������� ������
 * @return void
 */
void enterCredential(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
            array[i] = ' ';
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
 * @brief ������� ����� ����� ��� �������� ������ �����
 * 
 * @return int ��� ������ (0 ��� ������, 1 ���� ������)
 */
int chooseFile(char *fileName)
{
    FILE *currFile = NULL;
    char action;
    
    printf("�������� ����� ����:\n1)������� ������������ ����.\n2)������� ����� ����/�������� ������������.\n");
    action = getchar();
    fflush(stdin);
    switch (action)
    {
    case '1': //����� ������������� �����
    {
        printf("������� ��� ������������� �����: ");
        enterCredential(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            printf("������ �������� �����. ��������� �������.\n");
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
    case '2': //�������� ������ �����
    {
        printf("������� ��� �����, ������� ���������� �������: ");
        enterCredential(fileName);
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
                fclose(currFile);
                printf("���� ������� ������.\n");
                return 0;
            }
        }
        else
        {
            printf("����� ���� ��� ����������, ������� 1, ���� �� ������ �������� ���, ����� ����� ����� �������.\n");
            if (getchar() == '1')
            {
                currFile = fopen(fileName, "w");
                fclose(currFile);
                fflush(stdin);
                printf("���� ������� ������.\n");
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
    default: //������ ������ ������
    {
        // system("cls");
        printf("\n����������� ��������. ��������� �������.\n");
        return 1;
        break;
    }
    }
}
#endif // !INPUT