#include<stdio.h>
#include<string.h>

int main(){
    int buff[100];
    int a[100], count = 0;
    fgets(buff, 100, stdin);
    char *token = strtok(buff, " ");
    while ( token != NULL){
        count++;
        a[count]=atoi(token);
        token= strtok(NULL, " ");
    }

}