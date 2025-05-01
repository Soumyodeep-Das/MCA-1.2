#include <stdio.h>
#include <stdlib.h>

struct dynamic_array
{
    int data;
    struct dynamic_array* next;
} typedef darray;

darray* head;

darray* createNode(int);

void createArray(int);
void displayArray();
int countArraySize();
void reverseArray();
void findIndicesOfAnArrayElement();
int findArrayElementByIndex(int);
void insertElementIntoArray(int);
void deleteElementByIndex();
void deleteArray();
void mergeArray();
void splitArray();
void sortArray();

int main() {
    int choice, size, idx, newElement;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Count Array Size\n");
        printf("4. Reverse Array\n");
        printf("5. Find Indices of an Array Element\n");
        printf("6. Find Array Element by Index\n");
        printf("7. Insert Element into Array\n");
        printf("8. Delete Element by Index\n");
        printf("9. Delete Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter size of the array: ");
                scanf("%d", &size);
                createArray(size);
                break;
            case 2:
                displayArray();
                break;
            case 3:
                printf("\nSize of the array is %d\n", countArraySize());
                break;
            case 4:
                reverseArray();
                printf("\nArray reversed.\n");
                break;
            case 5:
                findIndicesOfAnArrayElement();
                break;
            case 6:
                printf("\nEnter index: ");
                scanf("%d", &idx);
                printf("\nElement at %dth index is %d\n", idx, findArrayElementByIndex(idx));
                break;
            case 7:
                printf("\nEnter new element: ");
                scanf("%d", &newElement);
                insertElementIntoArray(newElement);
                printf("\nElement %d inserted into the array.\n", newElement);
                break;
            case 8:
                printf("\nEnter index to delete element: ");
                scanf("%d", &idx);
                deleteElementByIndex(idx);
                printf("\nElement at index %d deleted from the array.\n", idx);
                break;
            case 9:
                deleteArray();
                printf("\nArray deleted.\n");
                break;
            case 0:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}


darray* createNode(int value){
    darray* newNode = (darray*)malloc(sizeof(darray));
    if (newNode == NULL){
        printf("\nMemory Allocation Failed\n");
        exit(1);
    }
    else {
        newNode->data=value;
        newNode->next=NULL;
        return newNode;
    }
}

void createArray(int size){
    if (size<=0){
        printf("\nKindly Enter a value greater than 0\n");
    } else {
        int val;
        darray* temp = NULL;
        printf("\nEnter Values : ");
        for(int i=0; i<size; i++){
            scanf("%d", &val);
            darray* node = createNode(val);
            if (head == NULL) {
                head = node;
                temp = head;
            } else {
                temp->next = node;
                temp = node;
            }
        }
    }
}

void displayArray(){
    darray* temp=head;
    printf("\nArray elements are:");
    while(temp!=NULL){
        printf("\t%d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int countArraySize(){
    darray* temp=head;
    int size=0;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}

void reverseArray(){
    darray* prev = NULL;
    darray* current = head;
    darray* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void findIndicesOfAnArrayElement(){
    printf("\nEnter number to search indices : ");
    int val;
    scanf(" %d", &val);
    darray* temp=head;
    int i=0;
    printf("\nIndices are : ");
    int count=0;
    while(temp!=NULL){
        if(temp->data==val){
            printf("\t%d", i);
            count++;
        }
        temp=temp->next;
        i++;
    }
    if(count==0)
        printf("Element not Found");
    printf("\n");
}

int findArrayElementByIndex(int index){
    darray* temp=head;
    int i=0;
    while(temp!=NULL){
        if(i==index)
            return temp->data;
        temp=temp->next;
        i++;
    }
    return 0;
}

void insertElementIntoArray(int val){
    darray* node = createNode(val);

    darray* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=node;
}

void deleteElementByIndex(int index){
    darray* temp=head;
    darray* prev;
    while(index--){
        prev=temp;
        temp=temp->next;
    }

    prev->next=temp->next;

}

void deleteArray(){
    darray* temp=head;
    darray* prev;

    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
        free(prev);
    }
}