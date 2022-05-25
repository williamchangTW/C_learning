/* 2.3 multiply two matrix */
#include <stdio.h>

void multiplyMatrix(int val1, int val2, int A[val1][val2], int B[val2][val1], int C[val1][val1])
{
    int i, j, k;
    int bound = val1 > val2 ? val2 : val1;
        
    // multiply every element of A and B to C
    for (i = 0; i < val1; i++)
        for (j = 0; j < bound; j++)
        {
            for ( k = 0; k < val2; k ++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
}

void printMatrix(int row, int column, int array[row][column])
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j =0; j < column; j++)
        {
            printf("Row: %d Column: %d value %d\n", i, j ,array[i][j]);
        }
}

int main(int argc, char **argv)
{
    // refer the example from book
    int A[][3] = {
        {2, 1, -3},
        {-2, 2, 4}
    };
    int B[][2] ={
        {-1, 2},
        {0, -3},
        {2, 1}
    };
    int C[2][2] = {};
    multiplyMatrix(2, 3, A, B, C);
    printMatrix(2, 2, C);

    return 0;
}