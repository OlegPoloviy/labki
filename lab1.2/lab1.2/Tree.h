#ifndef TREE_H
#define TREE_H
typedef int datatype;

struct Node {
    datatype key;
    Node* parent;
    Node* left;
    Node* right;
};
void ShowTree(Node** pNode, int level);
Node* SearchNodeBST(Node* root, int key);
Node* CreateRootBST(int key);
Node* InsertNodeBST(Node* root, int key);
Node* SuccessorNodeBST(Node* pNode);
Node* minimumNodeBST(Node* root);
Node* maximumNodeBST(Node* root);
Node* PredecessorNodeBST(Node* pNode);
Node* DeleteNodeBST(Node** root, int key);

#endif // TREE_H