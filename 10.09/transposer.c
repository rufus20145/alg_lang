
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int matrixHeight, int matrixLength)
{
    printf("Entered transposeMatrix function.\n");
    int tempSize;
    if (matrixHeight > matrixLength)
        tempSize = matrixHeight;
    else
        tempSize = matrixLength;
    printf("Completed chhosing the size.\n");
    for (int i = 0; i < tempSize - 1; i++) //идём по строкам
    {
        for (int j = i + 1; j < tempSize; j++) //идём по столбцам
        {
            printf("Entered second cycle.\n");
            swapNumbers(matrix[i][j], matrix[j][i], &matrix[i][j], &matrix[j][i]);
        }
    }
}