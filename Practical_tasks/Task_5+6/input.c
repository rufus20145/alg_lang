#ifndef INPUT
#define INPUT
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

#include <stdio.h>

#define MAXSIZE 256

/**
 * @brief функция ввода ФИО и номера группы
 * 
 * @param array массив, куда класть введенные данные
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
 * @brief функция для очистки массива
 * 
 * @param array - массив для очистки
 */
void clearArray(char *array, int arraySize)
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
int chooseFile(char *fileName)
{
    FILE *currFile = NULL;
    char action;
    
    printf("Выберите пункт меню:\n1)Выбрать существующий файл.\n2)Создать новый файл/очистить существующий.\n");
    action = getchar();
    fflush(stdin);
    switch (action)
    {
    case '1': //выбор существующего файла
    {
        printf("Введите имя существующего файла: ");
        enterCredential(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            printf("Ошибка открытия файла. Повторите попытку.\n");
            return 1;
        }
        else
        {
            currFile = fopen(fileName, "r");
            printf("Файл успешно найден.\n");
            fclose(currFile);
            return 0;
        }
        break;
    }
    case '2': //создание нового файла
    {
        printf("Введите имя файла, который необходимо создать: ");
        enterCredential(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            currFile = fopen(fileName, "w");
            if (NULL == currFile)
            {
                printf("Ошибка создания файла. Повторите попытку.\n");
                return 1;
            }
            else
            {
                fclose(currFile);
                printf("Файл успешно создан.\n");
                return 0;
            }
        }
        else
        {
            printf("Такой файл уже существует, нажмите 1, если вы хотите очистить его, иначе любую другю клавишу.\n");
            if (getchar() == '1')
            {
                currFile = fopen(fileName, "w");
                fclose(currFile);
                fflush(stdin);
                printf("Файл успешно очищен.\n");
                return 0;
            }
            else
            {
                currFile = fopen(fileName, "r");
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
        printf("\nНезивестная операция. Повторите попытку.\n");
        return 1;
        break;
    }
    }
}
#endif // !INPUT