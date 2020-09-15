/*
калькулятор различных действий с матрицами

коды ошибок:
0 - нет ошибки
1 - неправильно введён размер матрицы
*/

#include <stdio.h>
#include <output.c>
#define MAX_SIZE 255

int main() {
    short errorCode = 0;
    long linesNum, columnsNum;
    char temp[MAX_SIZE];
    double matrix[MAX_SIZE][MAX_SIZE];
    printf("Enter matrix size:\n");
    do {//ввод размеров матрицы, пока не будет
        scanf("%ld %1s %ld", &linesNum, &temp[1], &columnsNum);
        if(temp[1] != 'x') errorCode = 1;
    } while (!errorCode);
    printf("matrix size is: %ldx%ld\n", linesNum, columnsNum);
    printf("Enter matrix:\n");
    for(int currLine = 0; currLine < linesNum; currLine++) {
        for(int currColumn = 0; currColumn < columnsNum; currColumn++) {
            scanf("%lf", &matrix[currLine][currColumn]);
        }
    }
    printf("Your matrix is:\n");
    printMatrix(linesNum, columnsNum, matrix, errorCode);
    printf("The end.\n");
    return 0;
}