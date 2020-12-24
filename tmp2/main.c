#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

#define M 30
#define NUM_ST 15
#define result 256
#define MIN_M 1
#define MAX_M 10
#define MIN_E 0
#define MAX_E 50

void enterArray(char *array)
{
    char buff;
    for (int i = 0; i < M; i++)
    {
        buff = getchar();
        if (buff == '\n')
        {
            array[i] = ' ';
            break;
        }
        else
            array[i] = buff;
    }
}

void clearArray(char *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        array[i] = '\0';
}

int checkArray(char *array)
{
    int size = strlen(array);
    size--;
    for (int i = 0; i < size; i++)
    {
        if (!isalpha(array[i]))
        {
            printf("Ошибка1. Повторите попытку ");
            clearArray(array, M);
            return 0;
        }
    }
    array[0] = toupper(array[0]);
    return 1;
}

void printArray(char *array)
{
    int size = strlen(array);
    for (int i = 0; i < size; i++)
        printf("%c", array[i]);
    if (array[size - 1] != '\n')
        printf("\n");
}

void eGroup(char *group)
{
    for (int i = 0; i < M; i++)
    {
        group[i] = getchar();
        if (group[i] == '\n')
        {
            group[i] = ' ';
            break;
        }
    }
}

int checkEmail(char *array)
{
    int fs = 0, at = 0, q = 0;
    int size = strlen(array);
    for (int i = 0; i < size; i++)
    {
        if (array[i] == '@')
        {
            at++;
        }
    }
    if (at == 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == '@')
                q = i + 1;
        }
        if ((size - q) < 5)
        {
            printf("Ошибка2. Повторите попытку ");
            clearArray(array, M);
            return 1;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (array[i] == '.')
                    fs++;
            }
            if (fs == 1)
                return 0;
            else
            {
                printf("Ошибка3. Повторите попытку ");
                clearArray(array, M);
                return 1;
            }
        }
    }
    else
    {
        printf("Invalid %d", at);
        return 1;
    }
}

int change(int *a1, int *b1)
{
    int buf;
    buf = *a1;
    *a1 = *b1;
    *b1 = buf;
    return 0;
}
int main()
{
    char massive[result] = "";
    // char Line[128] = "";
    struct St_Struct
    {
        char F[M];
        char I[M];
        char O[M];
        char group[M];
        char mail[M];
        char mass[M];
    };
    struct St_Struct Students[NUM_ST];
    for (int i = 0; i < NUM_ST; i++)
    {
        clearArray(Students[i].F, M);
        clearArray(Students[i].I, M);
        clearArray(Students[i].O, M);
        clearArray(Students[i].group, M);
        clearArray(Students[i].mail, M);
    }

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int oper, oper2, num;
    int ch = 0;
    int check;
    char fname[255];

    printf("[1] - Создать файл \n[2] - Открыть файл \n");
    FILE *qq;
    do
    {
        scanf("%d", &oper);
        switch (oper)
        {
        case 1:
            printf("Введите имя нового файла: ");
            scanf("%s", &fname);
            qq = fopen(fname, "w");
            printf("Файл создан\n");
            fclose(qq);
            ch = 0;
            break;
        case 2:
            printf("Укажите имя файла\n");
            scanf("%s", &fname);
            qq = fopen(fname, "r");
            if (qq == NULL)
            {
                printf("Файл не найден. Повторите попытку\n");
                printf("[1] - Создать файл \n[2] - Открыть файл \n");
                ch = 1;
            }
            else
            {
                printf("Файл найден\n");
                ch = 0;
            }
            fclose(qq);
            break;
        default:
            printf("Ошибка. Повторите попытку\n[1] - Создать файл \n[2] - Открыть файл \n");
            ch = 1;
        }
        if (ch == 0)
            break;
    } while (oper != 1 || oper != 2);
    int R;
    do
    {
        printf("Введите размерность массива от %d до %d: ", MIN_M, MAX_M);
        scanf("%d", &R);
        if (R > MAX_M || R < MIN_M)
            printf("Число должно быть от %d до %d\n", MIN_M, MAX_M);
    } while (R > MAX_M || R < MIN_M);
    int mas[R];
    for (int i = 0; i < R; i++)
    {
        do
        {
            printf("Введите %d элемент массива от %d до %d: ", i + 1, MIN_E, MAX_E);
            scanf("%d", &mas[i]);
            if (mas[i] > MAX_E || mas[i] < MIN_E)
                printf("Число должно быть от %d до %d\n", MIN_E, MAX_E);
        } while (mas[i] > MAX_E || mas[i] < MIN_E);
    }
    do
    {
        check = 0;
        for (int i = 0; i < R - 1; i++)
        {
            if (mas[i] > mas[i + 1])
            {
                check++;
                change(&mas[i], &mas[i + 1]);
            }
        }
    } while (check > 0);
    printf("Отсортированный массив\n");
    for (int i = 0; i < R; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");

    qq = fopen(fname, "a");
    if (qq == NULL)
        printf("Err\n");
    else
    {
        fprintf(qq, "Отсортированный массив: ");
        for (int i = 0; i < R; i++)
        {
            fprintf(qq, "%d ", mas[i]);
        }
        fprintf(qq, "\n");
    }
    fclose(qq);

    printf("[1] - Добавить студента \n[2] - Вывести список студентов \n[3] - Очистить файл \n[0] - Выход \n");
    do
    {
        scanf("%d", &oper2);

        switch (oper2)
        {
        case 1:
            do
            {
                printf("Введите количество добавляемых студентов: ");
                scanf("%d", &num);
                fflush(stdin); // Очистка буфера ввода
                if (num > NUM_ST || num < 1)
                    printf("Ошибка 4. Повторите попытку \n");
            } while (num > NUM_ST || num < 1);

            for (int i = 0; i < num; i++)
            {
                printf("Введите фамилию %d-го студента: ", i + 1);
                do
                {
                    enterArray(Students[i].F);
                } while (checkArray(Students[i].F) == 0);
                printf("Введите имя: ");
                do
                {
                    enterArray(Students[i].I);
                } while (checkArray(Students[i].I) == 0);
                printf("Введите отчество: ");
                do
                {
                    enterArray(Students[i].O);
                } while (checkArray(Students[i].O) == 0);
                strcat(massive, "Студент: ");
                strcat(massive, Students[i].F);
                strcat(massive, Students[i].I);
                strcat(massive, Students[i].O);
                printf("Введите группу: ");
                eGroup(Students[i].group);
                while (!isalpha(Students[i].group[0]) || !isdigit(Students[i].group[1]) || !isalpha(Students[i].group[2]) || !isdigit(Students[i].group[4]) || !isdigit(Students[i].group[5]) || !isdigit(Students[i].group[6]) || !isalpha(Students[i].group[7]) || !isdigit(Students[i].group[9]) || !isdigit(Students[i].group[10]))
                {
                    clearArray(Students[i].group, M);
                    printf("Ошибка5. Повторите попытку\n");
                }
                strcat(massive, "Группа: ");
                strcat(massive, Students[i].group);
                printf("Введите почту: ");
                do
                {
                    enterArray(Students[i].mail);
                } while (checkEmail(Students[i].mail) == 1);
                strcat(massive, "Почта: ");
                strcat(massive, Students[i].mail);
                strcat(massive, "\n");
            }
            qq = fopen(fname, "a");
            fprintf(qq, massive);

            fclose(qq);
            clearArray(massive, result);
            printf("[1] - Добавить студента \n[2] - Вывести список студентов \n[3] - Очистить файл \n[0] - Выход \n");
            break;
        case 2:
            printf("Список студентов:\n");
            char str[result];
            qq = fopen(fname, "r");
            while (!feof(qq))
            {
                fgets(str, result, qq);
                if (!feof(qq))
                {
                    printArray(str);
                }
            }
            fclose(qq);
            printf("[1] - Добавить студента \n[2] - Вывести список студентов \n[3] - Очистить файл \n[0] - Выход \n");
            break;
        case 3:
            qq = fopen(fname, "w");
            fclose(qq);
            printf("Файл очищен\n");
            printf("[1] - Добавить студента \n[2] - Вывести список студентов \n[3] - Очистить файл \n[0] - Выход \n");
            break;
        case 0:
            return 0;
        default:
            printf("Ошибка 6.Повторите попытку\n[1] - Добавить студента \n[2] - Вывести список студентов \n[3] - Очистить файл \n[0] - Выход \n");
            break;
        }
    } while (oper2 != 0);

    return 0;
}
