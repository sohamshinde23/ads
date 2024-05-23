#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

void linearProbing(int *hashTable, int size, int key);
void quadraticProbing(int *hashTable, int size, int key);
void printTable(int *hashTable, int size);

void linearProbing(int *hashTable, int size, int key) {
    int index = key % size;
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % size;
        if (index == originalIndex) {
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

void quadraticProbing(int *hashTable, int size, int key) {
    int index = key % size;
    int i = 1;
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (originalIndex + i * i) % size;
        if (index == originalIndex) {
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
        i++;
    }
    hashTable[index] = key;
}

void printTable(int *hashTable, int size) {
    for (int i = 0; i < size; i++) {
        if (hashTable[i] == -1) {
            printf("%d: empty\n", i);
        } else {
            printf("%d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int hashTableLinear[TABLE_SIZE];
    int hashTableQuadratic[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTableLinear[i] = -1;   
        hashTableQuadratic[i] = -1;
    }

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int keys[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    for (int i = 0; i < n; i++) {
        linearProbing(hashTableLinear, TABLE_SIZE, keys[i]);
    }
    for (int i = 0; i < n; i++) {
        quadraticProbing(hashTableQuadratic, TABLE_SIZE, keys[i]);
    }

    printf("Hash Table using Linear Probing:\n");
    printTable(hashTableLinear, TABLE_SIZE);

    printf("\nHash Table using Quadratic Probing:\n");
    printTable(hashTableQuadratic, TABLE_SIZE);

    return 0;
}
