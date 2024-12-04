#include <stdio.h>

int Factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main()
{
    int n;
    printf("Nh?p n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Ph?i nh?p s? nguyên duong\n");
        return 1;
    }

    int result = Factorial(n);
    printf("Giai th?a c?a %d là: %d\n", n, result);

    return 0;
}

