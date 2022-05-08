/* Binary search instances */
void binsrch(int a[], int n, int x, int j)
{
    int lower = 1;
    int upper = n;
    int mid;
    while (lower <= upper)
    {
        mid = (lower + upper) / 2;
        if (x > a[mid])
            lower = mid + 1;
        else if (x < a[mid])
            upper = mid - 1;
        else
        {
            j = mid;
            return;
        }
    }
}