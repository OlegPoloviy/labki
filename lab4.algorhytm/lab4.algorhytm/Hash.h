#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
struct Node {
	int data;
	Node* next;
};
void  ChainedHashInsert(std::vector<Node*>& T, int x, int m);
	Node* ChainedHashSearch(std::vector<Node*> T, int k, int m);
	void ChainedHashDelete(std::vector<Node*>& T, int x, int m);
	int hash(int x, int m);
	void ChainedHashShow(std::vector<Node*> T);
	int hash_division(int x, int m);


#endif // HASH_H