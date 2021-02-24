#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//функция считывания номера строки
int input()
{
    int a;
    printf("Enter line number: ");
    while (scanf("%d", &a) != 1)
    {
        printf("Try again.\nEnter line number: ");
        while (getchar() != '\n')
            ; //шо це
    }
    return a;
}

int main()
{
    char File[2048], Line[256], value;
    int i = 0, func = 0;
    float S = 0;
    FILE *IOFile;
    printf("Enter path to file: ");
    scanf("%s", File);

    do
    {
        printf("Do you want to take a look at the file?(yes-1, no-0): ");
        scanf("%d", &func);
        switch (func)
        {
        case 1:
        {
            IOFile = fopen(File, "r");
            while (!feof(IOFile))
            {
                fgets(Line, 256, IOFile);
                if (!feof(IOFile))
                    puts(Line);
            }
            fclose(IOFile);
        }
        break;

        case 0:
        {
        }
        break;

        default:
            printf("Error.Try again.\n");
            break;
        }
        if (func == 0 || func == 1)
            break;
    } while (func != 0 || func != 1);

    int k = input();
    getchar();

    printf("Enter value: ");
    scanf("%c", &value);
    IOFile = fopen(File, "r");
    do
    {
        fgets(Line, 256, IOFile);
        i++;
        printf("1");
        if (!feof(IOFile) && i == k)
        {
            printf("2");
            for (int j = 0; j < (int)(strlen(Line) - 1); j++)
            {
                if (Line[j] == value)
                    S++;
                printf("3");
            }
        }
        if (k != i)
        {
            strcpy(Line, "");
        }
    } while ((i != k) && !feof(IOFile));

    if (strlen(Line) == 0)
    {
        printf("%s", Line);
        printf("str:%d\n", (int)(strlen(Line)));
        printf("This line does not exist in the file.\n");
        fclose(IOFile);
    }
    else
    {
        printf("str:%d\n", (int)(strlen(Line)));
        printf("Relative number of characters: %.2f;\nHow much chars: %.0f;\n", S / (strlen(Line)), S);
        fclose(IOFile);
    }
    return 0;
}
