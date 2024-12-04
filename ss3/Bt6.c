#include <stdio.h>

int sumArr(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n - 1] + sumArr(arr, n - 1);
}

int main() {
    int n, i;

    printf("Nh?p n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("T?ng m?ng: 0\n");
        return 0;
    }
    int arr[n];
    printf("Nh?p các s? vào m?ng: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = sumArr(arr, n);
    printf("T?ng m?ng: %d\n", result);		
    return 0;
}

