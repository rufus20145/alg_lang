#include <stdio.h>

#define MAXSIZE 256

/**
 * @brief функция проверки наличия заголовка в файле
 * 
 * @param fileName имя файла
 * @return int код ошибки (0 - нет ошибки, 1 - заголовка нет)
 */
int checkFile(wchar_t *fileName)
{
    // printf("File 123recieved: %s\n", fileName);
    FILE *currFile = NULL;
    char buffer[MAXSIZE] = "", refString[MAXSIZE] = "matrix";

    currFile = fopen((char *)fileName, "r");
    fflush(stdin);
    fgets(buffer, 7, currFile);
    if (!strcmp(buffer, refString))
    {
        printf("Матрица найдена.\n");
        fclose(currFile);
        return 0;
    }
    else
    {
        fclose(currFile);
        return 1; //поменять на 1
    }
}
