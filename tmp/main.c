#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = NULL, *separatedBuffer = NULL;
    char inputBuffer[256] = "";
    fgets(inputBuffer, sizeof(buffer), stdin);
    buffer = (char *)malloc(strlen(inputBuffer) * sizeof(char));
    separatedBuffer = (char *)malloc(strlen(inputBuffer) * sizeof(char));

    buffer = inputBuffer;
    separatedBuffer = strtok(buffer, "@");
    puts(separatedBuffer);
    separatedBuffer = strtok(NULL, ".");
    puts(separatedBuffer);
    separatedBuffer = strtok(NULL, "\n");
    puts(separatedBuffer);
    printf("End.");
    return 0;
}

/* отошёл */