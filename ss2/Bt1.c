#include <stdio.h>

void searchMaxNumber(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("S? l?n nh?t là: %d\n", max);
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

    int size = sizeof(arr) / sizeof(arr[0]);
    searchMaxNumber(arr, size);
    return 0;
}

