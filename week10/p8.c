#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CHAR_SIZE 26

typedef struct HashNode {
    char *key;
    int count;
    struct HashNode *next;
} HashNode;

#define HASH_SIZE 100003

HashNode *hashTable[HASH_SIZE];

unsigned long hashFunction(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % HASH_SIZE;
}

void insertHash(const char *key) {
    unsigned long hashIndex = hashFunction(key);
    HashNode *node = hashTable[hashIndex];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }
    node = malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->count = 1;
    node->next = hashTable[hashIndex];
    hashTable[hashIndex] = node;
}

int sherlockAndAnagrams(char *s) {
    int n = strlen(s);
    int total = 0;

    for (int len = 1; len < n; len++) {
        memset(hashTable, 0, sizeof(hashTable));
        for (int i = 0; i <= n - len; i++) {
            int freq[CHAR_SIZE] = {0};
            for (int j = 0; j < len; j++)
                freq[s[i + j] - 'a']++;

            char key[CHAR_SIZE * 4] = {0};
            for (int k = 0; k < CHAR_SIZE; k++) {
                char buf[5];
                sprintf(buf, "%d#", freq[k]);
                strcat(key, buf);
            }

            unsigned long hashIndex = hashFunction(key);
            HashNode *node = hashTable[hashIndex];
            int found = 0;
            while (node) {
                if (strcmp(node->key, key) == 0) {
                    total += node->count;
                    node->count++;
                    found = 1;
                    break;
                }
                node = node->next;
            }
            if (!found) insertHash(key);
        }
        for (int h = 0; h < HASH_SIZE; h++) {
            HashNode *node = hashTable[h];
            while (node) {
                HashNode *tmp = node;
                node = node->next;
                free(tmp->key);
                free(tmp);
            }
        }
    }
    return total;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        char s[10002];
        scanf("%s", s);
        printf("%d\n", sherlockAndAnagrams(s));
    }
    return 0;
}
