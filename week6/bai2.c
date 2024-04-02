#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
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

int pop() {
    if (stackEmpty()) return -1;
    int v = top->value;
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

int dequeue() {
    if (head == NULL) return -1;
    int v = head->value;
    Node* tmp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(tmp);
    return v;
}

void finalizeStack() {
    while (!stackEmpty()) {
        pop();
    }
}

void finalizeQueue() {
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

    if (intPart == 0) {
        printf("0");
    } else {
        while (intPart > 0) {
            int re = intPart % 16;
            push(re);
            intPart /= 16;
        }
    }

    while (!stackEmpty()) {
        int value = pop();
        if (value > 0) {
            if (value >= 10) {
                char hex = 'A' + (value - 10);
                printf("%c", hex);
            } else {
                printf("%d", value);
            }
        }
    }
    double fracPart = decimal - (int)decimal;
    if ( fracPart > 0 ){
        printf(".");

        // Phần thập phân
        initQueue();
        int printed = 0;
        int max = 10;

        while (fracPart > 0 && max > 0) {
            fracPart *= 16;
            int bit = (int)fracPart;
            if (bit > 0) {
                if (bit >= 10) {
                    char hex = 'A' + (bit - 10);
                    printf("%c", hex);
                } else {
                    printf("%d", bit);
                }
                printed = 1;
            }
            fracPart -= (int)fracPart;
            max--;
        }

        if (printed == 0) {
            printf("0");
        }
    }
    printf("\n");
    finalizeStack();
    finalizeQueue();

    return 0;
}
