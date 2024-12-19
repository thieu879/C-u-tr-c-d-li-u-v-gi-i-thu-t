#include<stdio.h>
void findSmallestNumber(int arr[], int size)
{
    int i;
    int min = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i]<min)
        {
            min = arr[i];
        }
    }
    printf("s? nh? nh?t là: %d", min);
}
int main()
{
    int n, i;
    printf("Nh?p n:");
    scanf("%d", &n);
    int arr[n];
    printf("Nh?p các ph?n t? vào m?ng: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    findSmallestNumber(arr, n);

    return 0;
}
