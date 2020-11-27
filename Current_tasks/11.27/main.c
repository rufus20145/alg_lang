#include <stdio.h>
#include <locale.h>
#define MAXSIZE 256
#define NUMBER_OF_SUBJECTS 16

int main()
{
    setlocale(LC_ALL, "");
    char identifier[MAXSIZE] = "";
    int marks[NUMBER_OF_SUBJECTS][MAXSIZE];
    int marksNumber[NUMBER_OF_SUBJECTS], subjectNumber;
    float averageMark[NUMBER_OF_SUBJECTS], markSum[NUMBER_OF_SUBJECTS];

    printf("������� ������������� ��������, ���������� ��������� � ���������� ������ ");
    scanf("%s %d", identifier, &subjectNumber);

    for (int i = 0; i < subjectNumber; i++)
    {
        printf("������� ���������� ������ �� %d �������� � ����� ��� ������. ", i+1);
        scanf("%d", &marksNumber[i]);
        for (int j = 0; j < marksNumber[i]; j++)
        {
            scanf("%d", &marks[i][j]);
            markSum[i] += marks[i][j];
        }
    }
    for (int i = 0; i < subjectNumber; i++)
    {
        averageMark[i] = markSum[i] / marksNumber[i];
        printf("������� ���� �� �������� %d: %.2f\n", i+1, averageMark[i]);
    }
    
    return 0;
}