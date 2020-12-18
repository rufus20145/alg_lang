#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <locale.h>


void clearArray(char *array, int arraySize)
{

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '\0';
    }
}

void enter_name(char *text, int i, unsigned char *array)
{
    setlocale(LC_ALL, "Russian");
    int check = 0;
    do
    {

        check = 0;
        printf("Введите %s студента №%d: ", text, i + 1);
        scanf("%s", array);
        // enterArray(array);
        // fflush(stdin);
        // fgets((char *)array, 30, stdin);
        for (size_t j = 0; j < strlen(array); j++)
        {
            if (isalpha(array[j]))
            {
            }
            else
            {

                check++;
                printf("Ошибка! Попробуйте еще раз.\n");
                clearArray(array, 40);
                // break;
            }
        }
    } while (check != 0);
}

void enter_course(int i, char *array)
{
    int check = 0;
    do
    {
        check = 0;
        printf("Введите номер курса студента №%d: ", i + 1);
        scanf("%s", array);
        for (size_t j = 0; j < strlen(array) - 1; j++)
        {
            if (isdigit(array[j]))
            {
            }
            else
            {
                check++;
                printf("Ошибка! Попробуйте еще раз.\n");
                break;
            }
        }
    } while (check != 0);
}

void enter_group(int i, char *array)
{
    int check = 0;
    do
    {
        check = 0;
        printf("Введите название группы студента №%d: ", i + 1);
        scanf("%s", array);
        for (size_t j = 0; j < strlen(array) - 1; j++)
        {
            if (isalpha(array[0]) && isdigit(array[1]) && isalpha(array[2]) && isdigit(array[4]) && isdigit(array[5]) && isdigit(array[6]) && isalpha(array[7]) && isdigit(array[9]) && isdigit(array[10]))
            {
            }
            else
            {
                check++;
                printf("Ошибка! Попробуйте еще раз.\n");
                break;
            }
        }
    } while (check != 0);
}

void enter_email(int i, char *array)
{
    int check = 0;
    do
    {
        check = 0;
        printf("Введите e-mail студента №%d: ", i + 1);
        scanf("%s", array);
        char string_email = strlen(array);
        if ((array[0] != '@') && (array[string_email - 1] != '@') && (array[string_email - 2] != '@') && ((array[string_email - 3] == '.') || (array[string_email - 4] == '.')) && (array[string_email - 4] != '@'))
        {
        }
        else
        {
            check++;
            printf("Ошибка! Попробуйте еще раз.\n");
        }
    } while (check != 0);
}

int input(char text[20], int min, int max)
{
    int A;
    do
    {
        printf("Введите %s (от %i до %i): ", text, min, max);
        scanf("%i", &A);
        if (A > max || A < min)
            printf("Ошибка! ");
    } while (A > max || A < min);
    return A;
}

void swap(int *a, int *b)
{
    int buf;
    buf = *a;
    *a = *b;
    *b = buf;
}

#endif // FUNCTION_H_INCLUDED
