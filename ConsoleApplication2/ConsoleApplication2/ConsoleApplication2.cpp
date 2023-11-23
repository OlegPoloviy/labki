#include "Hash.h"
#include <iostream>

int main() {
    int m;  // Розмір таблиці
    std::cout << "Enter the size of the table: ";
    std::cin >> m;

    Hash hashTable(m);

    // Додавання даних до хеш-таблиці
    hashTable.HashInsert(10);
    hashTable.HashInsert(20);
    hashTable.HashInsert(30);
    hashTable.HashInsert(11);

    // Відображення хеш-таблиці
    std::cout << "Hash Table:" << std::endl;
    hashTable.HashShow();

    // Пошук даних за ключем
    int searchKey = 20;
    std::string searchResult = hashTable.HashSearch(searchKey);
    std::cout << "Search result for key " << searchKey << ": " << searchResult << std::endl;

    // Видалення даних за ключем
    int deleteKey = 30;
    hashTable.HashDelete(deleteKey);
    std::cout << "After deleting key " << deleteKey << ":" << std::endl;
    hashTable.HashShow();

    return 0;
}
