#ifndef INPUT
#define INPUT
/**
 * @file input.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ���� � ��������������� ��������� ����� � ����������
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAX_SIZE 256
#include <stdio.h>

/**
 * @brief ������� ����� ����� � ��������� ������������ �����
 * 
 * @param *number ��������� �� ����� � ���������� �������
 * @return int ��� ������
 */
int enterNumber(int *number)
{
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, stdin);
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
        return 0;//������ ���, ������� �� �������
    }
    else
    {
        printf("�� �� ����� �� ������ �������, ��������� �������. ");
        return 1;//������, ��������� ������ �����
    }
}
#endif // !INPUT
