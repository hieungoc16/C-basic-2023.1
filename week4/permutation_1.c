#include <stdio.h>
#define MAX 1000

int a[MAX], n;
char b[MAX]; // mảng đánh dấu, 1 là chưa dùng, 0 là đã dùng
int dem = 0;
// In cấu hình A
void printSolution() {
    for (int i = 1; i <= n; i++) 
        printf("%d ", a[i]);
    printf("\n");
}

// Sinh phần tử thứ k
void gen(int k){
    // Kiểm tra sinh đủ n phần tử thì dừng
    if (k > n) { 
        printSolution(); 
        return; 
    }
    // Chọn giá trị cho a[k]
    
    for (int i = 1; i <= n; i++){
        if (b[i]){     // Nếu chưa dùng  
            b[i] = 0;   // đánh dấu là đã dùng
            a[k] = i;   // chọn giá trị đó
            gen(k + 1); // và gọi đệ quy sinh tiếp
            b[i] = 1;
            }
}
}


int main(){
    scanf("%d", &n);
    if ( n <= 0) printf("Input error"); 
    else{
    for(int i = 1; i <= n; i++)
        b[i] = 1;
  //  int dem = 0;
    gen(1);    
    }
}