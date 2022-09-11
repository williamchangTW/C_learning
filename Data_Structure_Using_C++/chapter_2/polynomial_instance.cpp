/* 2.8 addition of polynomial */
#include <iostream>
#include <iomanip>
#define DUMMY-1

using namespace std;
void outputP(int [], int);
void Padd(int [], int [], int []);
char compare(int, int);

int main()
{
    int A[] = {DUMMY, 3, 4, 5, 2, 3, 0, 2};
    int B[] = {DUMMY, 3, 3, 6, 2, 2, 0, 1};
    int C[13] = {DUMMY};

    Padd(A, B, C);
    cout << "A = ";
    outputP(A, A[1]*2 + 1);
    cout << "\nB = ";
    outputP(B, B[1]*2 + 1);
    cout << "\nC = ";
    outputP(C, C[1]*2 + 1);
    cout << "\n";
    return 0;
}
