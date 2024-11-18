#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[50];
    int count;
    struct Node* next;
} Node;

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

void addWord(Node** head, char* word) {
    Node* current = *head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    Node* newNode = createNode(word);
    newNode->next = *head;
    *head = newNode;
}

void removeDuplicate(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->word, current->next->word) == 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else {
            current = current->next;
        }
    }
}

void findMostFrequent(Node* head) {
    Node* current = head;
    Node* mostFrequent = head;
    while (current != NULL) {
        if (current->count > mostFrequent->count) {
            mostFrequent = current;
        }
        current = current->next;
    }
    printf("Most frequent word: %s\n", mostFrequent->word);
}

int countWords(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s (%d)\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    // Add your sentence here
    char sentence[] = "Một câu tiếng việt cấu thành từ nhiều từ khác nhau từ xanh xanh xanh xanh";
    char* word = strtok(sentence, " ");

    while (word != NULL) {
        addWord(&head, word);
        word = strtok(NULL, " ");
    }

    printf("Original list:\n");
    printList(head);

    removeDuplicate(head);

    printf("\nList after removing duplicates:\n");
    printList(head);

    findMostFrequent(head);

    int wordCount = countWords(head);
    printf("\nTotal words: %d\n", wordCount);

    return 0;
}
