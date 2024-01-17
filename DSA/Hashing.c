//hash table using linear probing
#include <stdio.h>
#define TABLE_SIZE 11

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int hashTable[], int key) {
    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        // Linear probing to handle collisions
        int i = 1;
        while (1) {
            int newIndex = (index + i) % TABLE_SIZE;
            if (hashTable[newIndex] == -1) {
                hashTable[newIndex] = key;
                break;
            }
            i++;
        }
    }
}

void printHashTable(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int keys[] = {83, 53, 64, 25, 39, 96, 12, 71};
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        insert(hashTable, keys[i]);
    }

    printHashTable(hashTable);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// #define TABLE_SIZE 11

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// int hashFunction(int key) {
//     return key % TABLE_SIZE;
// }

// void insert(int hashTable[], int key) {
//     int index = hashFunction(key);
//     struct Node* newNode = createNode(key);

//     if (hashTable[index] == NULL) {
//         hashTable[index] = newNode;
//     } else {
//         // Handle collision by adding to the linked list at the index
//         struct Node* current = hashTable[index];
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newNode;
//     }
// }

// void printHashTable(struct Node* hashTable[]) {
//     printf("Hash Table:\n");
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         printf("%d: ", i);
//         struct Node* current = hashTable[i];
//         while (current != NULL) {
//             printf("%d -> ", current->data);
//             current = current->next;
//         }
//         printf("NULL\n");
//     }
// }

// int main() {
//     int keys[] = {83, 53, 64, 25, 39, 96, 12, 71};
//     struct Node* hashTable[TABLE_SIZE];

//     for (int i = 0; i < TABLE_SIZE; i++) {
//         hashTable[i] = NULL;
//     }

//     for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
//         insert(hashTable, keys[i]);
//     }

//     printHashTable(hashTable);

//     return 0;
// }

