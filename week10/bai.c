#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct Node {
    char name[MAX_LEN];
    float grade;
    struct Node* previous;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void initList() {
    head = NULL;
    tail = NULL;
}

int listEmpty() {
    return (head == NULL && tail == NULL);
}

Node* makeNode(char* s, float v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        strcpy(newNode->name, s);
        newNode->previous = NULL;
        newNode->next = NULL;
        newNode->grade = v;
    }
    return newNode;
}

void insertLast(char* s, float v) {
    Node* newNode = makeNode(s, v);

    if (listEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void swap(Node* a, Node* b) {
    float tempGrade = a->grade;
    a->grade = b->grade;
    b->grade = tempGrade;

    char tempName[MAX_LEN];
    strcpy(tempName, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tempName);
}   
void printListLeft2Right() {
    for (Node* current = head; current != NULL; current = current->next)
        printf("%s ", current->name);
    printf("\n");
}

Node* merge(Node* head, Node* l, Node* mid, Node* r) {

    Node* i = l;
    Node* j = mid->next;
    Node* ta = NULL;
    for ( Node* k = l; k != r->next; k = k -> next){
        if ( i == mid->next ){

        }
    }
}


Node* mergeSort(Node* head, Node* l, Node* r) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* mid = l;
    Node* fast = l->next;

    while (fast != NULL && fast->next != r->next) {
        mid = mid->next;
        fast = fast->next->next;
    }

    mergeSort(head, l, mid);
    mergeSort(head, mid->next, r);

    merge(head, l, mid, r);
}

int main() {
    char buff[MAX_LEN];
    char s[100];
    float v;

    while (1) {
        scanf("%s", s);
        if (strcmp(s, "#") == 0)
            break;
        scanf(" %f", &v);
        if (v <= 10 && v >= 0)
            insertLast(s, v);
    }

    mergeSort(head, head, tail);

    return 0;
}
