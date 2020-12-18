#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    char firstArray[40] = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
    unsigned char secondArray[40] = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

    
    for (size_t i = 0; i < strlen(firstArray); i++)
    {
        printf("%d ", firstArray[i]);
    }
    printf("\n");

    for (size_t i = 0; i < strlen(secondArray); i++)
    {
        printf("%d ", secondArray[i]);
    }
    printf("\n");

    for (size_t i = 0; i < strlen(firstArray); i++)
    {
        printf("%d ", toUpper(firstArray[i]));
    }
    
    return 0;
}