#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char id;
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;

Node* root;

Node* makeNode(char id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftMostChild = NULL; 
    p->rightSibling = NULL;
    return p;
}

Node* find(Node* r, int id){
    if(r == NULL) return NULL;
    if(r->id == id) return r;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* q = find(p, id);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

Node* addLast(Node* p, char id){
    if(p == NULL) return makeNode(id);
    p->rightSibling = addLast(p->rightSibling, id);
    return p;
}

void addChild(int parent_id, int child_id){
    Node* r = find(root, parent_id);
    if(r == NULL) return;
    r->leftMostChild = addLast(r->leftMostChild, child_id);
}

void preOrder(Node* r) {
    if (r == NULL) return;
    printf("%d ", r->id); // visit the root r
    Node* p = r->leftMostChild;
    while (p != NULL) {
        preOrder(p);
        p = p->rightSibling;
    }
}

void inOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;// the first (left-most) child of r: r1
    inOrder(p);
    printf("%d ",r->id);
    if(p == NULL) return;
    p = p->rightSibling; // p = the second child of r: r2
    while(p != NULL){
        inOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ",r->id);
}

int countChild(char v){
    Node* p = find(root, v);
    if ( p == NULL ) return 0;
    int count = 0;
    p = p -> leftMostChild;
    while (p != NULL)
    {
        count++;
        p = p->rightSibling;
    }
    return count; 
}

int countTree(char v){
    Node* p = find(root, v);
    if ( p == NULL ) return 0;
    int count = 1;
    p = p -> leftMostChild;
    while ( p != NULL ){
        count += countTree(p -> id);
        p = p->rightSibling;
    }
    return count;
}

int height(char v) {
    Node* r = find( root, v);
    if (r == NULL) return 0;

    int maxH = 0;
    Node* p = r->leftMostChild;
    while (p != NULL) {
        int childHeight = height(p->id);
        maxH = (childHeight > maxH) ? childHeight : maxH;
        p = p->rightSibling;
    }

    return 1 + maxH;
}

int countLeaves(char v) {
    Node* r = find(root, v);
    if (r == NULL) return 0;

    if (r->leftMostChild == NULL) return 1;

    int count = 0;
    Node* p = r->leftMostChild;
    while (p != NULL) {
        count += countLeaves(p->id);
        p = p->rightSibling;
    }

    return count;
}

int main() {
    char cmd[20];
    int v, u;
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf(" %d", &v);
            root = makeNode(v);
        } else if (strcmp(cmd, "Insert") == 0) {
            scanf(" %d %d", &u, &v);
            addChild(u, v);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "Height") == 0) {
            scanf(" %c", &v);
            printf("%d\n", height(v));
        } else if (strcmp(cmd, "CountTree") == 0) {
            scanf(" %c", &v);
            printf("%d\n", countTree(v));
        } else if (strcmp(cmd, "CountChild") == 0) {
            scanf(" %c", &v);
            printf("%d\n", countChild(v));
        } else if (strcmp(cmd, "CountLeaves") == 0) {
            scanf(" %c", &v);
            printf("%d\n", countLeaves(v));
        } else if (strcmp(cmd, "*") == 0) {
            break;
        }
    }

    return 0;
}
