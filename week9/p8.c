#include <stdio.h>
#include <stdlib.h>

typedef struct HashNode {
    long long key;
    int value;
    struct HashNode* next;
} HashNode;

#define HASH_SIZE 100003

HashNode* hashTable[HASH_SIZE];

long long hashFunc(long long key) {
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

int get(long long key) {
    long long hashIndex = hashFunc(key);
    HashNode* node = hashTable[hashIndex];
    while (node) {
        if (node->key == key) return node->value;
        node = node->next;
    }
    return 0;
}

void put(long long key, int value) {
    long long hashIndex = hashFunc(key);
    HashNode* node = hashTable[hashIndex];
    while (node) {
        if (node->key == key) {
            node->value += value;
            return;
        }
        node = node->next;
    }
    node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = hashTable[hashIndex];
    hashTable[hashIndex] = node;
}

int findSubarray(int arr[], int n) {
    for (int i = 0; i < HASH_SIZE; i++) hashTable[i] = NULL;

    long long prefix_sum = 0;
    int count = 0;
    put(0, 1);  // base case

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        count += get(prefix_sum);
        put(prefix_sum, 1);
    }
    return count;
}

int main() {
    int arr1[] = {0, 0, 5, 5, 0, 0};
    printf("%d\n", findSubarray(arr1, 6));  // 6

    int arr2[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    printf("%d\n", findSubarray(arr2, 10)); // 4

    int arr3[] = {0};
    printf("%d\n", findSubarray(arr3, 1));  // 1

    return 0;
}
