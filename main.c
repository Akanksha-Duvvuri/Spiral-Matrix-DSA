#include <stdio.h>
#include <stdlib.h>
#include "sparse_utils.h"

typedef struct Node {
    int row;
    int col;
    int value;
    struct Node *next;
} Node;

Node *head = NULL;

void buildLinkedList() {
    head = NULL;
    Node *tail = NULL;

    for(int i = 0; i < lineCount; i++) {
        for(int j = 0; j < wordCount; j++) {
            if(matrix[i][j] != 0) {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->row   = i;
                newNode->col   = j;
                newNode->value = matrix[i][j];
                newNode->next  = NULL;

                if(head == NULL) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
    }
}

void printLinkedList() {
    printf("\n--- Linked List Sparse Representation ---\n");
    printf("%-6s %-6s %-8s %-15s\n", "Row", "Col", "Value", "Word");
    printf("------------------------------------------\n");

    Node *curr = head;
    int count = 0;
    while(curr != NULL) {
        printf("%-6d %-6d %-8d %-15s\n",
            curr->row,
            curr->col,
            curr->value,
            words[curr->col]);
        curr = curr->next;
        count++;
    }

    printf("\nTotal non-zero nodes: %d\n", count);

    int originalMemory = lineCount * wordCount * sizeof(int);
    int linkedMemory   = count * sizeof(Node);
    printf("\n--- Memory Comparison ---\n");
    printf("Original matrix memory : %d bytes\n", originalMemory);
    printf("Linked list memory     : %d bytes (%d nodes x %lu bytes)\n",
           linkedMemory, count, sizeof(Node));
    printf("Memory saved           : %.1f%%\n",
           100.0 * (originalMemory - linkedMemory) / originalMemory);
}

void freeLinkedList() {
    Node *curr = head;
    while(curr != NULL) {
        Node *tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    head = NULL;
}

void printAll() {
    printf("--- Original Text ---\n");
    for(int i = 0; i < lineCount; i++)
        printf("[%d] %s\n", i, lines[i]);

    printf("\n--- Vocabulary Index ---\n");
    for(int i = 0; i < wordCount; i++)
        printf("%d: %s\t", i, words[i]);

    printf("\n\n--- Sparse Matrix (Frequencies) ---\n");
    for(int i = 0; i < lineCount; i++) {
        for(int j = 0; j < wordCount; j++) {
            if(matrix[i][j] == 0) printf(". ");
            else printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    buildMatrix();
    printAll();
    buildLinkedList();
    printLinkedList();
    freeLinkedList();
    return 0;
}