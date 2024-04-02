#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int a[MAX], n;
bool b[MAX]; // Mảng đánh dấu, true là chưa dùng, false là đã dùng
int dem = 0;

// In cấu hình A
void printSolution() {
    for (int i = 1; i <= n; i++) 
        printf("%d", a[i]);
    printf("\n");
}

// Kiểm tra xem hai số cùng chẵn hoặc cùng lẻ đứng cạnh nhau
bool isValid(int k) {
    if (k > 1 && ((a[k] % 2 == 0 && a[k - 1] % 2 == 0) || (a[k] % 2 != 0 && a[k - 1] % 2 != 0))) {
        return false;
    }
    return true;
}

// Sinh phần tử thứ k
void gen(int k){
    // Kiểm tra sinh đủ n phần tử thì dừng
    if (k > n) { 
        printSolution(); 
        return; 
    }

    for (int i = 1; i <= n; i++){
        if (b[i]) { // Nếu chưa dùng  
            a[k] = i; // Chọn giá trị đó
            b[i] = false; // Đánh dấu là đã dùng
            if (isValid(k)) { // Kiểm tra điều kiện
                gen(k + 1); // Gọi đệ quy để sinh tiếp
            }
            b[i] = true; // Bỏ đánh dấu
        }
    }
}

int main(){
    scanf("%d", &n);
    if (n <= 1) {
        printf("Input error\n");
        return 0;
    }
    
    for(int i = 1; i <= n; i++)
        b[i] = true;
        
    gen(1);    
    return 0;
}
