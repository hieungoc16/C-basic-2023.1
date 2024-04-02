#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

#define MAX_LEN 100

typedef struct Node {
    char name[MAX_LEN];
    float grade;
    struct Node *next, *prev;
}Node;

Node *split(struct Node *head);


Node *merge(Node *l, Node *r) {
    if (!l)
        return r;

    if (!r)
        return l;

    if (l->grade < r->grade) {
        l->next = merge(l->next, r);
        l->next->prev = r;
        l->prev = NULL;
        return l;
    } else {
        r->next = merge(l, r->next);
        r->next->prev = r;
        r->prev = NULL;
        return r;
    }
}

Node *mergeSort(struct Node *head) {
    if (!head || !head->next)
        return head;

    Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}


void insert(Node **head, char name[], float grade) {
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->grade = grade;
    temp->next = temp->prev = NULL;

    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}


void print(Node *head) {
    while (head) {
        printf("%s ", head->name);
        //temp = head;
        head = head->next;
    }
}


Node *split(Node *head) {
    Node *fast = head, *mid = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        mid = mid->next;
    }
    Node *temp = mid->next;
    mid->next = NULL;
    return temp;
}

// Driver program
int main(void) {
    Node *head = NULL;
    char buff[MAX_LEN];
    char s[100];
    float v;

    while (1) {
        scanf("%s", s);
        if (strcmp(s, "#") == 0)
            break;
        scanf(" %f", &v);
        if (v <= 10 && v >= 0)
            insert(&head, s, v);
    }

    head = mergeSort(head);

    print(head);

    return 0;
}
