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
 * @brief функция ввода числа с проверкой ввода
 * 
 * @param *number указатель на число в вызывающей функции
 * @return int код ошибки
 */
int enterNumber(int *number)
{
    char buffer[MAXSIZE] = "";
    fgets(buffer, MAXSIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    int bufferLength = strlen(buffer);
    if (bufferLength && strcmp(buffer, "-")) 
    {
        for (int i = 0; i < bufferLength; i++)
        {
            if (!isdigit(buffer[i]) && buffer[i] != '-')
            {
                printf("Ошибка! Во вводе обнаружены символы, отличные от цифр.\n");
                return 1; //ошибка, в строке есть не только цифры
            }
        }
        *number = atoi(buffer);
        return 0;
    }
    else
    {
        printf("Вы не ввели ни одного символа, повторите попытку. ");
        return 1;
    }
}

/**
 * @brief функция ввода ФИО и номера группы
 * 
 * @param array массив, куда класть введенные данные
 * @return void
 */
void enterArray(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAXSIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
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
 * @brief функция ввода имени существующего или создания нового файла
 * 
 * @return int код ошибки (0 нет ошибки, 1 есть ошибка, 2 ввод отменён)
 */
int chooseFile(char *fileName)
{
    FILE *currFile = NULL;
    int action;
    int inputErrorCode = 0;

    printf("1)Выбрать существующий файл.\n2)Создать новый файл/очистить существующий.\n0)Выход из режима добавления файла\n");
    do
    {
        inputErrorCode = enterNumber(&action);
    } while (inputErrorCode == 1);
    switch (action)
    {
    case 1: //выбор существующего файла
    {
        printf("Введите имя существующего файла: ");
        enterArray(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            printf("Файл не найден. Повторите попытку.\n");
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
    case 2: //создание нового файла
    {
        printf("Введите имя файла, который необходимо создать: ");
        enterArray(fileName);
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
                char refString[MAXSIZE / 4] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
                fputs(refString, currFile);
                fclose(currFile);
                printf("Файл успешно создан. База данных инициализирована.\n");
                return 0;
            }
        }
        else
        {
            printf("Такой файл уже существует, нажмите 1, если вы хотите очистить его, иначе любую другю клавишу.\n");
            if (getchar() == '1')
            {
                currFile = fopen(fileName, "w");
                char refString[MAXSIZE / 4] = "0;Surname;Name;MiddleName;Group;Day;Month;Year;E-mail\n";
                fputs(refString, currFile);
                fclose(currFile);
                fflush(stdin);
                printf("Файл успешно очищен. База данных инициализирована.\n");
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
    case 0:
    {
        printf("Выбор файла отменён.\n");
        return 2;
    }
    default: //введен другой символ
    {
        printf("\nНезивестная операция. Повторите попытку.\n");
        return 1;
        break;
    }
    }
}
#endif // !INPUT