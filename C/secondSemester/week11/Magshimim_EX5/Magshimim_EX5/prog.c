/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
func rotate the node by k
runTime(k)
input:node and lenRotate
output:none
*/
void rotate(Node** head, int k) {
    Node* current = *head;
    int length = 1,i=0;
    if (!(k == 0 || *head == NULL)) {
        while (current->next != NULL) {
            current = current->next;
            length++;
        }
        k = k % length;

        if (!(k == 0 || *head == NULL)) {

            current->next = *head;

            current = *head;
            for (i = 1; i < length - k; i++) {
                current = current->next;
            }

            *head = current->next;
            current->next = NULL;
        }
    }
}

/*
func print the list
input:node
output:none
*/
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    int size = 0, i = 0, temp = 0, k = 0;
    Node* head = NULL;
    Node* curruct = NULL;
    Node* past = NULL;

    printf("How many nodes in list: ");
    scanf("%d", &size);
    getchar();
    for (i = 0; i < size; i++) {
        printf("Enter number: ");
        scanf("%d", &temp);
        getchar();
        curruct = createNode(temp);
        if (i == 0) {
            head = curruct;
        }
        else {
            past->next = curruct;
        }
        past = curruct;
    }

    printf("Enter number k: ");
    scanf("%d", &k);
    getchar();

    rotate(&head, k);

    printf("Rotated Linked list:\n");
    printList(head);

    freeList(&head);
    getchar();
    return 0;
}
