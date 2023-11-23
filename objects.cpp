#include <iostream>
#include <list>
#include <string>
using namespace std;

// Клас, який представляє елемент хеш-таблиці
class HashTableItem {
public:
    string key;
    int value;
};

// Клас хеш-таблиці
class HashTable {
private:
    static const int tableSize = 10; // розмір таблиці
    list<HashTableItem> table[tableSize]; // масив списків, що містять елементи таблиці

public:
    // Метод для генерації хешу за ключем
    int hashFunction(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum += (int)key[i];
        }
        return sum % tableSize;
    }

    // Метод для додавання елемента до таблиці
    void addItem(string key, int value) {
        int index = hashFunction(key);
        HashTableItem item;
        item.key = key;
        item.value = value;
        table[index].push_back(item);
    }

    // Метод для виведення елементів таблиці
    void printTable() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            for (auto item : table[i]) {
                cout << "(" << item.key << "," << item.value << ") -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable table;
    table.addItem("apple", 1);
    table.addItem("banana", 2);
    table.addItem("orange", 3);
    table.addItem("peach", 4);
    table.printTable();
    return 0;
}
