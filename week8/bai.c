#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct Node {
    char id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;
Node* root;

Node* makeNode(char id) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node* find(Node* r, char id) {
    if (r == NULL) return NULL;
    if (r->id == id) return r;
    Node* p = find(r->leftChild, id);
    if (p != NULL) return p;
    return find(r->rightChild, id);
}

void addLeftChild(char u, char left) {
    Node* p = find(root, u);
    if (p == NULL) return;
    if (p->leftChild != NULL) return;
    p->leftChild = makeNode(left);
}

void addRightChild(char u, char right) {
    Node* p = find(root, u);
    if (p == NULL) return;
    if (p->rightChild != NULL) return;
    p->rightChild = makeNode(right);
}

void preOrder(Node* r) {
    if (r == NULL) return;
    printf("%c ", r->id);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}

void inOrder(Node* r) {
    if (r == NULL) return;
    inOrder(r->leftChild);
    printf("%c ", r->id);
    inOrder(r->rightChild);
}

void postOrder(Node* r) {
    if (r == NULL) return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%c ", r->id);
}

int height(Node* p){
    if(p == NULL) return 0;
    int maxH = 0;
    int hl = height(p->leftChild);
    if(maxH < hl) maxH = hl;
    int hr = height(p->rightChild);
    if(maxH < hr) maxH = hr;
    return maxH + 1;
}

int countNodes(Node* r) {
    if (r == NULL) return 0;
    return 1 + countNodes(r->leftChild) + countNodes(r->rightChild);
}

int bac2(int a){
    int j = 1;
    for ( int i = 0; i < a; i++)
        j = 2 * j;
    return j;
}

int checkPerfect(Node* node, int* depth, int level, int nodeCount) {
    if (node == NULL) {
        if (*depth == 0) {
            *depth = level;
        } else if (level != *depth) {
            return 0;
        }
        return 1;
    }

    return checkPerfect(node->leftChild, depth, level + 1, nodeCount) &&
           checkPerfect(node->rightChild, depth, level + 1, nodeCount) &&
           (nodeCount == (bac2(*depth)) - 1); 
}

int isPerfect(char v) {
    Node* r = find(root, v);
    int depth = 0;
    int nodeCount = countNodes(r);

    return checkPerfect(r, &depth, 0, nodeCount);
}



int isFull(char v) {
    Node *r = find(root, v);
    if (r == NULL) return 1;

    if (r->leftChild == NULL && r->rightChild == NULL) return 1;
    if (r->leftChild != NULL && r->rightChild != NULL) {
        return (isFull(r->leftChild->id) && isFull(r->rightChild->id));
    }
    return 0;
}

int isComplete(char v, int index, int count) {
    Node *r = find(root, v);
    if (r == NULL) return 1;

    if (index >= count) return 0;

    if (r->leftChild == NULL && r->rightChild == NULL)
        return 1;

    if ((r->leftChild != NULL && !isComplete(r->leftChild->id, 2 * index + 1, count)) ||
        (r->rightChild != NULL && !isComplete(r->rightChild->id, 2 * index + 2, count))) {
        return 0;
    }

    return 1;
}

int isBalanced(char v) {
    Node *r = find(root, v);
    if (r == NULL) return 1;

    int leftHeight = (r->leftChild != NULL) ? height(r->leftChild) : 0;
    int rightHeight = (r->rightChild != NULL) ? height(r->rightChild) : 0;

    if (abs(leftHeight - rightHeight) <= 1 &&
        isBalanced((r->leftChild != NULL) ? r->leftChild->id : -1) &&
        isBalanced((r->rightChild != NULL) ? r->rightChild->id : -1)) {
        return 1;
    }

    return 0;
}
int count2(Node* root) {
    if (root == NULL) return 0;
    int cnt = 0;
    if (root -> leftChild != NULL && root -> rightChild != NULL){
        cnt  = 1;
    }
    cnt += count2(root -> leftChild);
    cnt += count2(root -> rightChild);
    return cnt;
}


int main() {
    char cmd[20];
    char v, u;

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf(" %c", &v);
            root = makeNode(v);
        } else if (strcmp(cmd, "AddLeftChild") == 0) {
            scanf(" %c %c", &u, &v);
            addLeftChild(u, v);
        } else if (strcmp(cmd, "AddRightChild") == 0) {
            scanf(" %c %c", &u, &v);
            addRightChild(u, v);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "IsPerfect") == 0) {
            scanf(" %c", &v);
            if (isPerfect(v)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else if (strcmp(cmd, "IsFull") == 0) {
            scanf(" %c", &v);
            if (isFull(v)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else if (strcmp(cmd, "IsComplete") == 0) {
            scanf(" %c", &v);
            Node* r = find(root, v);
            int nodeCount = countNodes(r);
            if (isComplete(v, 0, nodeCount)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else if (strcmp(cmd, "IsBalanced") == 0) {
            scanf(" %c", &v);
            if (isBalanced(v)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else if (strcmp(cmd, "CountNodes2Children") == 0) {
            printf("%d", count2(root) );
        } else if (strcmp(cmd, "Quit") == 0) {
            break;
        }
    }

    return 0;
}
