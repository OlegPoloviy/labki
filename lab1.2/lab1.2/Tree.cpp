#include "Tree.h"
#include <stack>
#include <iostream>
using namespace std;

Node* SearchNodeBST(Node* root, int key) {
    Node* pNode = root;
    while (pNode != NULL) {
        if (pNode->key == key) {
            return pNode;
        }
        else if (pNode->key > key) {
            pNode = pNode->left;
        }
        else {
            pNode = pNode->right;
        }
    }
    return NULL;
}

Node* CreateRootBST(int key) {
    Node* pNode = new Node;
    pNode->key = key;
    pNode->parent = pNode->left = pNode->right = NULL;
    return pNode;
}

Node* InsertNodeBST(Node* root, int key) {
    // ��������, �� ������ �� ������
    if (root == NULL) {
        // ��������� ������ ������
        root = new Node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return root;
    }

    // ����� ���� ��� ������� �����
    Node* pNode = root;
    Node* previous = NULL;
    while (pNode != NULL) {
        previous = pNode;
        if (key == pNode->key) {
            // ����� � ������ ������ ��� ����
            cout << "Node with key " << key << " already exists!" << endl;
            return root;
        }
        else if (key < pNode->key) {
            pNode = pNode->left;
        }
        else {
            pNode = pNode->right;
        }
    }

    // ������� �����
    Node* pNew = new Node;
    pNew->key = key;
    pNew->left = NULL;
    pNew->right = NULL;
    pNew->parent = previous;
    if (key < previous->key) {
        previous->left = pNew;
    }
    else {
        previous->right = pNew;
    }

    return root;
}

Node* minimumNodeBST(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// ������� ������ ����� � ������������ ������ � ������� � ������� root.
Node* maximumNodeBST(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// ������� SuccessorNodeBST ��� ������ ����� Successor ��� ����� pNode.
Node* SuccessorNodeBST(Node* pNode) {
    // ���� � ����� pNode ���� ������ ��� (����� ��������):
    if (pNode->right != NULL) {
        // ������� � ����� ������� �������� ����� pNode.
        Node* previous = pNode->right;
        while (previous->left != NULL) {
            previous = previous->left;
        }
        return previous;
    }
    // ������, ���� � ����� pNode �� ���� ������� ���� (������� ��������):
    else {
        Node* previous = pNode->parent;
        while (previous != NULL && pNode == previous->right) {
            pNode = previous;
            previous = previous->parent;
        }
        return previous;
    }
}

Node* PredecessorNodeBST(Node* pNode) {
    // ���� ����� pNode �� ����� �������, ������ ����� � ������������ ������ � ����� �������
    if (pNode->left != nullptr) {
        Node* current = pNode->left;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    // ���� ����� pNode �� �� ����� �������, ������ ���� �������, ���� � ������ �������� ���� ������
    Node* current = pNode;
    while (current->parent != nullptr && current == current->parent->left) {
        current = current->parent;
    }
    return current->parent;
}

Node* DeleteNodeBST(Node** root, int key) {
    // ����� �����, �� �����������
    Node* curr = SearchNodeBST(*root, key);
    if (curr == NULL) {
        printf("�������: ����� ��� ��������� �� ��������.\n");
        return *root;
    }

    // ������� 1: �����, �� ����������� �� �� �������
    if (curr->left == NULL && curr->right == NULL) {
        if (curr->parent == NULL) {
            // ��������� ������ ������
            *root = NULL;
        }
        else if (curr == curr->parent->left) {
            curr->parent->left = NULL;
        }
        else {
            curr->parent->right = NULL;
        }
        delete curr;
    }
    // ������� 2: �����, �� ����������� �� ���� ������ �������
    else if (curr->left == NULL || curr->right == NULL) {
        Node* child = curr->left ? curr->left : curr->right;
        if (curr == *root) {
            // ��������� ������ ������ � ����� ��������
            *root = child;
            child->parent = NULL;
        }
        else {
            child->parent = curr->parent;
            if (curr == curr->parent->left) {
                curr->parent->left = child;
            }
            else {
                curr->parent->right = child;
            }
        }
        delete curr;
    }
    // ������� 3: �����, �� ����������� �� ���� �������
    else {
        Node* successor = SuccessorNodeBST(curr);
        curr->key = successor->key;
        DeleteNodeBST(root, successor->key);
    }

    return *root;
}

void ShowTree(const Node* pNode, int indent = 0) {
    if (pNode == nullptr)
        return;

    ShowTree(pNode->right, indent + 1);

    for (int i = 0; i < indent; i++)
        cout << "    ";

    cout << pNode->key << endl;

    ShowTree(pNode->left, indent + 1);
}
