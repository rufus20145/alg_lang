#include <stdio.h>

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

