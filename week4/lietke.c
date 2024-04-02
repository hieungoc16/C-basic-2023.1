#include <stdio.h>
#define MAX 100

int a[MAX], n, m;

void printSolution() {
    for (int i = 1; i <= n; i++) 
        printf("%d", a[i]);
    printf("\n");
}

void gen(int k) {
    if (k > n) { 
        printSolution(); 
        return; 
    }

    for(int i = a[k - 1] + 1; i <= m + n - k; i++){
        a[k] = i;
        gen(k + 1);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    a[0] = 0;
    gen(1);
}