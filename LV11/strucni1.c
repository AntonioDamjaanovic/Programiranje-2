#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char *ime;
    char *prezime;
    int id;
    struct student* next;
} STUDENT;

STUDENT* loadStudent(FILE *file) {
    STUDENT *student = malloc(sizeof(STUDENT));
    student->ime = malloc(50);
    student->prezime = malloc(50);
    fscanf(file, "%s %s %d", student->ime, student->prezime, &student->id);
    student->next = NULL;
    
    return student;
}

int printAllStudents(STUDENT *traverseNode){
    int counter = 0;
    if (traverseNode == NULL)
        return -1;
    else {
        while (traverseNode) {
            counter++;
            printf("Ime: %s, Prezime: %s, ID: %d\n", traverseNode->ime, traverseNode->prezime, traverseNode->id);
            traverseNode = traverseNode->next;
        }
    }
    return counter;
}

STUDENT* findStudent(STUDENT *traverseNode, int id){
    while (traverseNode) {
        if (traverseNode->id == id){
            return traverseNode;
        }
        else {
            traverseNode = traverseNode->next;
        }
    }
    return NULL;
}

void deleteStudent(STUDENT **headNode, STUDENT *targetNode){
    if (*headNode == targetNode) {
        *headNode = (*headNode)->next;
        free(targetNode);
        printf("Oslobodjen cvor.\n");
    }
    else {
        STUDENT *traverseNode = *headNode;
        while (traverseNode->next) {
            if (traverseNode->next == targetNode){
                traverseNode->next = targetNode->next;
                free(targetNode);
                printf("Oslobodjen cvor.\n");
                break;
            }
            traverseNode = traverseNode->next;
        }
    }
}

STUDENT* deleteAllStudets(STUDENT *traverseNode){
    STUDENT *deleteNode = NULL;
    while (traverseNode) {
        deleteNode = traverseNode;
        traverseNode = traverseNode->next;
        free(deleteNode);
        printf("Oslobodjen chvor.\n");
    }
    return NULL;
}

int main() {
    FILE *file = fopen("studenti.txt", "r");
    if (file == NULL) {
        printf("Ne mogu otvoriti datoteku.\n");
        return 1;
    }
    STUDENT *head = NULL, *temp = NULL;
    for (int i = 0; i < 5; i++) {
        STUDENT *new_student = loadStudent(file);
        new_student->next = head;
        head = new_student;
    }
    printf("Ukupno studenata: %d\n", printAllStudents(head));
    STUDENT *targetNode = findStudent(head, 3);
    if (targetNode == NULL) {
        return 1;
    }
    deleteStudent(&head, targetNode);
    printf("Ukupno studenata: %d\n", printAllStudents(head));

    head = deleteAllStudets(head);

    fclose(file);
    return 0;
}