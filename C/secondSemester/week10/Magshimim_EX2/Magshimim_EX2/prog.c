/*********************************
* Class: MAGSHIMIM C2            *
* Week:                          *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 21

typedef struct personNode {
    char name[SIZE];
    int age;
    struct personNode* next;
} personNode;

personNode* createPersonNode(char name[SIZE], int age);
void cleaner(personNode** head);
int listLength(personNode* head);
personNode* copyList(personNode* head);

int main(void)
{
    int i = 0, persons = 0, age = 0;
    char name[SIZE];

    personNode* head = NULL;
    personNode* tail = NULL;
    personNode* newPerson = NULL;
    personNode* current = NULL;
    personNode* copiedList = NULL;

    printf("Enter number of persons you want: ");
    scanf("%d", &persons);
    getchar(); // Consume newline character left in the buffer

    for (i = 0; i < persons; i++)
    {
        printf("Enter name: ");
        scanf("%s", name);
        getchar(); // Consume newline character left in the buffer
        printf("Enter age: ");
        scanf("%d", &age);
        getchar(); // Consume newline character left in the buffer

        newPerson = createPersonNode(name, age);

        if (newPerson == NULL) {
            printf("Memory allocation failed\n");
            cleaner(&head);
            return 1;
        }

        if (head == NULL) {
            head = newPerson;
            tail = newPerson;
        }
        else {
            tail->next = newPerson;
            tail = newPerson;
        }
    }

    current = head;
    printf("Number of persons: %d\n", persons);
    while (current != NULL) {
        printf("%s, %d\n", current->name, current->age);
        current = current->next;
    }

    int length = listLength(head);
    printf("Length of the list: %d\n", length);

    copiedList = copyList(head);
    printf("Copied list:\n");
    current = copiedList;
    while (current != NULL) {
        printf("%s, %d\n", current->name, current->age);
        current = current->next;
    }

    cleaner(&head);
    cleaner(&copiedList);
    getchar();
    return 0;
}

/*
func create person
input:name,age
output:person
*/
personNode* createPersonNode(char name[SIZE], int age)
{
    personNode* newPerson = (personNode*)malloc(sizeof(personNode));
    if (newPerson == NULL) {
        return NULL;
    }
    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->next = NULL;
    return newPerson;
}

/*
func deleting persons
input:addres of persons head
output:none
*/
void cleaner(personNode** head)
{
    personNode* current = NULL;
    while (*head != NULL) {
        current = *head;
        *head = (*head)->next;
        free(current);
    }
}

/*
func counting len
input:person head
output:len
*/
int listLength(personNode* head)
{
    if (head == NULL) {
        return 0;
    }
    return 1 + listLength(head->next);
}

/*
func copy persons
input:head
output:new head
*/
personNode* copyList(personNode* head)
{
    if (head == NULL) {
        return NULL;
    }
    personNode* newHead = createPersonNode(head->name, head->age);
    if (newHead == NULL) {
        return NULL;
    }
    newHead->next = copyList(head->next);
    return newHead;
}
