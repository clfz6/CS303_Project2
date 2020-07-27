#pragma once
#include "BinarySearchTree.h"
#include <cstring>
#include <iostream>
#include <time.h>

using namespace std;

class Node {

public:
    Node();
    Node(char c, char* s);
    ~Node();
    void setChr(const char c);
    void setStr(char* const s);
    void setLeft(Node* const pLeft);
    void setRight(Node* const pRight);
    char getChr() const;
    string getString() const;
    Node*& getLeft();
    Node*& getRight();

private:

    char Char;
    char String[100];
    Node* Left;
    Node* Right;

};