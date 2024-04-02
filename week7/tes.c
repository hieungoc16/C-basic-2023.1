#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
    char id;
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;
Node* root;
Node* MakeRoot(char id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}

Node* FindNode(Node* root, char id) {
    if (root == NULL) return NULL;
    if (root->id == id) return root;
    Node* sibling = root->rightSibling;
    while (sibling != NULL) {
        if (sibling->id == id) return sibling;
        sibling = sibling->rightSibling;
    }
    Node* child = root->leftMostChild;
    while (child != NULL) {
        Node* result = FindNode(child, id);
        if (result != NULL) return result;
        child = child->rightSibling;
    }
    return NULL;
}

void AddChild(Node* root, char u, char v) {
    Node* uNode = FindNode(root, u);
    if (uNode == NULL || FindNode(root, v) != NULL) return; // u doesn't exist or v already exists

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = v;
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;

    if (uNode->leftMostChild == NULL) {
        uNode->leftMostChild = newNode;
    } else {
        Node* child = uNode->leftMostChild;
        while (child->rightSibling != NULL) {
            child = child->rightSibling;
        }
        child->rightSibling = newNode;
    }
}

void PreOrder(Node* r) {
    if (r == NULL) return;
    printf("%c ", r->id); // visit the root r
    Node* p = r->leftMostChild;
    while (p != NULL) {
        PreOrder(p);
        p = p->rightSibling;
    }
}

void InOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;// the first (left-most) child of r: r1
    InOrder(p);
    printf("%c ",r->id);
    if(p == NULL) return;
    p = p->rightSibling; // p = the second child of r: r2
    while(p != NULL){
        InOrder(p);
        p = p->rightSibling;
    }
}

void PostOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        PostOrder(p);
        p = p->rightSibling;
    }
    printf("%c ",r->id);
}



int Height(Node* root, char id) {
    Node* u = FindNode(root, id);
    if (u == NULL) return -1; // Node not found
    int height = -1;
    while (u != NULL) {
        u = u->leftMostChild;
        height++;
    }
    return height;
}

int CountTree(Node* root, char id) {
    Node* u = FindNode(root, id);
    if (u == NULL) return 0; // Node not found
    int count = 1;
    Node* child = u->leftMostChild;
    while (child != NULL) {
        count += CountTree(child, child->id);
        child = child->rightSibling;
    }
    return count;
}

int CountChild(Node* root, char id) {
    Node* u = FindNode(root, id);
    if (u == NULL) return 0; // Node not found
    int count = 0;
    Node* child = u->leftMostChild;
    while (child != NULL) {
        count++;
        child = child->rightSibling;
    }
    return count;
}

int CountLeaves(Node* root, char id) {
    Node* u = FindNode(root, id);
    if (u == NULL) return 0; // Node not found
    if (u->leftMostChild == NULL) return 1; // Node is a leaf
    int count = 0;
    Node* child = u->leftMostChild;
    while (child != NULL) {
        count += CountLeaves(child, child->id);
        child = child->rightSibling;
    }
    return count;
}

int main() {
    char cmd[20], v, u;
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf(" %c", &v);
            root = MakeRoot(v);
        } else if (strcmp(cmd, "AddChild") == 0) {
            scanf(" %c %c", &u, &v);
            AddChild(root, u, v);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            PreOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "PostOrder") == 0) {
            PostOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0) {
            InOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "Height") == 0) {
            scanf(" %c", &v);
            printf("%d\n", Height(root, v));
        } else if (strcmp(cmd, "CountTree") == 0) {
            scanf(" %c", &v);
            printf("%d\n", CountTree(root, v));
        } else if (strcmp(cmd, "CountChild") == 0) {
            scanf(" %c", &v);
            printf("%d\n", CountChild(root, v));
        } else if (strcmp(cmd, "CountLeaves") == 0) {
            scanf(" %c", &v);
            printf("%d\n", CountLeaves(root, v));
        } else if (strcmp(cmd, "#") == 0) {
            break;
        }
    }

    return 0;
}