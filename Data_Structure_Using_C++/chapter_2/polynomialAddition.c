/* 2.4 polynomial instance code */
/* Here shows the addition of polynomial 
 * for instance:
 * (2X^2 + 1) + (X^3 - X^2 + 1) = X^3 +2X^2 +2
 * 
 * 8X^3 + 2X^2Y + 2X^2Y^2 + 2XY^2 + Y^3 + 2
 * and store to array shown in the below
 *     Y^0 Y^1 Y^2 Y^3
 * X^0  2 | 0 | 0 | 1
 * X^1  0 | 0 | 2 | 0
 * X^2  0 | 2 | 2 | 0
 * X^3  8 | 0 | 0 | 0
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10


char compare(int x, int y)
{
    if (x == y)
        return '=';
    else if (x > y)
        return '>';
    else
        return '<';
}

void Padd(int a[], int b[], int c[])
{
    int p, q, r, m, n;
    char result;

    m = a[1];
    n = b[1];
    p = q = r =2;
    while ((p <= 2*m) && (q <= 2*n))
    {
        result = compare( a[p], b[q]);
        switch (result)
        {
            /* the exponent of a is equal to b */
            case '=':
                c[ r+1 ] = a[ p+1 ] + b[ q+1 ];
                if ( c[ r+1 ] != 0)
                {
                    c[r] = a[p];
                    r+=2;
                }
                p+=2;
                q+=2;
                break;

            /* the exponent of a is more than b */
            case '>':
                c[ r+1 ] = a[ p+1 ];
                c[r] = a[p];
                p += 2;
                r += 2;
                break;
            
            /* the exponent of a is less that b*/
            case '<':
                c [ r+1 ] = b[ q+1 ];
                c[r] = b[q];
                q+=2;
                r+=2;
                break;
        }
    }

    /* move all the reset of a items to c which means wihtout exponent value */
    while ( p <= 2*m)
    {
        c[ r+1 ] = a[ p+1 ];
        c[r] = a[q];
        q += 2;
        r += 2;
        break;
    }

    /* move all the reset of b items to c which means without exponent value */
    while ( q <= 2*n)
    {
        c[ r+1 ] = b[ p+1 ];
        c[r] = a[q];
        q += 2;
        r += 2;
        break;
    }
    c[1] = r/2 - 1;
}

int main(int argc, char **argv)
{
    /*
    int poly[6][4] = {
        {7, 0, 0, 0},
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 6},
        {8, 0, 0, 0},
    };
    */
    /* allow to user interactive */
    int A[MAXSIZE];
    int i, N, power;
    
    printf("Enter the order of the polynomial\n");
    scanf("%d", &N);
    printf("Enter %d coefficients\n", N + 1);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    

}