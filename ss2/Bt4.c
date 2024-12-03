#include <stdio.h>

void sortArrayAscending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Nh?p s? ph?n t? n c?a m?ng: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("S? ph?n t? không h?p l?.\n");
        return 1;
    }

    int arr[n];
    printf("Nh?p %d ph?n t? c?a m?ng:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sortArrayAscending(arr, n);

    printf("M?ng sau khi s?p x?p tang d?n:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

