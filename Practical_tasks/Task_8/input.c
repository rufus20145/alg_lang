/**
 * @brief ������� ����� ����� � ��������� �����
 * 
 * @param *number ��������� �� ����� � ���������� �������
 * @return int ��� ������
 */
int enterNumber(int *number)
{
    char buffer[MAXSIZE];
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