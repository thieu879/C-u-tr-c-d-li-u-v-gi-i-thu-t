#include<stdio.h>
void findLargestNumber(int arr[], int size){
    int i;
    int max = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    printf("s? l?n nh?t là: %d", max);
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
    findLargestNumber(arr, n);

    return 0;
}
