/*
    файл с операциями над матрицами
*/
int sumMatrix(int **matrix1, int **matrix2, int **resultMatrix, int matrix1Length, int matrix1Height, int matrix2Length, int matrix2Height, int *resultMatrixHeight, int *resultMatrixWidth)
{
    for (int i = 0; i < matrix1Length; i++)
    {
        for (int j = 0; j < matrix1Height; j++)
        {
            printf("EElement[%d][%d] = %d", i, j, matrix1[i][j]);
        }
    }
    return 0;
    // if (matrix1Length == matrix2Length && matrix1Height == matrix2Height)
    // {
    //     for (int i = 0; i < matrix1Length; i++)
    //     {
    //         for (int j = 0; j < matrix1Height; j++)
    //             resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    //     }
    //     *resultMatrixHeight = matrix1Height;
    //     *resultMatrixWidth = matrix1Length;
    //     return 0;//завершено без ошибки
    // }
    // else return -1;//размеры матриц не совпадают
}
// void multiplyMatrix(int **matrix1, int **matrix2, int **resultMatrix, int matrixSize)
// {
// }
