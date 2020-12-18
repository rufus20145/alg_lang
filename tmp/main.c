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
    n=input("количество строк", 2, 5);
    m=input("количество столбцов", 2, 5);
    int matrix[n][m];
    printf("\n");
        for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
        do {
            printf("Введите элемент [%d][%d] (от -100 до 100): ", i, j);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j]>100||matrix[i][j]<-100)
                printf("Ошибка! ");
        } while (matrix[i][j]>100||matrix[i][j]<-100);
        }
    }
    printf("\n");
    printf("Оригинальная матрица:\n");
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

    printf("Упорядоченная матрица:\n");
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
            printf("Элемент [%d][%d] = %d\n", i, j, matrix[i][j]);
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

    printf("Выберите пункт меню:\n1) Открыть файл;\n2) Создать файл;\n0) Выйти из программы.\n\n");
    do
    {
        scanf("%d", &operation1);
        printf("Выбран пункт %d.\n\n", operation1);
        switch (operation1)
        {
        case 1:
            printf("Укажите путь к выбранному файлу (в формате ДИСК:/Папка/Имя_файла.расширение файла): \n");
            scanf("%s", filename);
            IOFile = fopen(filename, "r+t");
            if (IOFile == 0)
            {
                printf("Файл не найден.\n\n");
                printf("Выберите пункт меню:\n1) Открыть файл;\n2) Создать файл;\n0) Выйти из программы.\n\n");
                check_file = 0;
            }
            else
            {
                printf("Файл найден.\n\n");
                check_file = 1;
            }
            fclose(IOFile);
            break;
        case 2:
            printf("Задайте путь к создаваемому файлу (в формате ДИСК:/Папка/Имя_файла.расширение файла): \n");
            scanf("%s", filename);
            IOFile = fopen(filename, "a+t");
            printf("Файл создан.\n\n");
            fclose(IOFile);
            check_file = 1;
            break;
        case 0:
            return 0;
        default:
            printf("Ошибка! \n\nВыберите пункт меню:\n1) Открыть файл;\n2) Создать файл;\n0) Выйти из программы.\n\n");
        }
        if (check_file == 1)
            break;
    } while (operation1 != 0);
    printf("Выберите действие:\n1) Добавить студента;\n2) Вывести список студентов;\n3) Очистить список студентов;\n4) Изменить рабочий файл;\n0) Выйти из программы.\n\n");
    do
    {
        scanf("%d", &operation2);
        printf("Выбрано действие %d.\n\n", operation2);
        switch (operation2)
        {
        case 1:
        {
            do
            {
                printf("Введите количество добавляемых студентов (от 1 до 20): ");
                scanf("%d", &number);
            } while (isalpha(number) || number < 1 || number > 20);
            fflush(stdin);
            printf("\n");
            for (i = 0; i < number; i++)
            {
                enter_name("фамилию", i, student[i].surname);
                enter_name("имя", i, student[i].name);
                enter_name("отчество", i, student[i].patronymic);
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
                fprintf(IOFile, "Студент: %hs %hs %hs\nКурс: %s\nГруппа: %s\nE-mail: %s\n\n", student[k].surname, student[k].name, student[k].patronymic, student[k].course, student[k].group, student[k].email);
            }
            fclose(IOFile);
            printf("Идет добавление записи в файл...\nЗапись успешно добавлена.\n\n");
            printf("Выберите действие:\n1) Добавить студента;\n2) Вывести список студентов;\n3) Очистить список студентов;\n4) Изменить рабочий файл;\n0) Выйти из программы.\n\n");
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
            printf("Выберите действие:\n1) Добавить студента;\n2) Вывести список студентов;\n3) Очистить список студентов;\n4) Изменить рабочий файл;\n0) Выйти из программы.\n\n");
        }
        break;
        case 3:
        {
            IOFile = fopen(filename, "wt");
            printf("Список успешно очищен.\n\n");
            printf("Выберите действие:\n1) Добавить студента;\n2) Вывести список студентов;\n3) Очистить список студентов;\n4) Изменить рабочий файл;\n0) Выйти из программы.\n\n");
        }
            fclose(IOFile);
            break;
        case 4:
            check_file = 1;
            printf("Выберите пункт меню:\n1) Открыть файл;\n2) Создать файл;\n0) Выйти из программы.\n\n");
            do
            {
                scanf("%d", &operation1);
                printf("Выбран пункт %d.\n\n", operation1);
                switch (operation1)
                {
                case 1:
                    printf("Укажите путь к выбранному файлу (в формате ДИСК:/Папка/Имя_файла.расширение файла): \n");
                    scanf("%s", filename);
                    IOFile = fopen(filename, "r+t");
                    if (IOFile == 0)
                    {
                        printf("Файл не найден.\n\n");
                        printf("Выберите пункт меню:\n1) Открыть файл;\n2) Создать файл;\n0) Выйти из программы.\n\n");
                        check_file = 0;
                    }
                    else
                    {
                        printf("Файл найден.\n\n");
                        check_file = 1;
                    }
                    fclose(IOFile);
                    break;
                case 2:
                    printf("Задайте путь к создаваемому файлу (в формате ДИСК:/Папка/Имя_файла.расширение файла): \n");
                    scanf("%s", filename);
                    IOFile = fopen(filename, "a+t");
                    printf("Файл создан.\n\n");
                    fclose(IOFile);
                    check_file = 1;
                    break;
                case 0:
                    return 0;
                default:
                    printf("Ошибка! \n\nВыберите пункт меню:\n1) Открыть файл;\n2) Создать файл;\n0) Выйти из программы.\n\n");
                }
                if (check_file == 1)
                    break;
            } while (operation1 != 1 || operation1 != 2);
            printf("Выберите действие:\n1) Добавить студента;\n2) Вывести список студентов;\n3) Очистить список студентов;\n4) Изменить рабочий файл;\n0) Выйти из программы.\n\n");
            break;
        case 0:
            return 0;
        default:
            printf("Ошибка!\n\nВыберите действие:\n1) Добавить студента;\n2) Вывести список студентов;\n3) Очистить список студентов;\n4) Изменить рабочий файл;\n0) Выйти из программы.\n\n");
            break;
        }
    } while (operation2 != 0);
    return 0;
}
