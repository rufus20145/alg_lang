#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    char fileName[256];
    scanf("%s", fileName);
    fflush(stdin);
    if(fopen(fileName, "r") == 0) {
        printf("File wasn`t opened.\n");
        getchar();
    }
    else
    {
        getchar();
    }
    
    return 0;
}