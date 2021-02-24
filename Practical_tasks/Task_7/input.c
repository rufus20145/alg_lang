#include <stdio.h>
#include <wchar.h>
#include <string.h>

/**
 * @file input.c
 * @author your name (you@domain.com)
 * @brief файл с функциями ввода и очистки массива
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAXSIZE 256

/**
 * @brief функция ввода ФИО и номера группы
 * 
 * @param array массив, куда класть введенные данные
 * @return void
 */
void enterCredential(wchar_t *array)
{
    wchar_t buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = fgetwc(stdin);
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
 * @brief функция для очистки массива
 * 
 * @param array - массив для очистки
 */
void clearArray(wchar_t *array, int arraySize)
{

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = '\0';
    }
}

/**
 * @brief функция ввода имени или создания нового файла
 * 
 * @return int код ошибки (0 нет ошибки, 1 есть ошибка)
 */
int chooseFile(wchar_t *fileName)
{
    wchar_t string[MAXSIZE];
    char tempStr[MAXSIZE] = "Выберите пункт меню:\n1)Выбрать существующий файл.\n2)Создать новый файл/очистить существующий.\n";
    for (int i = 0; i < (int)strlen(tempStr); i++)
    {
        string[i] = btowc(tempStr[i]);
    }
    
    FILE *currFile = NULL;
    char action;
    fputws(string, stdout);
    action = getchar();
    fflush(stdin);
    switch (action)
    {
    case '1': //выбор существующего файла
    {
        wprintf((wchar_t *)"Введите имя существующего файла: ");
        enterCredential(fileName);
        if (fopen((char *)fileName, "r") == NULL)
        {
            wprintf((wchar_t *)"Ошибка открытия файла. Повторите попытку.\n");
            return 1;
        }
        else
        {
            currFile = fopen((char *)fileName, "r");
            wprintf((wchar_t *)"Файл успешно найден.\n");
            fclose(currFile);
            wprintf((wchar_t *)"File received: %s\n", fileName);
            return 0;
        }
        break;
    }
    case '2': //создание нового файла
    {
        wprintf((wchar_t *)"Введите имя файла, который необходимо создать: ");
        enterCredential(fileName);
        if (fopen((char *)fileName, "r") == NULL)
        {
            currFile = fopen((char *)fileName, "w");
            fputs("matrix", currFile);
            fclose(currFile);
            wprintf((wchar_t *)"Файл успешно создан.\n");
            return 0;
        }
        else
        {
            printf("Такой файл уже существует, нажмите 1, если вы хотите очистить его, иначе любую другую клавишу.\n");
            if (getchar() == '1')
            {
                currFile = fopen((char *)fileName, "w");
                fclose(currFile);
                fflush(stdin);
                printf("Файл успешно очищен.\n");
                return 0;
            }
            else
            {
                currFile = fopen((char *)fileName, "r");
                fclose(currFile);
                fflush(stdin);
                printf("Файл не был очищен.\n");
                return 0;
            }
        }
        break;
    }
    default: //введен другой символ
    {
        // system("cls");
        printf("Неизвестная операция. Повторите попытку.\n");
        return 1;
        break;
    }
    }
}
