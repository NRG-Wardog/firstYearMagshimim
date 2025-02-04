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

Node* findKthFromEnd(Node* head, int k);
void freeList(Node** head);
void printListFromKth(Node* head, int k);
Node* createNode(int data);

int main()
{
    int size=0,i=0,temp=0,k=0;
    Node* head = NULL;
    Node* curruct = NULL;
    Node* past = NULL;

    printf("how many node in list:");
    scanf("%d",&size);
    getchar();
    for (i = 0;i < size;i++)
    {
        printf("enter number: ");
        scanf("%d", &temp);
        getchar();
        curruct = createNode(temp);
        if(i==0)
        {
            head = curruct;
        }
        else
        {
            past->next = curruct;
        }
        past = curruct;
    }
    printf("enter number k:");
    scanf("%d", &k);
    getchar();
    printListFromKth(head, k);

    freeList(&head);
	getchar();
	return 0;
}


/*
func use 2 pointer to go k of last
runTime o(n)
input:head of the struc and number k
output:pointer for struct
*/
Node* findKthFromEnd(Node* head, int k)
{
    Node* first = head;
    Node* second = head;
    int i = 0;
    for (i = 0; i < k; ++i)
    {
        if (first == NULL)
        {
            return NULL;
        }
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second;
}

/*
func print the list k
input:head and k
output:none
*/
void printListFromKth(Node* head, int k) {
    Node* kthNode = findKthFromEnd(head, k);
    if (kthNode == NULL) {
        printf("The list has less than %d .\n", k);
        return;
    }

    Node* current = kthNode;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/*
func create new node
input: data
output:data
*/
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
func free the list
input:head address
output:none
*/
void freeList(Node** head) {
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
