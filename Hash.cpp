#include "Hash.h"
#include <iostream>

Hash::Hash(int size) {
    this->size = size;
    table = new int[size];
    for (int i = 0; i < size; i++) {
        table[i] = -1;  // Позначаємо, що комірка є вільною
    }
}

Hash::~Hash() {
    delete[] table;
}

void Hash::HashInsert(int key) {
    int index = key % size;
    int i = 1;
    while (table[index] != -1) {
        index = (key + i) % size;  // Лінійне квадратичне дослідження
        i++;
    }
    table[index] = key;
}

std::string Hash::HashSearch(int key) {
    int index = key % size;
    int i = 1;
    while (table[index] != -1) {
        if (table[index] == key) {
            return "Found";
        }
        index = (key + i) % size;  // Лінійне квадратичне дослідження
        i++;
    }
    return "Not found";
}

void Hash::HashDelete(int key) {
    int index = key % size;
    int i = 1;
    while (table[index] != -1) {
        if (table[index] == key) {
            table[index] = -2;  // Позначаємо, що комірка містить видалене значення
            return;
        }
        index = (key + i) % size;  // Лінійне квадратичне дослідження
        i++;
    }
}

void Hash::HashShow() {
    for (int i = 0; i < size; i++) {
        std::cout << "Index " << i << ": ";
        if (table[i] == -1) {
            std::cout << "Empty";
        }
        else if (table[i] == -2) {
            std::cout << "Deleted";
        }
        else {
            std::cout << table[i];
        }
        std::cout << std::endl;
    }
}
