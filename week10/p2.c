#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} NumFreq;

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

#define HASH_SIZE 100003
HashNode* hashTable[HASH_SIZE];

unsigned long hashFunc(int key) {
    return key % HASH_SIZE;
}

void put(int key) {
    unsigned long hashIndex = hashFunc(key);
    HashNode* node = hashTable[hashIndex];
    while (node) {
        if (node->key == key) {
            node->value++;
            return;
        }
        node = node->next;
    }
    node = malloc(sizeof(HashNode));
    node->key = key;
    node->value = 1;
    node->next = hashTable[hashIndex];
    hashTable[hashIndex] = node;
}

int compare(const void* a, const void* b) {
    NumFreq* x = (NumFreq*)a;
    NumFreq* y = (NumFreq*)b;
    if (y->freq != x->freq) return y->freq - x->freq;
    return y->num - x->num;
}

void topKFrequent(int* arr, int n, int k) {
    for (int i = 0; i < HASH_SIZE; i++) hashTable[i] = NULL;
    for (int i = 0; i < n; i++) put(arr[i]);
    NumFreq* freqArr = malloc(n * sizeof(NumFreq));
    int size = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node) {
            freqArr[size].num = node->key;
            freqArr[size].freq = node->value;
            size++;
            node = node->next;
        }
    }
    qsort(freqArr, size, sizeof(NumFreq), compare);
    for (int i = 0; i < k; i++) printf("%d ", freqArr[i].num);
    printf("\n");
    free(freqArr);
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
}

int main() {
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    topKFrequent(arr, n, k);
    return 0;
}
