#include <iostream>
#include <stdlib.h>
#include "Tree.h"

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createTreeNode(int data) {
    TreeNode* node = new TreeNode;
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void ShowTreeNode(TreeNode* node, int level) {
    if (node == NULL) {
        return;
    }

    ShowTreeNode(node->right, level + 1);

    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
    cout << node->key << endl;

    ShowTreeNode(node->left, level + 1);
}

void PrefixOrder(TreeNode* pNode) {
    if (pNode == NULL)
        return;

    cout << pNode->key << " ";
    PrefixOrder(pNode->left);
    PrefixOrder(pNode->right);
}

void PostfixOrder(TreeNode* pNode) {
    if (pNode == NULL)
        return;

    PostfixOrder(pNode->left);
    PostfixOrder(pNode->right);
    cout << pNode->key << " ";
}

void InfixOrder(TreeNode* pNode) {
    if (pNode == NULL)
        return;

    InfixOrder(pNode->left);
    cout << pNode->key << " ";
    InfixOrder(pNode->right);
}
