#include <iostream>
#include <vector>
#include <list>
#include "Hash.h"
#include "Hash.cpp"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int m;
    std::cout << "Задайте розмір хеш-таблиці: ";
    std::cin >> m;

    std::vector<Node*> T(m, nullptr);

    int choice, val;
    Node* node = nullptr;

    do {
        std::cout << "1. Вставити значення" << std::endl;
        std::cout << "2. Пошук значення" << std::endl;
        std::cout << "3. Видалити значення" << std::endl;
        std::cout << "4. Відобразити таблицю" << std::endl;
        std::cout << "5. Вийти з програми" << std::endl;

        std::cout << "Введіть ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введіть значення, яке потрібно вставити: ";
            std::cin >> val;
            ChainedHashInsert(T, val, T.size());
            std::cout << "Значення " << val << " успішно вставлене в таблицю." << std::endl;
            break;
        case 2:
            std::cout << "Введіть значення, яке потрібно знайти: ";
            std::cin >> val;
            node = ChainedHashSearch(T, val, T.size());
            if (node != nullptr) {
                std::cout << "Значення " << val << " знайдене в таблиці." << std::endl;
            }
            else {
                std::cout << "Значення " << val << " не знайдене в таблиці." << std::endl;
            }
            break;
        case 3:
            std::cout << "Введіть значення, яке потрібно видалити: ";
            std::cin >> val;
            try {
                ChainedHashDelete(T, val, T.size());
                std::cout << "Значення " << val << " успішно видалене з таблиці." << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
                std::cout << "Значення " << val << " не видалене з таблиці." << std::endl;
            }
            break;
        case 4:
            ChainedHashShow(T);
            break;
        case 5:
            std::cout << "Роботу закінчено" << std::endl;
            break;
        default:
            std::cout << "Некоректний вибір. Спробуйте ще раз." << std::endl;
            break;
        }

        std::cout << std::endl;

    } while (choice != 5);

    return 0;
}
