#include <stdio.h>

int main()
{
    int n;
    printf("Nh?p s? lu?ng ph?n t? c?a m?ng n: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Nh?p ph?n t? th? %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("M?ng sau khi d?o ngu?c: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

