#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

// Định nghĩa cấu trúc Node
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

// Hàm chèn một Node vào cuối danh sách
Node* insertLast(Node* head, int v) {
    Node* p = head;

    // Trường hợp danh sách rỗng
    if (head == NULL) {
        return makeNode(v);
    }

    // Trường hợp thông thường
    while (p->next != NULL) {
        p = p->next;
    }

    Node* q = makeNode(v);
    p->next = q;

    return head;
}

// Hàm hiển thị danh sách
void printList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}
Node* reverse(Node *head){
    Node* p = head;
    Node* pp = NULL;
    Node* np = NULL;
    while(p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}


Node* insertvaluemax(int u, int max) {
    Node* newNode = makeNode(u);

    if (head->value == max) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->value == max) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

}


int main() {
    char buff[MAX_LEN];
    int v, n, max = 0; 
    
    // Đọc dãy số vào bộ đệm
    fgets(buff, MAX_LEN, stdin);

    // Sử dụng strtok() để tách xâu bằng dấu khoảng cách
    char *token = strtok(buff, " ");

    // Mặc định danh sách có một node với giá trị 0
    // Tạo list (nếu dãy không rỗng)
    while (token != NULL) {
        head = insertLast(head, atoi(token)); // Lấy số hiện tại
        if (atoi(token) > max) max = atoi(token);
        token = strtok(NULL, " "); // Lấy số tiếp theo
    }
    
    scanf("%d", &n);
    insertvaluemax(n, max);
    if (strlen(buff) == 1 && buff[0] == '\n'){
        Node* newHead = reverse(head);
        printList(newHead);
    } else{
    // Hiển thị danh sách
    printList(head);
    }
    // Giải phóng bộ nhớ sau khi sử dụng
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
