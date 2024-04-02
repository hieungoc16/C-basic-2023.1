#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* MakeNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

int isMaxHeap(Node* root) {
    if (root == NULL) {
        return 1; // Cây rỗng được coi là max-heap
    }

    if (root->leftChild != NULL && root->leftChild->id > root->id) {
        return 0;
    }

    if (root->rightChild != NULL && root->rightChild->id > root->id) {
        return 0;
    }

    return isMaxHeap(root->leftChild) && isMaxHeap(root->rightChild);
}

Node* findNode(Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->id == target) {
        return root;
    }

    Node* leftSearch = findNode(root->leftChild, target);
    if (leftSearch != NULL) {
        return leftSearch;
    }

    return findNode(root->rightChild, target);
}

void addLeftChild(Node* root, int cur_id, int child_id) {
    Node* curNode = findNode(root, cur_id);
    if (curNode != NULL) {
        if (curNode->leftChild == NULL) {
            curNode->leftChild = MakeNode(child_id);
        }
    }
}

void addRightChild(Node* root, int cur_id, int child_id) {
    Node* curNode = findNode(root, cur_id);
    if (curNode != NULL) {
        if (curNode->rightChild == NULL) {
            curNode->rightChild = MakeNode(child_id);
        }
    }
}

int main() {
    Node* root = NULL;

    char action[20];
    int u, v;

    while (1) {
        scanf("%s", action);

        if (action[0] == 'M') {
            scanf("%d", &u);
            root = MakeNode(u);
        } else if (action[0] == 'A' && action[3] == 'L') {
            scanf("%d %d", &u, &v);
            addLeftChild(root, u, v);
        } else if (action[0] == 'A' && action[3] == 'R') {
            scanf("%d %d", &u, &v);
            addRightChild(root, u, v);
        } else if (action[0] == 'I') {
            scanf("%d", &u);
            int result = isMaxHeap(findNode(root, u));
            printf("%d\n", result);
        } else if (action[0] == 'Q') {
            break;
        }
    }

    return 0;
}
