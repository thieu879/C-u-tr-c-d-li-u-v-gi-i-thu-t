#include <stdio.h>
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void selectionSort(int arr[], int n) {
	int i, j;
    for (i = 0; i < n - 1; i++) {
        int minIndex = i;  
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            printf("Hoán d?i %d v?i %d: ", arr[minIndex], arr[i]);
            printArray(arr, n);
        }
    }
}

int main() {
    int n, i;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nh?p các ph?n t? c?a m?ng: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("M?ng tru?c khi s?p x?p: ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("M?ng sau khi s?p x?p: ");
    printArray(arr, n);
    return 0;
}

