#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
    if ( argc < 2) return 1;
    for ( int j = argc - 1 ; j >= 1; j--) printf("%s ",argv[j]);
    return 0;
}