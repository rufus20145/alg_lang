#include <stdio.h>

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
            printf("File recieved: %s\n", fileName);
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
            fputs("matrix", currFile);
            fclose(currFile);
            printf("���� ������� ������.\n");
            return 0;
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
        printf("����������� ��������. ��������� �������.\n");
        return 1;
        break;
    }
    }
}

/**
 * @brief ������� �������� ������� ��������� � �����
 * 
 * @param fileName ��� �����
 * @return int ��� ������ (0 - ��� ������, 1 - ��������� ���)
 */
int checkFile(char *fileName)
{
    // printf("File 123recieved: %s\n", fileName);
    FILE *currFile = NULL;
    char buffer[MAXSIZE] = "", refString[MAXSIZE] = "matrix";

    currFile = fopen(fileName, "r");
    fflush(stdin);
    fgets(buffer, 7, currFile);
    // printf("123:%d\n", strcmp(buffer, refString));
    if (!strcmp(buffer, refString))
    {
        printf("������� �������.\n");
        fclose(currFile);
        return 0;
    }
    else
    {
        fclose(currFile);
        return 1; //�������� �� 1
    }
}

/**
 * @brief 
 * 
 */

