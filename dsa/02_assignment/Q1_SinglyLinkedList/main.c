#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createList();
void printList(Node* head);
Node* insertFront(Node* head, int data);
Node* insertEnd(Node* head, int data);
Node* insertAfterK(Node* head, int k, int data);
Node* insertAfterValue(Node* head, int value, int data);
Node* insertBeforeK(Node* head, int k, int data);
Node* insertBeforeValue(Node* head, int value, int data);
Node* deleteFirst(Node* head);
Node* deleteLast(Node* head);
Node* deleteAfterK(Node* head, int k);
Node* deleteBeforeK(Node* head, int k);
Node* deleteKth(Node* head, int k);
Node* deleteByValue(Node* head, int value);
Node* reverseList(Node* head);
Node* sortList(Node* head);
int searchElement(Node* head, int value);
Node* mergeSortedLists(Node* l1, Node* l2);
Node* concatenateLists(Node* l1, Node* l2);
int areListsEqual(Node* l1, Node* l2);
void freeList(Node* head);

// Helper functions
typedef struct Pair {
    Node* l1;
    Node* l2;
} Pair;
Pair createTwoLists();

int main() {
    Node* head = NULL;
    int choice, data, k, value, found;
    Node *head2 = NULL, *merged = NULL;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
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
        printf("18. Merge two sorted lists\n");
        printf("19. Concatenate two lists\n");
        printf("20. Check if two lists are equal\n");
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
            case 18: {
                Pair p = createTwoLists();
                merged = mergeSortedLists(p.l1, p.l2);
                printf("Merged list: ");
                printList(merged);
                freeList(p.l1); freeList(p.l2); freeList(merged);
                break;
            }
            case 19: {
                Pair p = createTwoLists();
                merged = concatenateLists(p.l1, p.l2);
                printf("Concatenated list: ");
                printList(merged);
                freeList(p.l1); freeList(p.l2); freeList(merged);
                break;
            }
            case 20: {
                Pair p = createTwoLists();
                if (areListsEqual(p.l1, p.l2))
                    printf("Lists are equal.\n");
                else
                    printf("Lists are not equal.\n");
                freeList(p.l1); freeList(p.l2);
                break;
            }
            case 0:
                freeList(head);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

// Create a singly linked list from user input (enter -1 to end)
Node* createList() {
    Node *head = NULL, *tail = NULL, *newNode;
    int data;
    printf("Enter elements (-1 to end): ");
    while (scanf("%d", &data) && data != -1) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        if (!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* insertFront(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

Node* insertEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertAfterK(Node* head, int k, int data) {
    if (k <= 0) return head;
    Node* temp = head;
    for (int i = 1; temp && i < k; i++) temp = temp->next;
    if (!temp) return head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertAfterValue(Node* head, int value, int data) {
    Node* temp = head;
    while (temp && temp->data != value) temp = temp->next;
    if (!temp) return head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertBeforeK(Node* head, int k, int data) {
    if (k <= 1) return insertFront(head, data);
    Node* temp = head;
    for (int i = 1; temp && i < k-1; i++) temp = temp->next;
    if (!temp || !temp->next) return head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertBeforeValue(Node* head, int value, int data) {
    if (!head) return NULL;
    if (head->data == value) return insertFront(head, data);
    Node* temp = head;
    while (temp->next && temp->next->data != value) temp = temp->next;
    if (!temp->next) return head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteFirst(Node* head) {
    if (!head) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteLast(Node* head) {
    if (!head) return NULL;
    if (!head->next) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next && temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteAfterK(Node* head, int k) {
    if (k <= 0) return head;
    Node* temp = head;
    for (int i = 1; temp && i < k; i++) temp = temp->next;
    if (!temp || !temp->next) return head;
    Node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

Node* deleteBeforeK(Node* head, int k) {
    if (k <= 1 || !head) return head;
    if (k == 2) return deleteFirst(head);
    Node* temp = head;
    for (int i = 1; temp && i < k-2; i++) temp = temp->next;
    if (!temp || !temp->next || !temp->next->next) return head;
    Node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

Node* deleteKth(Node* head, int k) {
    if (k <= 0) return head;
    if (k == 1) return deleteFirst(head);
    Node* temp = head;
    for (int i = 1; temp && i < k-1; i++) temp = temp->next;
    if (!temp || !temp->next) return head;
    Node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

Node* deleteByValue(Node* head, int value) {
    if (!head) return NULL;
    if (head->data == value) return deleteFirst(head);
    Node* temp = head;
    while (temp->next && temp->next->data != value) temp = temp->next;
    if (!temp->next) return head;
    Node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* sortList(Node* head) {
    if (!head) return NULL;
    for (Node* i = head; i && i->next; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                int t = i->data; i->data = j->data; j->data = t;
            }
        }
    }
    return head;
}

int searchElement(Node* head, int value) {
    int pos = 1;
    Node* temp = head;
    while (temp) {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    }
    return 0;
}

Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy, *tail = &dummy;
    dummy.next = NULL;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1; l1 = l1->next;
        } else {
            tail->next = l2; l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

Node* concatenateLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    Node* temp = l1;
    while (temp->next) temp = temp->next;
    temp->next = l2;
    return l1;
}

int areListsEqual(Node* l1, Node* l2) {
    while (l1 && l2) {
        if (l1->data != l2->data) return 0;
        l1 = l1->next; l2 = l2->next;
    }
    return (!l1 && !l2);
}

void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Pair createTwoLists() {
    Pair p;
    printf("Create first list:\n");
    p.l1 = createList();
    printf("Create second list:\n");
    p.l2 = createList();
    return p;
}
