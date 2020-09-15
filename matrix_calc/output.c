/*
дополнительный файл с функцией вывода матрицы
*/
#define MAX_SIZE 255
void printMatrix(long linesNum, long columnsNum, double matrix[MAX_SIZE][MAX_SIZE] , int errorCode) {
    if(0 == errorCode) {
        for(int currLine = 0; currLine < linesNum; currLine++) {
            for(int currColumn = 0; currColumn < columnsNum; currColumn++) {
                printf("%.2lf ", matrix[currLine][currColumn]);
            }
            printf("\n");
        }
    }
    else switch (errorCode)
    {
    case '1':
        printf("Error in matrix size");
        break;
    
    default:
        printf("Unknown error.\n");
        break;
    }
}