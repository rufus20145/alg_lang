/**
 * @file parser.c
 * @author your name (you@domain.com)
 * @brief ���� � �������� �������� ��������� ��������
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief ������� �������� ������ ������
 * 
 * @param array ������ � ������� ������ ��� ��������
 * @return int ��������� ��������
 */
int checkGroup(char *array)
{
    int arraySize = strlen(array);
    arraySize--; // ��� ����� �� ��������� ������ � ������ ��� �� ���� ��������� �� �����
    for (int i = 0; i < arraySize; i++)
    {
        if (!isalpha(array[i]))
        {
            printf("������ �����. ��������� �������. ");
            clearArray(array);
            return 0;
        }
    }
    return 1;
}

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
            clearArray(array);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}
