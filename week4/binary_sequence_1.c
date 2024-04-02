#include <stdio.h>
#define MAX 100

int a[MAX], n;

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
    a[k] = 0; gen(k+1);
    a[k] = 1; gen(k+1);
}
int main() {
    scanf("%d", &n);
    if ( n <= 0 ) printf("Error");
    else gen(1);
}