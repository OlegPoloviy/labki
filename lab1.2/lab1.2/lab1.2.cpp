#include <iostream>
#include "Tree.h"
#include "Tree.cpp"
#include <Windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Node* root = NULL;
    int choice = 0, key = 0;
    Node* pNode = NULL; 
    while (true) {
        cout << "\nОперації над бінарним деревом пошуку:\n";
        cout << "-------------------------------\n";
        cout << "1. Вставити вузол\n";
        cout << "2. Видалити вузол\n";
        cout << "3. Знайти найменший вузол\n";
        cout << "4. Знайти найбільший вузол\n";
        cout << "5. Знайти successor\n";
        cout << "6. Знайти predecessor\n";
        cout << "7. Вйити з програми\n";
        cout << "Підтвердіть свій вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть число для вставки: ";
            cin >> key;
            root = InsertNodeBST(root, key);
            ShowTree(root,0);
            break;
        case 2:
            cout << "Введіть вузол для видалення: ";
            cin >> key;
            root = DeleteNodeBST(&root, key);
            ShowTree(root,0);
            break;
        case 3:
            cout << "Найменший вузол: " << minimumNodeBST(root)->key << endl;
            break;
        case 4:
            cout << "Найбільший вузол: " << maximumNodeBST(root)->key << endl;
            break;
        case 5:
            cout << "Введіть значення щоб знайти successor: ";
            cin >> key;
            pNode = SearchNodeBST(root, key); 
            if (pNode == NULL) {
                cout << "Вузол зі значенням " << key << " не знайдений!" << endl;
            }
            else {
                Node* pSuccessor = SuccessorNodeBST(pNode);
                if (pSuccessor == NULL) {
                    cout << "Вузол зі значенням  " << key << " не має successor!" << endl;
                }
                else {
                    cout << "Successor вузла зі значенням  " << key << " це " << pSuccessor->key << endl;
                }
            }
            break;
        case 6:
            cout << "Введіть значення щоб знайти predecessor: ";
            cin >> key;
            pNode = SearchNodeBST(root, key); 
            if (pNode == NULL) {
                cout << "Вузол зі значенням  " << key << " не знайдено!" << endl;
            }
            else {
                Node* pPredecessor = PredecessorNodeBST(pNode);
                if (pPredecessor == NULL) {
                    cout << "Вузол зі значенням  " << key << " не має predecessor!" << endl;
                }
                else {
                    cout << "Predecessor вузла зі значенням  " << key << " це " << pPredecessor->key << endl;
                }
            }
            break;
        case 7:
            cout << "Вихід з програми...\n";
            exit(0);
        default:
            cout << "Неправильний вибір\n";
            break;
        }
    }
    return 0;
}