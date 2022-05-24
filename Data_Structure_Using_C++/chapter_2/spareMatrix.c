/* chap 2.3 of practice 1 */
/* store every location if the value is none-zero
 * In ordinary, the zero element > 1/2 then we call it spare matrix
 * give a spare matrix:
 * [ 0 15 0 0 -8 0 ]
 * [ 0 0 6 0 0 0 ]
 * [ 0 0 0 -6 0 0 ]
 * [ 0 0 18 0 0 0 ]
 * [ 0 0 0 0 0 16 ]
 * [72 0 0 0 20 0 ]
 * and named to sm which is two dimentions array
 */
# include <stdio.h>

/* get every zero location in spare matrix */
int SpareMatrixLocation(int row, int column, int array[row][column])
{
    int i, j, temp = 0;

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            if (array[i][j] != 0)
                temp++;
    return temp;
}

/* store every non-zero into another matrix 
 * for instance:
 * array:
 * ---------------------
 * |row    | ... | ... |
 * ---------------------
 * |column | ... | ... |
 * ---------------------
 * |value  | ... | ... |
 * ---------------------
*/
void SpareMatrixPick(int row, int column, int array[row][column], int row2, int column2, int array2[row2][column2])
{
    int i, j, k = 0;
    
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            if (k < column2 && array[i][j] != 0)
            {
                array2[0][k] = i;
                array2[1][k] = j;
                array2[2][k] = array[i][j];
                k++;
            }
}

/* Print the matrix */
void SpareMatrixPrint(int row, int column, int array[row][column])
{
    int i, j;
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int k;
    int spare[6][6] ={
        {0, 15, 0, 0, -8, 0},
        {0, 0, 6, 0,0, 0},
        {0, 0, 0, -6, 0, 0},
        {0, 0, 18, 0, 0,0},
        {0, 0, 0, 0, 0, 16},
        {72, 0, 0, 0, 20, 0}
    };
    k = SpareMatrixLocation(6, 6, spare);

    int sm[3][k];
    SpareMatrixPick(6, 6, spare, 3, k, sm);
    SpareMatrixPrint(3, k, sm);
    return 0;
}