#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Створення порожньої хеш-таблиці
    unordered_map<string, int> myMap;

    // Додавання елементів зі значеннями за ключем до хеш-таблиці
    myMap["apple"] = 8;
    myMap["banana"] = 2;
    myMap["orange"] = 3;
    myMap["peach"] = 4;

    // Виведення елементів хеш-таблиці
    for (auto& item : myMap) {
        cout << "Key: " << item.first << ", Value: " << item.second << endl;
    }

    return 0;
}
