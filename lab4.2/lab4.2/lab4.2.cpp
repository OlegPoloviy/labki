#include <iostream>
#include "Hash.h"
#include "Hash.cpp"
using namespace std;

void showMenu(HashTable& table, int hashMethod);
void performOperation(HashTable& table, int hashMethod, int option);

int main() {
    HashTable table;
    int option;

    cout << "Введіть розмір хеш-таблиці: ";
    cin >> table.size;

    table.table = new Node * [table.size];
    for (int i = 0; i < table.size; i++) {
        table.table[i] = nullptr;
    }

    do {
        cout << endl << "Меню:" << endl;
        cout << "1. Дослідження звичайної хеш-таблиці" << endl;
        cout << "2. Дослідження хеш-таблиці з квадратичним пробуванням" << endl;
        cout << "3. Дослідження хеш-таблиці з подвійним хешуванням" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> option;

        switch (option) {
        case 1:
            showMenu(table, 1);
            break;
        case 2:
            showMenu(table, 2);
            break;
        case 3:
            showMenu(table, 3);
            break;
        case 0:
            break;
        default:
            cout << "Невірний вибір" << endl;
        }
    } while (option != 0);

    return 0;
}

void showMenu(HashTable& table, int hashMethod) {
    string methodName;

    switch (hashMethod) {
    case 1:
        methodName = "звичайної";
        break;
    case 2:
        methodName = "з квадратичним хешуванням";
        break;
    case 3:
        methodName = "з подвійним хешуванням";
        break;
    default:
        methodName = "невідомого методу хешування";
    }

    cout << endl << "Дослідження хеш-таблиці " << methodName << endl;

    int option;
    do {
        cout << endl << "Підменю:" << endl;
        cout << "1. Вставка елемента" << endl;
        cout << "2. Пошук елемента" << endl;
        cout << "3. Видалення елемента" << endl;
        cout << "4. Виведення всіх елементів" << endl;
        cout << "0. Повернутися до головного меню" << endl;
        cout << "Ваш вибір: ";
        cin >> option;
        performOperation(table, hashMethod, option);

    } while (option != 0);
}

void performOperation(HashTable& table, int hashMethod, int option) {
    int key;
    switch (option) {
    case 1:
        cout << "Введіть ключ: ";
        cin >> key;
        if (HashInsert(key, hashMethod,table)) {
            cout << "Елемент успішно вставлено" << endl;
        }
        else {
            cout << "Помилка вставки елемента" << endl;
        }
        break;
    case 2:
        cout << "Введіть ключ: ";
        cin >> key;
        if (HashSearch(key, hashMethod)) {
            cout << "Елемент знайдено" << endl;
        }
        else {
            cout << "Елемент не знайдено" << endl;
        }
        break;
    case 3:
        cout << "Введіть ключ: ";
        cin >> key;
        if (HashDelete(key, hashMethod)) {
            cout << "Елемент успішно видалено" << endl;
        }
        else {
            cout << "Помилка видалення елемента" << endl;
        }
        break;
    case 4:
        HashShow(hashMethod);
        break;
    case 0:
        break;
    default:
        cout << "Невірний вибір" << endl;
    }
}