#include <stdio.h>

int main() {
    int n, k, index = -1;

    printf("Nh?p s? ph?n t? c?a m?ng (0 < n <= 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("S? ph?n t? không h?p l?.\n");
        return 1;
    }

    int arr[n];

    printf("Nh?p %d ph?n t? c?a m?ng:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nh?p ph?n t? c?n xóa (k): ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Thông báo: không có ph?n t? d?y.\n");
    } else {
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        printf("M?ng sau khi xóa ph?n t? %d:\n", k);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}

