/**
 * @file functions.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief файл с различными функциями, используемыми в 5 ПЗ
 * @version 0.1
 * @date 2020-11-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

/**
 * @brief функция ввода имени или создания нового файла
 * 
 * @return int код ошибки (0 нет ошибки, 1 есть ошибка)
 */
int chooseFie(char* fileName)
{
    FILE* currFile = NULL;
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
            fclose(currFile);
            printf("Файл успешно создан.\n");
            return 0;
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
        printf("Незивестная операция. Повторите попытку.\n");
        return 1;
        break;
    }
    }
}