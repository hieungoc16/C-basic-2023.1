#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh cho hàm qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Hàm tìm bộ ba số
void find(int arr[], int n, int sum) {
    int b = 0;
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int current_sum = arr[i] + arr[left] + arr[right];

            if (current_sum == sum) {
                printf("%d %d %d\n", arr[i], arr[left], arr[right]);
                left++;
                right--;
                b = 1;
            } else if (current_sum < sum) {
                left++;
            } else {
                right--;
            }
        }
    }
    if ( b == 0 ) printf("Not found");
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    find(arr, n, q);

    return 0;
}
