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
    printf("Nh?p gi� tr? mu?n t�m ki?m: ");
    scanf("%d", &value);
    if (linearSearch(arr, size, value) == -1)
    {
        printf("Kh�ng c� trong danh s�ch");
    }else{
        printf("c� trong danh s�ch");
    }

    return 0;
}
