#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 10000
#define ULL unsigned long long
typedef struct TNode {
unsigned long long key; // Khoá
struct TNode* next; // Con trỏ, trỏ đến node kế tiếp
} Node;

Node* t[M] = {NULL};

Node* makeNode(ULL v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = v;
    p->next = NULL;
    return p; 
}

int find(ULL v){
    Node *p = t[v % M];
    while ( p != NULL ){
        if ( p->key == v) return 1;
        p = p->next;
    }
    return 0;
}

int insert(ULL k) {
    if (find(k) == 1) return 0;
    if (find(k) == 0) {
        Node* p = t[k % M];
        if (p == NULL) {
            t[k % M] = makeNode(k);
        } else {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = makeNode(k);
            
        }
        return 1;
    } 
    
}


int main(){
    int n, i = 0;
    ULL v;
    char cmd[10];
    while(1){
        int s = scanf("%lld", &v);
        insert(v);
        if ( s == 0 ) break;
        
    }
    while(1){
        scanf("%s", cmd);
        if (strcmp(cmd, "find") == 0){
            scanf("%lld", &v);
            if (find(v)) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(cmd, "insert") == 0){
            scanf("%lld", &v);
            printf("%d\n", insert(v));
            insert(v);
        }
        else if (strcmp(cmd, "***") == 0) break;
    }
}