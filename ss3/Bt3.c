#include <stdio.h>
int fibonacci(int n) {
    if (n == 0){
       return 0; 
    } 
    if (n == 1){
       return 1; 
    } 
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    int i;
    printf("Nh?p s? l?n hi?n th? s? Fibonacci (n): ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("S? n ph?i l?n hon 0.\n");
        return 1;
    }
    printf("Dãy Fibonacci v?i %d s? d?u tiên: ", n);
    for (i = 0; i < n; i++) {
        printf("%d", fibonacci(i));
        if (i < n - 1) {
            printf(", ");
        }
    }
    return 0;
}

