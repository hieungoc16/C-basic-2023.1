    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_LEN 50

    typedef struct Node {
        char name[MAX_LEN];
        float grade;
        struct Node* previous;
        struct Node* next;
    } Node;

    Node* merge(Node* left, Node* right) {
        Node* result = NULL;
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        if (left->grade < right->grade) {
            result = left;
            result->next = merge(left->next, right);
            result->next->previous = result;
        } else {
            result = right;
            result->next = merge(left, right->next);
            result->next->previous = result;
        }
        return result;
    }
    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL)
            return head;
        Node* m = head;
        Node* fast = head->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                m = m->next;
                fast = fast->next;
            }
        }
        Node* left = head;
        Node* right = m->next;
        m->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }
    Node* insertNode(Node* head, const char* name, float grade) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        strcpy(newNode->name, name);
        newNode->grade = grade;
        newNode->previous = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            return newNode;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->previous = current;
        return head;
    }
    void freeList(Node* head) {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    int main() {
        Node* head = NULL;
        char buff[MAX_LEN];
        char s[100];
        float v;

        while (1) {
            scanf("%s", s);
            if (strcmp(s, "#") == 0)
                break;
            scanf(" %f", &v);
            if (v <= 10 && v >= 0)
                head = insertNode(head, s, v);
        }
        head = mergeSort(head);
        Node* current = head;
        while (current != NULL) {
            printf("%s ", current->name);
            current = current->next;
        }
        freeList(head);
        return 0;
    }