#include <stdio.h>

int SumFromNToM(int n, int m)
{
    if (n == m)
    {
        return n;
    }
    return n + SumFromNToM(n + 1, m);
}

int main()
{
    int n, m;
    printf("Nh?p n: ");
    scanf("%d", &n);
    printf("Nh?p m: ");
    scanf("%d", &m);

    if (n > m)
    {
        printf("n ph?i nh? hon ho?c b?ng m\n");
        return 1;
    }

    int sum = SumFromNToM(n, m);
    printf("T?ng các s? t? %d d?n %d là: %d\n", n, m, sum);

    return 0;
}

