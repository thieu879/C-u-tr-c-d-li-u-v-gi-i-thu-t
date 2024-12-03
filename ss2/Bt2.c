#include <stdio.h>

int FindNumberOfElement(int arr[], int x, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    printf("Nh?p s? lu?ng ph?n t? n: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Nh?p ph?n t? th? %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Nh?p s? c?n tìm x: ");
    scanf("%d", &x);

    int count = FindNumberOfElement(arr, x, n);
    printf("S? l?n xu?t hi?n c?a %d là: %d\n", x, count);

    return 0;
}

