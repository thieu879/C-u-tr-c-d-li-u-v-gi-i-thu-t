#include <stdio.h>
int binarySearch(int arr[], int size, int value) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
void insertionSort(int arr[], int n) {
	int i;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, value, i;
    printf("Nhap n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printf("Mang sau khi sap xep: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Nhap gia tri muon tim kiem: ");
    scanf("%d", &value);

    int result = binarySearch(arr, n, value);
    if (result != -1) {
        printf("Gia tri co trong danh sach tai vi tri.\n");
    } else {
        printf("Gia tri khong co trong danh sach.\n");
    }

    return 0;
}

