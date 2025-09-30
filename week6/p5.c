#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *next, *pre;
} Node;

typedef struct LRUCache {
    int capacity, count;
    Node *head, *tail;
    Node **hashmap; // hashmap: array of Node*
} LRUCache;

// Helper: Create a new node
Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = node->pre = NULL;
    return node;
}

// Helper: Remove a node from the linked list
void removeNode(LRUCache* cache, Node* node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
}

// Helper: Add node right after head (front of LRU list)
void addNodeToFront(LRUCache* cache, Node* node) {
    node->next = cache->head->next;
    node->pre = cache->head;
    cache->head->next->pre = node;
    cache->head->next = node;
}

// Create LRUCache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->count = 0;

    cache->head = createNode(0, 0); // dummy head
    cache->tail = createNode(0, 0); // dummy tail
    cache->head->next = cache->tail;
    cache->tail->pre = cache->head;

    // Simple hashmap: fixed size large enough for keys (can be optimized with hash function)
    cache->hashmap = (Node**)calloc(10001, sizeof(Node*)); // keys up to 10000

    return cache;
}

// GET operation
int lRUCacheGet(LRUCache* cache, int key) {
    Node* node = cache->hashmap[key];
    if (node == NULL) return -1;

    removeNode(cache, node);
    addNodeToFront(cache, node);

    return node->value;
}

// PUT operation
void lRUCachePut(LRUCache* cache, int key, int value) {
    Node* node = cache->hashmap[key];

    if (node != NULL) {
        node->value = value;
        removeNode(cache, node);
        addNodeToFront(cache, node);
    } else {
        Node* newNode = createNode(key, value);
        cache->hashmap[key] = newNode;
        addNodeToFront(cache, newNode);
        cache->count++;

        if (cache->count > cache->capacity) {
            Node* lru = cache->tail->pre;
            removeNode(cache, lru);
            cache->hashmap[lru->key] = NULL;
            free(lru);
            cache->count--;
        }
    }
}

// Free memory
void lRUCacheFree(LRUCache* cache) {
    Node* curr = cache->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(cache->hashmap);
    free(cache);
}
