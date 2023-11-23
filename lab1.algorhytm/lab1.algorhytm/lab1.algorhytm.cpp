#include <iostream>
#include <stdlib.h>
#include "Tree.h"
#include "Tree.cpp"
#include <Windows.h>

using namespace std;
Node* newNode(int data) {
    Node* node = new Node;
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    TreeNode* root = NULL;
    int n;

    while (true) {
        cout << "1. Створити дерево" << endl;
        cout << "2. Показати дерево" << endl;
        cout << "3. Обхід у прямому порядку" << endl;
        cout << "4. Обхід у зворотньому порядку" << endl;
        cout << "5. Обхід у внутрішньому порядку" << endl;
        cout << "6. Вихід з програми" << endl;
        cout << "Введіть ваш вибір: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть кількість вузлів: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                int data;
                cout << "Введіть елемент " << i + 1 << " вузла: ";
                cin >> data;
                if (root == NULL) {
                    root = createTreeNode(data);
                }
                else {
                    TreeNode* current = root;
                    while (true) {
                        if (data < current->key) {
                            if (current->left == NULL) {
                                current->left = createTreeNode(data);
                                break;
                            }
                            else {
                                current = current->left;
                            }
                        }
                        else {
                            if (current->right == NULL) {
                                current->right = createTreeNode(data);
                                break;
                            }
                            else {
                                current = current->right;
                            }
                        }
                    }
                }
            }
            cout << "Дерево створене." << endl;
            break;
        case 2:
            cout << "Дерево:" << endl;
            ShowTreeNode(root, 0);
            break;
        case 3:
            cout << "Обхід у прямому порядку: ";
            PrefixOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "Обхід у зворотньому порядку: ";
            PostfixOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Обхід у внутрішньому порядку: ";
            InfixOrder(root);
            cout << endl;
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Неправильний вибір." << endl;
        }
    }

    return 0;
}