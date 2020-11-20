#include <stdio.h>

/**
 * @brief функция ввода имени или создания нового файла
 * 
 * @return int код ошибки (0 нет ошибки, 1 есть ошибка)
 */
int chooseFile(char* fileName)
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
            printf("File recieved: %s\n", fileName);
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
            fputs("matrix", currFile);
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