/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>



typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* concatenate(Node* head1, Node* head2) {
    Node* current = NULL;
    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }

    current = head1;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = head2;

    return head1;
}
