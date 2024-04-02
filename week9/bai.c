#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct Node {
    char name[MAX_LEN];
    float grade;
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
Node* makeNode(char* s, float v) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho node mới
    if (newNode != NULL) { // Kiểm tra xem việc cấp phát bộ nhớ có thành công hay không
        strcpy(newNode->name, s);
        newNode->previous = NULL;
        newNode->next = NULL;
        newNode->grade = v;
    }
    return newNode;
}

// Hàm chèn một node vào cuối danh sách
void insertLast(char* s,float v) {
    Node* newNode = makeNode(s, v);

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
        printf("%s ", current->name);
    printf("\n");
}
void swap(Node* a, Node* b) {
    float tempGrade = a->grade;
    a->grade = b->grade;
    b->grade = tempGrade;

    char tempName[MAX_LEN];
    strcpy(tempName, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tempName);
}

void SelectionSort(){
    for (Node* current = head; current != NULL; current = current->next){
        Node* min = current;
        for (Node* j = current->next; j != NULL; j = j->next){
            if (min->grade > j->grade) min = j;
        }
    char tempName[MAX_LEN];
    float tempGrade;

    strcpy(tempName, min->name);
    tempGrade = min->grade;

    strcpy(min->name, current->name);
    min->grade = current->grade;

    strcpy(current->name, tempName);
    current->grade = tempGrade;
    printListLeft2Right();
    }
}
void InsertionSort() {
    for (Node* k = head->next; k != NULL; k = k->next) {
        Node* last = k;
        Node* j = k -> previous;

        while (j != NULL && j->grade > last->grade) {
            char tempName[MAX_LEN];
            float tempGrade;

            strcpy(tempName, j->name);
            tempGrade = j->grade;

            strcpy(j->name, last->name);
            j->grade = last->grade;

            strcpy(last->name, tempName);
            last->grade = tempGrade;
            last = j;
            j = j ->previous;
        }

        printListLeft2Right();
    }
}


void BubbleSort(){
    int a;
    do{
        a = 0;
        for ( Node* i = head; i != tail; i = i->next){
            if ( i->grade > i->next->grade){
                char tempName[MAX_LEN];
                float tempGrade;

                strcpy(tempName, i->name);
                tempGrade = i->grade;

                strcpy(i->name, i->next->name);
                i->grade = i->next->grade;

                strcpy(i->next->name, tempName);
                i->next->grade = tempGrade;
                a = 1;
            }  
        }
        printListLeft2Right();
    } while ( a == 1);
}



// Hàm tìm node có giá trị v trong danh sách
Node* findNode(float v) {
    Node* current = head;
    while (current != NULL) {
        if (current->grade == v) {
            return current; // Trả về con trỏ đến node có giá trị v
        }
        current = current->next;
    }
    return NULL; // Trả về NULL nếu không tìm thấy
}

// Hàm chèn một node có giá trị u vào trước node có giá trị v
/*void addBefore(int u, int v) {
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
}*/

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
    char s[100];
    float v;
    // Đọc dãy số vào bộ đệm
    
    while(1){
        scanf("%s", s);
        if ( strcmp(s, "#") == 0 ) break;
        scanf(" %f", &v);
        if (v <= 10 && v >= 0) insertLast(s, v);
    }
    scanf("%s", s);
    if ( strcmp(s, "SelectionSort") == 0 ) SelectionSort();
    else if ( strcmp(s, "InsertionSort") == 0 ) InsertionSort();
    else if  ( strcmp(s, "BubbleSort") == 0 ) BubbleSort();
    else printf("Wrong Command");

    finalize();

    return 0;
}