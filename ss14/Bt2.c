#include<stdio.h>
int bynarySearch(int arr[], int size, int value){
    int low = 0;
    int high = size - 1;
    while (low<=high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }else if (arr[mid]>value)
        {
            return mid - 1;
        }else{
            return mid + 1;
        }
    }
    return -1;
}
int bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        int swap = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0)
        {
            break;
        }
    }
}
int main(){
    int n, i, value;
    printf("Nh?p n: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Nh?p giá tr? mu?n tìm ki?m: ");
    scanf("%d", &value);
    if (bynarySearch(arr, size, value) != -1)
    {
        printf("Không có trong danh sách");
    }
    else
    {
        printf("có trong danh sách");
    }
    return 0;
}
