#include <stdio.h>
#include <string.h>

void firstTestFunction(char *array)
{
    printf("Entered first test function with string: %s\nStart of changing string.\n", array);

    array[0] = 'a'; //��� char* �� ��������
    printf("%s\n", array);

    strcpy(array, "Second string"); //��� char* �� ��������
    printf("%s\n", array);

    array = "Third string";
    printf("%s\n", array);

    printf("Leaved first test function.\n");
}

int main()
{
    char *buffer1 = "char*";
    char buffer2[64] = "char[]";
    char buffer3[] = "123";

    // buffer1[0]= 'a';
    // buffer2[0] = 'a';
    // printf("1: %s, 2: %s\n", buffer1, buffer2);

    // buffer1 = "NEWSTRING";        //�������� ��� char *
    // buffer2 = "NEWSTRING";        //
    // strcpy(buffer2, "NEWSTRING"); //�������� ��� ������ ��������
    // printf("1: %s, 2: %s\n", buffer1, buffer2);

    // strcpy(buffer1, "LASTSTRING");//�� �������� ��-�� ���������� � ���� char*
    // printf("2: %s", buffer1);

    // firstTestFunction(buffer1);
    firstTestFunction(buffer2);
    return 0;
}