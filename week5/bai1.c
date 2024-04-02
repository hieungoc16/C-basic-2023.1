#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void initList(){
    head = NULL;
    tail = NULL;
}

int listempty(){
    return ( head == NULL && tail == NULL );
}

Node *makenode(int v){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if ( newNode != NULL ){
        newNode->value = v;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    return newNode;
}

void insertLast( int v ){
    Node* newNode = makenode(v);

    if ( listempty() ){
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}