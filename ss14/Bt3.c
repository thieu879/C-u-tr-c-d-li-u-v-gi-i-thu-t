#include<stdio.h>
int bubbleSort(int arr[], int size){
    int i, j;
    for (i = 0; i < size; i++)
    {
        int swap = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j]>arr[j+1])
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
int printArr(int arr[], int size){
    int i;
    printf("m?ng dã du?c s?p x?p: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
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
    printArr(arr, n);
    return 0;
}
