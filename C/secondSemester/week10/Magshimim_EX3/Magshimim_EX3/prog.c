#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 50
#define NUMBER_OF_FRIENDS 3

typedef struct Person {
    char name[SIZE];
    int age;
    struct Person* next;
} Person;

Person* createPerson(char name[SIZE], int age);
void printQueue(Person* head);
int lenOfQue(Person* head);
void addToQueue(Person** head, char name[SIZE], int age, char friends[NUMBER_OF_FRIENDS][SIZE]);
void removeFromQueue(Person** head, char name[SIZE]);
void vip(Person** head, char name[SIZE], int age);
void search(Person* head, char name[SIZE]);
void reverseQueue(Person** head);
void myFgets(char str[SIZE], int size);

int main() {
    Person* head = NULL;
    int choice = 0;
    char name[SIZE];
    int age = 0;
    char friends[NUMBER_OF_FRIENDS][SIZE];

    do {
        printf("\nMenu:\n");
        printf("1. Print queue\n");
        printf("2. Add person to queue\n");
        printf("3. Remove person from queue\n");
        printf("4. VIP\n");
        printf("5. Search in queue\n");
        printf("6. Reverse queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("number of persons:%d  \n", lenOfQue(head));
            printQueue(head);
            break;
        case 2:
            printf("Enter name: ");
            myFgets(name, SIZE);
            printf("Enter age: ");
            scanf("%d", &age);
            getchar();

            for (int i = 0; i < NUMBER_OF_FRIENDS; i++) {
                printf("Enter friend %d: ", i + 1);
                myFgets(friends[i], SIZE);
            }
            addToQueue(&head, name, age, friends);
            break;
        case 3:
            printf("Enter name to remove: ");
            myFgets(name, SIZE);
            removeFromQueue(&head, name);
            break;
        case 4:
            printf("Enter VIP name: ");
            myFgets(name, SIZE);
            printf("Enter age: ");
            scanf("%d", &age);
            vip(&head, name, age);
            break;
        case 5:
            printf("Enter name to search: ");
            myFgets(name, SIZE);
            search(head, name);
            break;
        case 6:
            reverseQueue(&head);
            break;
        case 7:
            while (head != NULL) {
                Person* temp = head;
                head = head->next;
                free(temp);
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);


    getchar();
    return 0;
}

/*
func create person in queue
input: head of the queue
outpout:none
*/
Person* createPerson(char name[SIZE], int age) {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->next = NULL;
    return newPerson;
}

/*
func return size of the queue
input: head of the queue
outpout:size of the queue
*/
int lenOfQue(Person* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + lenOfQue(head->next);
}

/*
func printing the queue
input: head of the queue
outpout:size of the queue
*/
void printQueue(Person* head) {
    if (head != NULL) {
        printf("%s, Age: %d\n", head->name, head->age);
        printQueue(head->next);
    }
}

/*
func add person to queue
input: head of the queue and name age friends of person
outpout:none
*/
void addToQueue(Person** head, char name[SIZE], int age, char friends[NUMBER_OF_FRIENDS][SIZE]) {
    Person* newPerson = createPerson(name, age);
    if (*head == NULL) {
        *head = newPerson;
    }
    else {
        Person* current = *head;
        Person* prev = NULL;
        bool inserted = false;

        while (current != NULL && !inserted) {
            for (int i = 0; i < NUMBER_OF_FRIENDS; i++) {
                if (strcmp(current->name, friends[i]) == 0) {
                    newPerson->next = current->next;
                    current->next = newPerson;
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                prev = current;
                current = current->next;
            }
        }

        if (!inserted) {
            prev->next = newPerson;
        }
    }
}


/*
func remove person the queue
input: head of the queue name of person
outpout:none
*/
void removeFromQueue(Person** head, char name[SIZE]) {
    Person* current = *head;
    Person* prev = NULL;
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Person not found in queue\n");
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    }
    else {
        prev->next = current->next;
    }
    free(current);
}

/*
func put vip person to queue
input: head of the queue name of per and age
outpout:none
*/
void vip(Person** head, char name[SIZE], int age) {
    Person* newPerson = createPerson(name, age);
    newPerson->next = *head;
    *head = newPerson;
}

/*
func sarch the person
input: head of the queue and name of the person
outpout:none
*/
void search(Person* head, char name[SIZE]) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("%s is in the queue\n", name);
            break;
        }
        head = head->next;
    }
    printf("%s is not in the queue\n", name);
}

/*
func revers the queue
input: head of the queue
outpout:none
*/
void reverseQueue(Person** head) {
    Person* prev = NULL;
    Person* current = *head;
    Person* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/*
func get string 
input: size and place in memorey
outpout:none
*/
void myFgets(char str[SIZE], int size) {
    if (fgets(str, size, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}
