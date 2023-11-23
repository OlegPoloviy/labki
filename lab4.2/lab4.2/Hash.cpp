#include <iostream>
#include "Hash.h"

using namespace std;

// Обчислює хеш-функцію
int hashFunction(int key, int size) {
    return key % size;
}

// Вставляє елемент у хеш-таблицю
void HashInsert(HashTable* table, int key, int value) {
    int i = 0;
    int j = hashFunction(key, table->size);

    while (i < table->size) {
        if (table->array[j].key == -1) {
            table->array[j].key = key;
            table->array[j].value = value;
            table->count++;
            return;
        }
        i++;
        j = (j + 1) % table->size;
    }

    cout << "Хеш-таблиця переповнена" << endl;
}

// Пошук елемента в хеш-таблиці
int HashSearch(HashTable* table, int key) {
    int i = 0;
    int j = hashFunction(key, table->size);

    while (i < table->size && table->array[j].key != -1) {
        if (table->array[j].key == key) {
            return table->array[j].value;
        }
        i++;
        j = (j + 1) % table->size;
    }

    return -1;
}

// Видалення елемента з хеш-таблиці
void HashDelete(HashTable* table, int key) {
    int i = 0;
    int j = hashFunction(key, table->size);

    while (i < table->size && table->array[j].key != -1) {
        if (table->array[j].key == key) {
            table->array[j].key = -1;
            table->array[j].value = -1;
            table->count--;
            return;
        }
        i++;
        j = (j + 1) % table->size;
    }
}

// Виведення всіх елементів хеш-таблиці
void HashShow(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        if (table->array[i].key != -1) {
            cout << "Індекс: " << i << "  Ключ: " << table->array[i].key << "  Значення: " << table->array[i].value << endl;
        }
    }
}

// Розв'язування колізій методом квадратичного пробування
int quadraticProbe(int key, int i, int size) {
    return (hashFunction(key, size) + i * i) % size;
}

// Розв'язуванвання колізій методом подвійного хешування
int doubleHash(int key, int i, int size) {
    int h1 = hashFunction(key, size);
    int h2 = 1 + (key % (size - 1)); 
    return (h1 + i * h2) % size;
}

