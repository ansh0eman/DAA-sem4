#include <stdio.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int getMaxVal(int n, int w[], int v[], int c, int i)
{
    int Vinclude, Vexclude;
    if (i == n || c <= 0)
    {
        return 0;
    }

    if (w[i] <= c)
    {
        Vinclude = v[i] + getMaxVal(n, w, v, c - w[i], i + 1);
        Vexclude = getMaxVal(n, w, v, c, i + 1);
        return Max(Vinclude, Vexclude);
    }
    else
    {
        Vexclude = getMaxVal(n, w, v, c, i + 1);
        return Vexclude;
    }
}

int main()
{
    int n = 5;
    int w[100] = {2, 5, 10, 5};
    int v[100] = {20, 30, 50, 10};
    int capacity = 16;

    printf("The maximum value: %d ", getMaxVal(n, w, v, capacity, 0));
}