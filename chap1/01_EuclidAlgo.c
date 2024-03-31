#include <stdio.h>

int gcd(int m, int n)
{
    while (n > 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int main()
{
    int gcd1 = gcd(4,6);
    printf("%d ",gcd1);
    return 0;
}