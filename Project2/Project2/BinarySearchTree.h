#pragma once
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "Node.h"

using namespace std;

class BST {
public:
	BST();
	~BST();
	void setRoot(Node* newHead);
	Node* getRoot() const;
	void insert(const char newC, char* const newStr);
	void print();
	string search(char c);
	string decode(string c);

private:
	void destroyBST(Node* TreeHead);
	void insert(Node*& newNode, const char C, char* const Str);
	void print(Node* Tree); 
	string search(Node* Tree, char c);
	string decode(Node* Tree, string c);
	Node* Root;
	fstream MorseCode;
};

#endif // !BINARY_SEARCH_TREE


