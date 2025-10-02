#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 100003

typedef struct HashNode {
    char* key;
    int value;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[HASH_SIZE];

unsigned long hashFunc(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % HASH_SIZE;
}

int get(char* key) {
    unsigned long hashIndex = hashFunc(key);
    HashNode* node = hashTable[hashIndex];
    while (node) {
        if (strcmp(node->key, key) == 0) return node->value;
        node = node->next;
    }
    return 0;
}

void put(char* key, int value) {
    unsigned long hashIndex = hashFunc(key);
    HashNode* node = hashTable[hashIndex];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            node->value += value;
            return;
        }
        node = node->next;
    }

    node = (HashNode*)malloc(sizeof(HashNode));
    node->key = malloc(strlen(key) + 1);
    strcpy(node->key, key);
    node->value = value;
    node->next = hashTable[hashIndex];
    hashTable[hashIndex] = node;
}

void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

void checkMagazine(int magazine_count, char** magazine, int note_count, char** note) {
    for (int i = 0; i < HASH_SIZE; i++) hashTable[i] = NULL;

    for (int i = 0; i < magazine_count; i++) {
        put(magazine[i], 1);
    }

    for (int i = 0; i < note_count; i++) {
        if (get(note[i]) == 0) {
            printf("No\n");
            freeHashTable();
            return;
        }
        put(note[i], -1);
    }

    printf("Yes\n");
    freeHashTable();
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) return NULL;
    }

    if (data[data_length - 1] == '\n') data[data_length - 1] = '\0';
    return data;
}

char* ltrim(char* str) {
    while (*str && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}

int main() {
    char** first_multiple_input = split_string(rtrim(readline()));
    int m = parse_int(*(first_multiple_input + 0));
    int n = parse_int(*(first_multiple_input + 1));

    char** magazine_temp = split_string(rtrim(readline()));
    char** magazine = malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) magazine[i] = *(magazine_temp + i);

    char** note_temp = split_string(rtrim(readline()));
    char** note = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) note[i] = *(note_temp + i);

    checkMagazine(m, magazine, n, note);

    free(magazine);
    free(note);
    free(first_multiple_input);
    free(magazine_temp);
    free(note_temp);

    return 0;
}
