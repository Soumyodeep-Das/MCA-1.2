#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// Function prototypes
DNode* createList();
void printList(DNode* head);
DNode* insertFront(DNode* head, int data);
DNode* insertEnd(DNode* head, int data);
DNode* insertAfterK(DNode* head, int k, int data);
DNode* insertAfterValue(DNode* head, int value, int data);
DNode* insertBeforeK(DNode* head, int k, int data);
DNode* insertBeforeValue(DNode* head, int value, int data);
DNode* deleteFirst(DNode* head);
DNode* deleteLast(DNode* head);
DNode* deleteAfterK(DNode* head, int k);
DNode* deleteBeforeK(DNode* head, int k);
DNode* deleteKth(DNode* head, int k);
DNode* deleteByValue(DNode* head, int value);
DNode* reverseList(DNode* head);
DNode* sortList(DNode* head);
int searchElement(DNode* head, int value);
void freeList(DNode* head);

int main() {
    DNode* head = NULL;
    int choice, data, k, value, found;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create a linked list\n");
        printf("2. Print the content of the list\n");
        printf("3. Insert at front\n");
        printf("4. Insert at end\n");
        printf("5. Insert after k-th node\n");
        printf("6. Insert after node with value\n");
        printf("7. Insert before k-th node\n");
        printf("8. Insert before node with value\n");
        printf("9. Delete first node\n");
        printf("10. Delete last node\n");
        printf("11. Delete node after k-th node\n");
        printf("12. Delete node before k-th node\n");
        printf("13. Delete k-th node\n");
        printf("14. Delete node by value\n");
        printf("15. Reverse the list\n");
        printf("16. Sort the list\n");
        printf("17. Search for an element\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                freeList(head);
                head = createList();
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 5:
                printf("Enter k: ");
                scanf("%d", &k);
                printf("Enter value: ");
                scanf("%d", &data);
                head = insertAfterK(head, k, data);
                break;
            case 6:
                printf("Enter value to find: ");
                scanf("%d", &value);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                head = insertAfterValue(head, value, data);
                break;
            case 7:
                printf("Enter k: ");
                scanf("%d", &k);
                printf("Enter value: ");
                scanf("%d", &data);
                head = insertBeforeK(head, k, data);
                break;
            case 8:
                printf("Enter value to find: ");
                scanf("%d", &value);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                head = insertBeforeValue(head, value, data);
                break;
            case 9:
                head = deleteFirst(head);
                break;
            case 10:
                head = deleteLast(head);
                break;
            case 11:
                printf("Enter k: ");
                scanf("%d", &k);
                head = deleteAfterK(head, k);
                break;
            case 12:
                printf("Enter k: ");
                scanf("%d", &k);
                head = deleteBeforeK(head, k);
                break;
            case 13:
                printf("Enter k: ");
                scanf("%d", &k);
                head = deleteKth(head, k);
                break;
            case 14:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteByValue(head, value);
                break;
            case 15:
                head = reverseList(head);
                printf("List reversed.\n");
                break;
            case 16:
                head = sortList(head);
                printf("List sorted.\n");
                break;
            case 17:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = searchElement(head, value);
                if (found)
                    printf("Element found at position %d.\n", found);
                else
                    printf("Element not found.\n");
                break;
            case 0:
                freeList(head);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

// Create a doubly linked list from user input (enter -1 to end)
DNode* createList() {
    DNode *head = NULL, *tail = NULL, *newNode;
    int data;
    printf("Enter elements (-1 to end): ");
    while (scanf("%d", &data) && data != -1) {
        newNode = (DNode*)malloc(sizeof(DNode));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = tail;
        if (!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printList(DNode* head) {
    DNode* temp = head;
    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

DNode* insertFront(DNode* head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head) head->prev = newNode;
    return newNode;
}

DNode* insertEnd(DNode* head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    if (!head) {
        newNode->prev = NULL;
        return newNode;
    }
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

DNode* insertAfterK(DNode* head, int k, int data) {
    if (k <= 0) return head;
    DNode* temp = head;
    for (int i = 1; temp && i < k; i++) temp = temp->next;
    if (!temp) return head;
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

DNode* insertAfterValue(DNode* head, int value, int data) {
    DNode* temp = head;
    while (temp && temp->data != value) temp = temp->next;
    if (!temp) return head;
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

DNode* insertBeforeK(DNode* head, int k, int data) {
    if (k <= 1) return insertFront(head, data);
    DNode* temp = head;
    for (int i = 1; temp && i < k; i++) temp = temp->next;
    if (!temp) return head;
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev) temp->prev->next = newNode;
    temp->prev = newNode;
    if (temp == head) head = newNode;
    return head;
}

DNode* insertBeforeValue(DNode* head, int value, int data) {
    DNode* temp = head;
    while (temp && temp->data != value) temp = temp->next;
    if (!temp) return head;
    if (temp == head) return insertFront(head, data);
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    return head;
}

DNode* deleteFirst(DNode* head) {
    if (!head) return NULL;
    DNode* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    return head;
}

DNode* deleteLast(DNode* head) {
    if (!head) return NULL;
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else head = NULL;
    free(temp);
    return head;
}

DNode* deleteAfterK(DNode* head, int k) {
    if (k <= 0) return head;
    DNode* temp = head;
    for (int i = 1; temp && i < k; i++) temp = temp->next;
    if (!temp || !temp->next) return head;
    DNode* del = temp->next;
    temp->next = del->next;
    if (del->next) del->next->prev = temp;
    free(del);
    return head;
}

DNode* deleteBeforeK(DNode* head, int k) {
    if (k <= 1 || !head) return head;
    if (k == 2) return deleteFirst(head);
    DNode* temp = head;
    for (int i = 1; temp && i < k; i++) temp = temp->next;
    if (!temp || !temp->prev) return head;
    DNode* del = temp->prev;
    if (del->prev) del->prev->next = temp;
    else head = temp;
    temp->prev = del->prev;
    free(del);
    return head;
}

DNode* deleteKth(DNode* head, int k) {
    if (k <= 0) return head;
    DNode* temp = head;
    for (int i = 1; temp && i < k; i++) temp = temp->next;
    if (!temp) return head;
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

DNode* deleteByValue(DNode* head, int value) {
    DNode* temp = head;
    while (temp && temp->data != value) temp = temp->next;
    if (!temp) return head;
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

DNode* reverseList(DNode* head) {
    DNode *temp = NULL, *current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) head = temp->prev;
    return head;
}

DNode* sortList(DNode* head) {
    if (!head) return NULL;
    for (DNode* i = head; i->next; i = i->next) {
        for (DNode* j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                int t = i->data; i->data = j->data; j->data = t;
            }
        }
    }
    return head;
}

int searchElement(DNode* head, int value) {
    int pos = 1;
    DNode* temp = head;
    while (temp) {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    }
    return 0;
}

void freeList(DNode* head) {
    DNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
