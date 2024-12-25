#include <stdio.h>
void bubbleSort(int arr[], int n, int isAscending) {
    int swapped, i, j;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if ((isAscending && arr[j] > arr[j + 1]) || 
                (!isAscending && arr[j] < arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, isAscending, i;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nh?p các ph?n t? c?a m?ng: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Ch?n ki?u s?p x?p (1-Tang d?n, 0-Gi?m d?n): ");
    scanf("%d", &isAscending);
    printf("M?ng tru?c khi s?p x?p: ");
    printArray(arr, n);
    bubbleSort(arr, n, isAscending);
    printf("M?ng sau khi s?p x?p: ");
    printArray(arr, n);
    return 0;
}

