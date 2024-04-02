#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct Node {
    int value;
    struct Node* previous;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

// Hàm khởi tạo danh sách
void initList() {
    head = NULL;
    tail = NULL;
}

// Hàm kiểm tra danh sách rỗng
int listEmpty() {
    return (head == NULL && tail == NULL);
}

// Hàm tạo node mới
Node* makeNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho node mới
    if (newNode != NULL) { // Kiểm tra xem việc cấp phát bộ nhớ có thành công hay không
        newNode->value = v;
        newNode->previous = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

// Hàm chèn một node vào cuối danh sách
void insertLast(int v) {
    Node* newNode = makeNode(v);

    if (listEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Hàm hiển thị toàn bộ danh sách từ head đến tail
void printListLeft2Right(){
    for(Node* current = head; current != NULL; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}

// Hàm hiển thị toàn bộ danh sách từ tail đến head
void printListRight2Left(){
    for(Node* current = tail; current != NULL; current = current->previous)
        printf("%d ", current->value);
    printf("\n");    
}


// Hàm tìm node có giá trị v trong danh sách
Node* findNode(int v) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == v) {
            return current; // Trả về con trỏ đến node có giá trị v
        }
        current = current->next;
    }
    return NULL; // Trả về NULL nếu không tìm thấy
}

// Hàm chèn một node có giá trị u vào trước node có giá trị v
void addBefore(int u, int v) {
    Node* newNode = makeNode(u);
    Node* foundNode = findNode(v);

    if (foundNode == NULL) {
        printf("Node có giá trị %d không tồn tại trong danh sách.\n", v);
        free(newNode);
        return;
    }

    if (foundNode->previous != NULL) {
        foundNode->previous->next = newNode;
        newNode->previous = foundNode->previous;
    } else {
        head = newNode;
    }

    newNode->next = foundNode;
    foundNode->previous = newNode;
}

// Hàm chèn một node có giá trị u vào sau node có giá trị v
void addAfter(int u, int v) {
    Node* newNode = makeNode(u);
    Node* foundNode = findNode(v);

    if (foundNode == NULL) {
        printf("Node có giá trị %d không tồn tại trong danh sách.\n", v);
        free(newNode);
        return;
    }

    newNode->previous = foundNode;
    newNode->next = foundNode->next;

    if (foundNode->next != NULL) {
        foundNode->next->previous = newNode;
    } else {
        tail = newNode;
    }

    foundNode->next = newNode;
}

// Hàm giải phóng bộ nhớ
void finalize() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    tail = NULL;
}

int main() {
    char buff[MAX_LEN];
    
    // Đọc dãy số vào bộ đệm
    fgets(buff, MAX_LEN, stdin);

    // Sử dụng strtok() để tách xâu bằng dấu khoảng cách
    char *token = strtok(buff, " ");

    // Tạo list
    while (token != NULL) {
        insertLast(atoi(token)); // Lấy số hiện tại
        token = strtok(NULL, " "); // Lấy số tiếp theo
    }

    // Hiển thị danh sách theo chiều xuôi
    printListLeft2Right();

    // Hiển thị danh sách theo chiều ngược
    printListRight2Left();

    // Nhập giá trị muốn xoá
    //printf("Nhập giá trị muốn xóa khởi danh sách: ");
    //scanf("%d", &v);

    // Xóa phần tử có giá trị v
    // head = removeNode(head, v);

    // Xoá hết các phần tử có giá trị v
    //head = removeAll(head, v);

    //printf("Dãy số sau khi xóa là:\n");
    //printList(head);

    //Node* newHead = reverse(head);

    //printf("Dãy số sau khi đảo ngược là:\n");
    //printList(newHead);

    // Giải phóng bộ nhớ sau khi sử dụng
    finalize();

    return 0;
}