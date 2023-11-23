#ifndef TREE_H
#define TREE_H

typedef int datatype;
struct Node {
    datatype key;
    Node* parent;
    Node* left;
    Node* right;
};

Node* newNode(int data);
void insertNode(Node** pNode, int data);
void CreateTree(Node** pNode, int n);
void ShowTree(Node** pNode, int level);
void PrefixOrder(Node* pNode);
void PostfixOrder(Node* pNode);
void InfixOrder(Node* pNode);

#endif // TREE_H
