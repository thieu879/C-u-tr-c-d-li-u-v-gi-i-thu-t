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
    int numSwaps = 0;
    for (i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            numSwaps++;
            printf("Hoán d?i: ");
            printArray(arr, n);
        }
    }
    printf("S?p x?p hoàn thành v?i %d l?n hoán d?i.\n", numSwaps);
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
    printf("M?ng ban d?u: ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("M?ng dã s?p x?p: ");
    printArray(arr, n);
    return 0;
}

