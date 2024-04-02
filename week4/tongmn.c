#include <stdio.h>
#define MAX 100

int a[MAX], n, m, p = 0;

// In cấu hình A
void printSolution() {
    for (int i = 1; i <= n; i++) 
        printf("%d", a[i]);
    printf("\n");
}

// Kiểm tra tổng đúng bằng m hay không
int check(int x, int k){
    if(k == n) return p + x == m;
    return 1;
}

// Sinh phần tử thứ k
void gen(int k){
    for (int x = 1; x <= m - p - n + k; x++) {
        if(check(x, k)){
            a[k] = x;
            p += x;
            if (k == n) 
                printSolution();
            else    
                gen(k+1);
            p -= x;
        }
    }    
}

int main(){
    scanf("%d %d", &n, &m);
    gen(1);
}