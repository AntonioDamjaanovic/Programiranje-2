#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char *ime;
    char *prezime;
    int id;
    float prosjek;
    struct student* nextNode;
}STUDENT;

void inputNodeData(STUDENT*);
float prosjekSvih(STUDENT*);
STUDENT* createSLList(void);
void traverseSLList(STUDENT*);
STUDENT* insertNewNodeSLList(STUDENT*);
STUDENT* searchSLList(STUDENT*, int);
void deleteNodeSLList(STUDENT**, STUDENT*);
STUDENT* deleteWholeSLList(STUDENT*);

int  main() {
    int n, i, x;
    STUDENT *headNode = NULL;
    STUDENT *targetNode = NULL;

    printf("Koliko studenata zelis unijeti:");
    scanf("%d", &n);

    headNode = createSLList();
    for (i = 0; i < n-1; i++) {
        headNode = insertNewNodeSLList(headNode);
    }

    printf("Unesite ID studenta kojeg trazite:");
    scanf("%d", &x);

    printf("REZULTATI:\n");
    traverseSLList(headNode);
    printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvih(headNode));

    targetNode = searchSLList(headNode, x);
    if (targetNode == NULL) {
        printf("Student s trazenim ID-em nije pronadjen!\n");
    }
    else {
        deleteNodeSLList(&headNode, targetNode);
        traverseSLList(headNode);
        printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvih(headNode));
    }
    headNode = deleteWholeSLList(headNode);

    return 0;
}

void inputNodeData(STUDENT* node) {
    node->ime = (char*)malloc(40 * sizeof(char));
    if (node->ime == NULL) {
        exit(-1);
    }
    node->prezime = (char*)malloc(40 * sizeof(char));
    if (node->prezime == NULL) {
        exit(-1);
    }
    scanf("%d", &node->id);
    scanf(" %39[^\n]", node->ime);
    scanf(" %39[^\n]", node->prezime);
    scanf("%f", &node->prosjek);
}

float prosjekSvih(STUDENT *node) {
    float sum = 0;
    int numOfStudents = 0;
    while(node) {
        numOfStudents++;
        sum = sum + node->prosjek;
        node = node->nextNode;
    }
    return sum / (float)numOfStudents;
}

STUDENT* createSLList() {
    STUDENT *headNode = (STUDENT*)calloc(1, sizeof(STUDENT));
    if (headNode == NULL) {
        return NULL;
    }
    else {
        inputNodeData(headNode);
        headNode->nextNode = NULL;
    }
    return headNode;
}

STUDENT* insertNewNodeSLList(STUDENT* headNode){
    STUDENT *newHeadNode = (STUDENT*)calloc(1, sizeof(STUDENT));
    if (newHeadNode == NULL) {
        return headNode;
    }
    else {
        inputNodeData(newHeadNode);
        newHeadNode->nextNode = headNode;
    }
    return newHeadNode;
}

void traverseSLList(STUDENT* node) {
    if (node == NULL) {
        perror("Greska");
        exit(-1);
    }
    else {
        while (node) {
            printf("ID: %d - %s %s, prosjek: %.2f\n", node->id, node->ime, node->prezime, node->prosjek);
            node = node->nextNode;
        }
    }
}

STUDENT* searchSLList(STUDENT* node, int ID) {
    while (node) {
        if (node->id == ID) {
            return node;
        }
        node = node->nextNode;
    }
    return NULL;
}

void deleteNodeSLList(STUDENT** headNode, STUDENT* targetNode) {
    if (targetNode == NULL) {
        printf("Ne postoji cvor za brisanje: %p\n", targetNode);
        return;
    }
    if (*headNode == targetNode) {
        *headNode = (*headNode)->nextNode;
        free(targetNode->ime);
        free(targetNode->prezime);
        free(targetNode);
    }
    else {
        STUDENT* traverseNode = *headNode;
        while (traverseNode->nextNode) {
            if (traverseNode->nextNode == targetNode) {
                traverseNode->nextNode = targetNode->nextNode;
                free(targetNode->ime);
                free(targetNode->prezime);
                free(targetNode);
                break;
            }
            traverseNode = traverseNode->nextNode;
        }
    }
}

STUDENT* deleteWholeSLList(STUDENT* traverseNode) {
    STUDENT* deleteNode = NULL;
    while (traverseNode) {
        deleteNode = traverseNode;
        free(deleteNode->ime);
        free(deleteNode->prezime);
        free(deleteNode);
        traverseNode = traverseNode->nextNode;
    }
    return NULL;
}