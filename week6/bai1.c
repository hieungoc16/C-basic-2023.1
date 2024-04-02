#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* top;  // for stack
Node* head; // for queue
Node* tail; // for queue

Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void initStack() {
    top = NULL;
}

int stackEmpty() {
    return top == NULL;
}

void push(int v) {
    Node* p = makeNode(v);
    p->next = top;
    if (top != NULL) {
        top->prev = p;
    }
    top = p;
}

char pop() {
    if (stackEmpty()) return -1;
    char v = top->value;
    Node* tmp = top;
    top = top->next;
    if (top != NULL) {
        top->prev = NULL;
    }
    free(tmp);
    return v;
}

void initQueue() {
    head = NULL;
    tail = NULL;
}

void enqueue(int v) {
    Node* p = makeNode(v);
    if (tail == NULL) {
        head = p;
        tail = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

char dequeue() {
    if (head == NULL) return -1;
    char v = head->value;
    Node* tmp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(tmp);
    return v;
}

void finalizestack() {
    while (!stackEmpty()) {
        pop();
    }
}

void finalizequeue() {
    while (head != NULL) {
        dequeue();
    }
}

int main(void) {
    double decimal;

    // Nhận một số thập phân từ bàn phím
    scanf("%lf", &decimal);

    // Phần nguyên
    int intPart = (int)decimal;
    initStack();
    if (intPart == 0) printf("0");
    while (intPart > 0) {
        int re = intPart % 2;
        push(re); 
        intPart /= 2;
    }

    while (!stackEmpty()) {
        printf("%d", pop());
    }
    printf(".");

    // Phần thập phân
    double fracPart = decimal - (int)decimal;
    initQueue();

    int max = 0; 
    double tempFrac = fracPart; 

    while (tempFrac != (int)tempFrac) {
        tempFrac *= 10; 
        max++;
    }
    if (max < 1) {
        max = 1;
    }

    while (fracPart > 0 && max > 0) {
        fracPart *= 2;
        int bit = (int)fracPart;
        enqueue(bit);
        fracPart -= (int)fracPart;
        max--;
    }


    while (max > 0) {
        enqueue(0);
        max--;
    }

    while (head != NULL) {
        printf("%d", dequeue());
    }

    printf("\n");
    finalizestack();
    finalizequeue();

    return 0;
}
