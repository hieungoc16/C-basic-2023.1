#include <stdio.h>

void phanTich(int n, int *arr, int size, int idx, int lastAdded) {
    if (n == 0) {
        // In ra phân tích
        printf("{ ");
        for (int i = 0; i < idx; ++i) {
            printf("%d", arr[i]);
            if (i < idx - 1) printf(", ");
        }
        printf(" }\n");
        return;
    }

    for (int i = 1; i <= n && i <= lastAdded; ++i) {
        // Thử thêm số i vào phân tích
        arr[idx] = i;
        phanTich(n - i, arr, size, idx + 1, i);
    }
}

int main() {
    int N;
    printf("Nhap so N: ");
    scanf("%d", &N);

    int arr[N];  // Mảng để lưu các số nguyên dương trong phân tích
    phanTich(N, arr, N, 0, N);

    return 0;
}
/*
#include <stdio.h>

void phanTich(int n, int *arr, int size, int idx, int minValue) {
    if (n == 0) {
        // In ra phân tích
        printf("{ ");
        for (int i = 0; i < idx; ++i) {
            printf("%d", arr[i]);
            if (i < idx - 1) printf(", ");
        }
        printf(" }\n");
        return;
    }

    for (int i = minValue; i <= n; ++i) {
        // Thử thêm số i vào phân tích
        arr[idx] = i;
        phanTich(n - i, arr, size, idx + 1, i + 1);
    }
}

int main() {
    int N;
    printf("Nhap so N: ");
    scanf("%d", &N);

    int arr[N];  // Mảng để lưu các số nguyên dương trong phân tích
    phanTich(N, arr, N, 0, 1);

    return 0;
}
*/