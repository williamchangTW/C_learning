/* 2.6 magic array */
/*
 * introduction:
 * Git an array with odd edge that satisfies following condition
 * - the sum in every row, column and diagonal is the same
 * 
 * Fill empty array start from 1, and in diagonal place fill with the square until the array is full.
*/
#include <stdio.h>
#include <math.h>

// code from book
/*
void Magic()
{
    int i, j, p, q, key;

    // initial a empty array
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            Square[i][j] = 0;
    Square[0][(N - 1) / 2] = 1;
    key = 2;
    i = 0;
    j  = (N - 1) / 2;
    while (key <= N*N)
    {
        p = (i - 1) % N;
        q = (j - 1) % N;
        if ( p < 0 )
            p = N - 1;
        if ( q < 0)
            q = N - 1;
        if ( Square[p][q] != 0)
            i = (i + 1) % N;
        else
        {
            i = p;
            j = q;
        }
        Square[i][j] = key;
        key++;
    }
}
*/

