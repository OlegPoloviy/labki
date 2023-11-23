#include"Hash.h"
int hash(int x, int m) {
    return x % m;
}

// ������� ��� ������� ����� � ���-������� � �������� ���������� (chaining)
void ChainedHashInsert(std::vector<Node*>& T, int x, int m) {
    int h = hash(x, m);
    Node* node = new Node;
    node->data = x;
    node->next = T[h];
    T[h] = node;
}

// ������� ��� ������ ����� � ���-������� � �������� ���������� (chaining)
Node* ChainedHashSearch(std::vector<Node*> T, int k, int m) {
    int h = hash(k, m);
    Node* node = T[h];
    while (node != nullptr && node->data != k) {
        node = node->next;
    }
    return node;
}

// ������� ��� ��������� ����� � ���-������� � �������� ���������� (chaining)
void ChainedHashDelete(std::vector<Node*>& T, int k, int m) {
    int h = hash(k, m);
    Node* node = T[h];
    Node* prev = nullptr;
    while (node != nullptr && node->data != k) {
        prev = node;
        node = node->next;
    }
    if (node != nullptr) {
        if (prev != nullptr) {
            prev->next = node->next;
        }
        else {
            T[h] = node->next;
        }
        delete node;
    }
    else {
        std::cerr << "�������� �� �������� � ���-������� " << std::endl;
        throw std::runtime_error("");
    }
}


void ChainedHashShow(std::vector<Node*> T) {
    for (int i = 0; i < T.size(); i++) {
        std::cout << "������ " << i << ": ";
        Node* current = T[i];
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
  
}
int hash_division(int x, int m) {
    return x % m;
}
