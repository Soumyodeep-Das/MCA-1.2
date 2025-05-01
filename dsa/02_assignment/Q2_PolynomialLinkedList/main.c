#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct PolyNode {
    int coeff, pow;
    struct PolyNode* next;
};

typedef struct PolyNode PolyNode;

// Function prototypes
PolyNode* createPoly();
void printPoly(PolyNode* head);
PolyNode* addPoly(PolyNode* p1, PolyNode* p2);
PolyNode* subPoly(PolyNode* p1, PolyNode* p2);
PolyNode* mulPoly(PolyNode* p1, PolyNode* p2);
void freePoly(PolyNode* head);

int main() {
    int choice;
    PolyNode *p1 = NULL, *p2 = NULL, *result = NULL;
    while (1) {
        printf("\n--- Polynomial Linked List Menu ---\n");
        printf("1. Create first polynomial\n");
        printf("2. Create second polynomial\n");
        printf("3. Add polynomials\n");
        printf("4. Subtract polynomials\n");
        printf("5. Multiply polynomials\n");
        printf("6. Print first polynomial\n");
        printf("7. Print second polynomial\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                freePoly(p1);
                p1 = createPoly();
                break;
            case 2:
                freePoly(p2);
                p2 = createPoly();
                break;
            case 3:
                result = addPoly(p1, p2);
                printf("Sum: ");
                printPoly(result);
                freePoly(result);
                break;
            case 4:
                result = subPoly(p1, p2);
                printf("Difference: ");
                printPoly(result);
                freePoly(result);
                break;
            case 5:
                result = mulPoly(p1, p2);
                printf("Product: ");
                printPoly(result);
                freePoly(result);
                break;
            case 6:
                printf("First Polynomial: ");
                printPoly(p1);
                break;
            case 7:
                printf("Second Polynomial: ");
                printPoly(p2);
                break;
            case 0:
                freePoly(p1); freePoly(p2);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

// Create a polynomial linked list from user input (enter coeff=0 to end)
PolyNode* createPoly() {
    PolyNode *head = NULL, *tail = NULL, *newNode;
    int coeff, pow;
    printf("Enter terms as <coefficient> <power> (enter coeff=0 to end):\n");
    while (1) {
        printf("Term: ");
        scanf("%d%d", &coeff, &pow);
        if (coeff == 0) break;
        newNode = (PolyNode*)malloc(sizeof(PolyNode));
        newNode->coeff = coeff;
        newNode->pow = pow;
        newNode->next = NULL;
        if (!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printPoly(PolyNode* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    PolyNode* temp = head;
    int first = 1;
    while (temp) {
        if (!first && temp->coeff > 0) printf(" + ");
        if (temp->pow == 0)
            printf("%d", temp->coeff);
        else if (temp->pow == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
        first = 0;
    }
    printf("\n");
}

// Helper: insert term in decreasing order of power, combine like terms
PolyNode* insertTerm(PolyNode* head, int coeff, int pow) {
    if (coeff == 0) return head;
    PolyNode *prev = NULL, *curr = head;
    while (curr && curr->pow > pow) {
        prev = curr;
        curr = curr->next;
    }
    if (curr && curr->pow == pow) {
        curr->coeff += coeff;
        if (curr->coeff == 0) { // Remove node
            if (prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
        }
        return head;
    }
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = curr;
    if (prev) prev->next = newNode;
    else head = newNode;
    return head;
}

PolyNode* addPoly(PolyNode* p1, PolyNode* p2) {
    PolyNode* result = NULL;
    while (p1) {
        result = insertTerm(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        result = insertTerm(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

PolyNode* subPoly(PolyNode* p1, PolyNode* p2) {
    PolyNode* result = NULL;
    while (p1) {
        result = insertTerm(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        result = insertTerm(result, -p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

PolyNode* mulPoly(PolyNode* p1, PolyNode* p2) {
    PolyNode* result = NULL;
    for (PolyNode* a = p1; a; a = a->next) {
        for (PolyNode* b = p2; b; b = b->next) {
            result = insertTerm(result, a->coeff * b->coeff, a->pow + b->pow);
        }
    }
    return result;
}

void freePoly(PolyNode* head) {
    PolyNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
