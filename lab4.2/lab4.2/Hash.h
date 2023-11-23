#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>

struct Node {
    int key;
    int value;
};

struct HashTable {
    Node* array;
    int size;
    int count;
};

int hashFunction(int key, int size);

void HashInsert(HashTable* table, int key, int value);

int HashSearch(HashTable* table, int key);

void HashDelete(HashTable* table, int key);

void HashShow(HashTable* table);

int quadraticProbe(int key, int i, int size);

int doubleHash(int key, int i, int size);

#endif // HASH_H