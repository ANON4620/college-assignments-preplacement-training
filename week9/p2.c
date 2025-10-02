#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

struct Hash {
    int bucket_count;
    struct Node** table;
};

struct Hash* createHash(int buckets) {
    struct Hash* h = (struct Hash*)malloc(sizeof(struct Hash));
    h->bucket_count = buckets;
    h->table = (struct Node**)malloc(buckets * sizeof(struct Node*));
    for (int i = 0; i < buckets; i++) {
        h->table[i] = NULL;
    }
    return h;
}

int getHashIndex(struct Hash* h, int key) {
    return key % h->bucket_count;
}

void insert(struct Hash* h, int key) {
    int index = getHashIndex(h, key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = h->table[index];
    h->table[index] = newNode;
}

void removeKey(struct Hash* h, int key) {
    int index = getHashIndex(h, key);
    struct Node* curr = h->table[index];
    struct Node* prev = NULL;
    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) {
                h->table[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void display(struct Hash* h) {
    for (int i = 0; i < h->bucket_count; i++) {
        printf("%d", i);
        struct Node* curr = h->table[i];
        while (curr != NULL) {
            printf(" --> %d", curr->key);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    int keys[] = {7, 18, 12, 25};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct Hash* hash_table = createHash(7);

    for (int i = 0; i < n; i++) {
        insert(hash_table, keys[i]);
    }

    removeKey(hash_table, 12);
    display(hash_table);

    return 0;
}
