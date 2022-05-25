/* 2.5 upper triangular matrix */
/* 1. try to store upper triangular matrix A to an single array B (1: n(n+1/2)) with more efficient way
 * 2. output the array and bring matrix A back
*/
#include <stdio.h>
#define ROW_A 4
#define COL_A 4
#define ROW_B 1
#define COL_B ROW_A*(ROW_A + 1) / 2

void recoverUpperTriangularMatrix(int array[ROW_B][COL_B], int array2[ROW_A][COL_A])
{
    int i, j, k = 0;
    for (i = 0; i < ROW_A; i++)
        for (j = i; j < COL_A; j++)
        {
            array2[i][j] = array[0][k];
            k++;
        }
}

void transformUpperTriangularMatrixToArray(int array[ROW_A][COL_A], int array2[ROW_B][COL_B])
{
    int i, j, k = 0;
    for (i = 0; i < ROW_A; i++)
        for (j = i; j < COL_A; j++)
            {
                array2[0][k] = array[i][j];
                k++;
            }
}

void printMatrix(int row, int column, int array[row][column])
{
    int i, j;
    printf("=========== Start Line ===========\n");
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            printf("Row: %d, Column: %d, Value: %d\n", i, j, array[i][j]);
    printf("============ End Line ===========\n");
}

int main (int argc, char **argv)
{
    int A[ROW_A][COL_A] ={
        {1, 2, 2, 3},
        {0, 1, 2, 2},
        {0, 0, 1, 2},
        {0, 0, 0, 1},
    };
    
    /* n 4, so B = 4(4+1)/2 = 10 */
    int B[ROW_B][COL_B] = {};

    /* store back to C as a upper traingular matrix */
    int C[ROW_A][ROW_A] = {};

    transformUpperTriangularMatrixToArray(A, B);
    printMatrix(ROW_B, COL_B, B);
    recoverUpperTriangularMatrix(B, C);
    printMatrix(ROW_A, ROW_A, C);
    return 0;  
}
