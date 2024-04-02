#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head = NULL;

// Hàm tạo một Node mới
Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}
int exists(int v) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == v) {
            return 1;  // Giá trị đã tồn tại
        }
        current = current->next;
    }
    return 0;  // Giá trị chưa tồn tại
}


Node* addLast(int v) {
    if (!exists(v)) {
        Node* newNode = makeNode(v);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}


Node* addFirst(int v) {
    if (!exists(v)) {
        Node* newNode = makeNode(v);
        newNode->next = head;
        return newNode;
    }
}

Node* addAfter(int u, int v) {
    if (!exists(u) && exists(v)) {
        Node* current = head;
        while (current != NULL) {
            if (current->value == v) {
                Node* newNode = makeNode(u);
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }
}

Node* addBefore(int u, int v) {
    if (!exists(u) && exists(v)) {
        if (head == NULL) {
            return NULL;
        }

        if (head->value == v) {
            Node* newNode = makeNode(u);
            newNode->next = head;
            return newNode;
        }

        Node* current = head;
        while (current->next != NULL) {
            if (current->next->value == v) {
                Node* newNode = makeNode(u);
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }
}


Node* removeNode(Node* head, int v){
    if(head == NULL) 
        return NULL;
    
    if(head->value == v){
        Node* tmp = head; 
        head = head->next; 
        free(tmp);
        head = removeNode(head, v); // continue to remove other elements having value v
        return head;
    }

    head->next = removeNode(head->next, v);
    return head;
}

// Hàm đảo ngược danh sách
void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// Hàm hiển thị danh sách
void printList(Node* h) {
    Node* p = h;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}


int main() {
    char buff[100];
    int v, n, a;
    char cmd[10];
    scanf("%d", &n);
    for ( int i = 0; i< n; i++){
        scanf("%d", &a);
        addLast(a);
    }
   // printf("%d", head -> value);
  //  printf("%d",exists(10));
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "addlast") == 0) {
            scanf("%d", &v);
            addLast(v);
        } else if (strcmp(cmd, "addfirst") == 0) {
            scanf("%d", &v);
            addFirst(v);
        } else if (strcmp(cmd, "addafter") == 0) {
            int u;
            scanf("%d %d", &u, &v);
            addAfter(u, v);
        } else if (strcmp(cmd, "addbefore") == 0) {
            int u;
            scanf("%d %d", &u, &v);
            addBefore(u, v);
        } else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &v);
            head = removeNode(head, v);
        } else if (strcmp(cmd, "reverse") == 0) {
            reverseList();
        } else if (strcmp(cmd, "#") == 0) {
            break;
        }
    }

    printList(head);

    // Giải phóng bộ nhớ sau khi sử dụng
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
