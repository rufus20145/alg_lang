#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include "head.h"

#define l 40
#define a 20

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    /*int n, m;
    n=input("���������� �����", 2, 5);
    m=input("���������� ��������", 2, 5);
    int matrix[n][m];
    printf("\n");
        for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
        do {
            printf("������� ������� [%d][%d] (�� -100 �� 100): ", i, j);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j]>100||matrix[i][j]<-100)
                printf("������! ");
        } while (matrix[i][j]>100||matrix[i][j]<-100);
        }
    }
    printf("\n");
    printf("������������ �������:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int max=m*n, change;
    int array[max];
    int element=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            array[element]=matrix[i][j];
            element++;
        }
    }
    int flag;
    for(int i=max-1; i>=0; i--)
    {
        flag=1;
        for(int j=0; j<i; j++)
        {
            if(array[j]>array[j+1])
            {
                swap(&array[j],&array[j+1]);
                flag=0;
            }
        }
        if(flag==1) break;
    }
    element=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            matrix[i][j]=array[element];
            element++;
        }
    }

    printf("������������� �������:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("������� [%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }
    printf("\n");*/

    struct student_struct
    {
        unsigned char surname[l];
        char name[l];
        char patronymic[l];
        char course[l];
        char group[l];
        char email[l];
    };
    struct student_struct student[a];
    char filename[l] = "", line[128] = "";
    int number, i, /*j,*/ k, operation1, operation2, /*, check, check_course, check_group, check_email,*/ check_file;
    FILE *IOFile;
    for (int i = 0; i < a; i++)
    {
        clearArray(student[i].surname, l);
        clearArray(student[i].name, l);
        clearArray(student[i].patronymic, l);
    }

    printf("�������� ����� ����:\n1) ������� ����;\n2) ������� ����;\n0) ����� �� ���������.\n\n");
    do
    {
        scanf("%d", &operation1);
        printf("������ ����� %d.\n\n", operation1);
        switch (operation1)
        {
        case 1:
            printf("������� ���� � ���������� ����� (� ������� ����:/�����/���_�����.���������� �����): \n");
            scanf("%s", filename);
            IOFile = fopen(filename, "r+t");
            if (IOFile == 0)
            {
                printf("���� �� ������.\n\n");
                printf("�������� ����� ����:\n1) ������� ����;\n2) ������� ����;\n0) ����� �� ���������.\n\n");
                check_file = 0;
            }
            else
            {
                printf("���� ������.\n\n");
                check_file = 1;
            }
            fclose(IOFile);
            break;
        case 2:
            printf("������� ���� � ������������ ����� (� ������� ����:/�����/���_�����.���������� �����): \n");
            scanf("%s", filename);
            IOFile = fopen(filename, "a+t");
            printf("���� ������.\n\n");
            fclose(IOFile);
            check_file = 1;
            break;
        case 0:
            return 0;
        default:
            printf("������! \n\n�������� ����� ����:\n1) ������� ����;\n2) ������� ����;\n0) ����� �� ���������.\n\n");
        }
        if (check_file == 1)
            break;
    } while (operation1 != 0);
    printf("�������� ��������:\n1) �������� ��������;\n2) ������� ������ ���������;\n3) �������� ������ ���������;\n4) �������� ������� ����;\n0) ����� �� ���������.\n\n");
    do
    {
        scanf("%d", &operation2);
        printf("������� �������� %d.\n\n", operation2);
        switch (operation2)
        {
        case 1:
        {
            do
            {
                printf("������� ���������� ����������� ��������� (�� 1 �� 20): ");
                scanf("%d", &number);
            } while (isalpha(number) || number < 1 || number > 20);
            fflush(stdin);
            printf("\n");
            for (i = 0; i < number; i++)
            {
                enter_name("�������", i, student[i].surname);
                enter_name("���", i, student[i].name);
                enter_name("��������", i, student[i].patronymic);
                enter_course(i, student[i].course);
                enter_group(i, student[i].group);
                enter_email(i, student[i].email);
                printf("\n");
            }
            IOFile = fopen(filename, "a+t");
            for (k = 0; k < number; k++)
            {
                if (islower(student[k].surname[0]))
                    student[k].surname[0] = toupper(student[k].surname[0]);
                if (islower(student[k].name[0]))
                    student[k].name[0] = toupper(student[k].name[0]);
                if (islower(student[k].patronymic[0]))
                    student[k].patronymic[0] = toupper(student[k].patronymic[0]);
                fprintf(IOFile, "�������: %hs %hs %hs\n����: %s\n������: %s\nE-mail: %s\n\n", student[k].surname, student[k].name, student[k].patronymic, student[k].course, student[k].group, student[k].email);
            }
            fclose(IOFile);
            printf("���� ���������� ������ � ����...\n������ ������� ���������.\n\n");
            printf("�������� ��������:\n1) �������� ��������;\n2) ������� ������ ���������;\n3) �������� ������ ���������;\n4) �������� ������� ����;\n0) ����� �� ���������.\n\n");
        }
        break;
        case 2:
        {
            IOFile = fopen(filename, "rt");
            while (!feof(IOFile))
            {
                fgets(line, 128, IOFile);
                if (!feof(IOFile))
                    puts(line);
            }
            fclose(IOFile);
            printf("�������� ��������:\n1) �������� ��������;\n2) ������� ������ ���������;\n3) �������� ������ ���������;\n4) �������� ������� ����;\n0) ����� �� ���������.\n\n");
        }
        break;
        case 3:
        {
            IOFile = fopen(filename, "wt");
            printf("������ ������� ������.\n\n");
            printf("�������� ��������:\n1) �������� ��������;\n2) ������� ������ ���������;\n3) �������� ������ ���������;\n4) �������� ������� ����;\n0) ����� �� ���������.\n\n");
        }
            fclose(IOFile);
            break;
        case 4:
            check_file = 1;
            printf("�������� ����� ����:\n1) ������� ����;\n2) ������� ����;\n0) ����� �� ���������.\n\n");
            do
            {
                scanf("%d", &operation1);
                printf("������ ����� %d.\n\n", operation1);
                switch (operation1)
                {
                case 1:
                    printf("������� ���� � ���������� ����� (� ������� ����:/�����/���_�����.���������� �����): \n");
                    scanf("%s", filename);
                    IOFile = fopen(filename, "r+t");
                    if (IOFile == 0)
                    {
                        printf("���� �� ������.\n\n");
                        printf("�������� ����� ����:\n1) ������� ����;\n2) ������� ����;\n0) ����� �� ���������.\n\n");
                        check_file = 0;
                    }
                    else
                    {
                        printf("���� ������.\n\n");
                        check_file = 1;
                    }
                    fclose(IOFile);
                    break;
                case 2:
                    printf("������� ���� � ������������ ����� (� ������� ����:/�����/���_�����.���������� �����): \n");
                    scanf("%s", filename);
                    IOFile = fopen(filename, "a+t");
                    printf("���� ������.\n\n");
                    fclose(IOFile);
                    check_file = 1;
                    break;
                case 0:
                    return 0;
                default:
                    printf("������! \n\n�������� ����� ����:\n1) ������� ����;\n2) ������� ����;\n0) ����� �� ���������.\n\n");
                }
                if (check_file == 1)
                    break;
            } while (operation1 != 1 || operation1 != 2);
            printf("�������� ��������:\n1) �������� ��������;\n2) ������� ������ ���������;\n3) �������� ������ ���������;\n4) �������� ������� ����;\n0) ����� �� ���������.\n\n");
            break;
        case 0:
            return 0;
        default:
            printf("������!\n\n�������� ��������:\n1) �������� ��������;\n2) ������� ������ ���������;\n3) �������� ������ ���������;\n4) �������� ������� ����;\n0) ����� �� ���������.\n\n");
            break;
        }
    } while (operation2 != 0);
    return 0;
}
