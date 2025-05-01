#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void josephus2DArray(int n, int k);
void josephusCircularLL(int n, int k);
void josephusCircularDLL(int n, int k);

// Node structures
struct Node {
    int data;
    struct Node* next;
};
struct DNode {
    int data;
    struct DNode* prev, *next;
};

typedef struct Node Node;
typedef struct DNode DNode;

int main() {
    int choice, n, k;
    while (1) {
        printf("\n--- Josephus Problem Menu ---\n");
        printf("1. Solve using 2D Array\n");
        printf("2. Solve using Circular Linked List\n");
        printf("3. Solve using Circular Doubly Linked List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        printf("Enter number of people (n): ");
        scanf("%d", &n);
        printf("Enter step (k): ");
        scanf("%d", &k);
        switch (choice) {
            case 1:
                josephus2DArray(n, k);
                break;
            case 2:
                josephusCircularLL(n, k);
                break;
            case 3:
                josephusCircularDLL(n, k);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

// Josephus Problem using 2D Array
void josephus2DArray(int n, int k) {
    if (n <= 0 || k <= 0) {
        printf("Invalid input.\n");
        return;
    }
    int *people = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) people[i] = 1; // 1 means alive
    int count = n, idx = 0, step = 0;
    while (count > 1) {
        if (people[idx]) step++;
        if (step == k) {
            people[idx] = 0;
            count--;
            step = 0;
        }
        idx = (idx + 1) % n;
    }
    for (int i = 0; i < n; i++) {
        if (people[i]) {
            printf("Survivor (2D Array): Position %d\n", i + 1);
            break;
        }
    }
    free(people);
}

// Josephus Problem using Circular Singly Linked List
void josephusCircularLL(int n, int k) {
    if (n <= 0 || k <= 0) {
        printf("Invalid input.\n");
        return;
    }
    Node *head = NULL, *prev = NULL;
    // Create circular linked list
    for (int i = 1; i <= n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = i;
        if (!head) head = newNode;
        else prev->next = newNode;
        prev = newNode;
    }
    prev->next = head;
    Node *ptr = head, *last = prev;
    while (ptr != ptr->next) {
        for (int i = 1; i < k; i++) {
            last = ptr;
            ptr = ptr->next;
        }
        last->next = ptr->next;
        free(ptr);
        ptr = last->next;
    }
    printf("Survivor (Circular LL): Position %d\n", ptr->data);
    free(ptr);
}

// Josephus Problem using Circular Doubly Linked List
void josephusCircularDLL(int n, int k) {
    if (n <= 0 || k <= 0) {
        printf("Invalid input.\n");
        return;
    }
    DNode *head = NULL, *tail = NULL;
    // Create circular doubly linked list
    for (int i = 1; i <= n; i++) {
        DNode *newNode = (DNode *)malloc(sizeof(DNode));
        newNode->data = i;
        if (!head) {
            head = newNode;
            newNode->prev = newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }
    DNode *ptr = head;
    int count = n;
    while (count > 1) {
        for (int i = 1; i < k; i++) ptr = ptr->next;
        // Remove ptr
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        DNode *toFree = ptr;
        ptr = ptr->next;
        free(toFree);
        count--;
    }
    printf("Survivor (Circular DLL): Position %d\n", ptr->data);
    free(ptr);
}
