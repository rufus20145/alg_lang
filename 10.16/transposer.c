
void transposeMatrix(int **matrix, int matrixHeight, int matrixLength)
{
    int tempSize;
    if (matrixHeight > matrixLength)
        tempSize = matrixHeight;
    else
        tempSize = matrixLength;
    for (int i = 0; i < tempSize - 1; i++) //идём по строкам
    {
        for (int j = i + 1; j < tempSize; j++) //идём по столбцам
        {
            swapNumbers(matrix[i][j], matrix[j][i], &matrix[i][j], &matrix[j][i]);
        }
    }
}