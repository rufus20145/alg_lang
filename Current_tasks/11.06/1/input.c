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
void clearArray(char *array)
{

    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '\0';
    }
}
