/**
 * @file output.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief ���� � ��������� ������
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief ������� ������ ������� ��������
 * 
 * @param array ������ ��� ������
 */
void printArray(char *array)
{
    int arraySize = strlen(array);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%c", array[i]);
    }
    if (array[arraySize - 1] != '\n')
    {
        printf("\n");
    }
}
