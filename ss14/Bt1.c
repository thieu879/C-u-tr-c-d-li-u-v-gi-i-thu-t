#include<stdio.h>
int linearSearch(int arr[], int size, int value){
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i]==value)
        {
            return i;
        }
    }
    return -1;
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

    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Nh?p giá tr? mu?n tìm ki?m: ");
    scanf("%d", &value);
    if (linearSearch(arr, size, value) == -1)
    {
        printf("Không có trong danh sách");
    }else{
        printf("có trong danh sách");
    }

    return 0;
}
