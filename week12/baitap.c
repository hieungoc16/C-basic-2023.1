#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
int key;
struct Node* leftChild;
struct Node* rightChild;
}Node;

Node* makeNode(Node* head, int item){
    Node* p = (Node*)malloc(sizeof(Node));
    if (p!= NULL){
        p->key = item;
        p->leftChild = NULL;
        p->rightChild = NULL;
    }
    return p;
}

Node *insert(Node * p, int item){
    if(p==NULL) p = makeNode(p, item);
    else if(item < p->key)
        p->leftChild = insert(p->leftChild, item);
    else if(item > p->key)
        p->rightChild = insert(p->rightChild, item);
    return p;
}

Node *search(Node *p, int target){
    if  (p!=NULL){
        if  (target < p->key){
            p = search(p->leftChild, target);
        }else{
            if(target > p->key)
            p = search(p->rightChild, target);
        }
    }
    return p;
}

Node* findmax(Node* p) {
    while (p != NULL && p->rightChild != NULL) {
        p = p->rightChild;
    }
    return p;
}

Node* findmin(Node* p) {
    while (p != NULL && p->leftChild != NULL) {
        p = p->leftChild;
    }
    return p;
}

void inOrder(Node* r) {
    if (r == NULL) return;
    inOrder(r->leftChild);
    printf("%d ", r->key);
    inOrder(r->rightChild);
}

Node* deletep(Node* p, int u){
    Node* tmp;
    if  (p==NULL) printf("%d not found", u);
    else if(u < p->key) p->leftChild = deletep(p->leftChild, u);
    else if(u > p->key) p->rightChild = deletep(p->rightChild, u);
        else /*Tìm được phần tử cần xóa */
            if(p->leftChild && p->rightChild){/* Tình huống 4 */
                                            tmp = findmin(p->rightChild);
                                            p->key = tmp->key;
                                            p->rightChild = deletep(p->rightChild,p->key);
            }else{/* có một con hoặc không có con*/
                    tmp = p;
                    if(p->leftChild==NULL)/* chỉ có con phải */
                    p = p->rightChild;
                    else /* chỉ có con trái */
                    p = p->leftChild;
                    free(tmp);
                }
    return p;
}

void freeTree(Node* p) {
    if (p == NULL) return;
    freeTree(p->leftChild);
    freeTree(p->rightChild);
    free(p);
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

int depth(Node* p, int u, int currentDepth) {
    if (p == NULL) return 0;
    if (p->key == u) return currentDepth;
    int leftDepth = depth(p->leftChild, u, currentDepth + 1);
    if (leftDepth > 0) return leftDepth;
    return depth(p->rightChild, u, currentDepth + 1);
}


int main() {
    char cmd[20];
    char v, u;
    Node* p = NULL;
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "Insert") == 0) {
            scanf(" %d", &u);
            p = insert(p, u);
        } else if (strcmp(cmd, "PrintTree") == 0) {
            inOrder(p);
            printf("\n");
        } else if (strcmp(cmd, "Delete") == 0) {
            scanf(" %d", &u);
            deletep(p, u);
        } else if (strcmp(cmd, "FindMax") == 0) {
            Node* maxNode = findmax(p);
            if (maxNode != NULL) printf("Max is %d", maxNode->key);
            else printf("Tree is empty");
            printf("\n");
        }else if (strcmp(cmd, "FindMin") == 0){
            Node* minNode = findmin(p);
            if (minNode != NULL) printf("Min is %d", minNode->key);
            else printf("Tree is empty");
            printf("\n");
        }else if (strcmp(cmd, "TreeHeight") == 0) {
            if( p == NULL )printf("Tree is empty");
            else printf("%d", height(p)-1);
            printf("\n");
        }else if (strcmp(cmd, "Depth") == 0) {
            scanf("%d", &u);
            int nodeDepth = depth(p, u, 0);
            if (nodeDepth > 0) printf("%d", nodeDepth);
            else printf("%d not found", u);
            printf("\n");
        }else if (strcmp(cmd, "Search") == 0) {
            scanf("%d", &u);
            if (search(p, u) != NULL) printf("found %d", u);
            else printf("%d not found", u);
            printf("\n");
        }else if (strcmp(cmd, "#") == 0) {
            break;
        }
    }
    freeTree(p);
    return 0;
}




