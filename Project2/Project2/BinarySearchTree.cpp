#include "BinarySearchTree.h"
#include "Node.h"
#include <fstream>
#include <string>
#include <cstring>

BST::BST()
{
    char C = '\0';
    char S[100] = " ";
    Root = nullptr;
    MorseCode.open("input.txt");
    while (!MorseCode.eof()) {
        MorseCode >> C;
        MorseCode.getline(S, 100);
        insert(C, S);
    }
}

BST::~BST()
{
    if (MorseCode.is_open())
    {
        MorseCode.close();
    }
    destroyBST(Root);
}

void BST::setRoot(Node* newHead)
{
    Root = newHead;
}

Node* BST::getRoot() const
{
    return Root;
}

void BST::insert(const char newC, char* const newStr)
{
    insert(Root, newC, newStr);
}

void BST::print()
{
    print(Root);
}

string BST::search(char c)
{
    string Str;
    Str = search(Root, c);
    return Str;
}

string BST::decode(string c)
{
    string Str;
    Str = decode(Root, c);
    return Str;
}

void BST::destroyBST(Node* TreeHead)
{
    if (TreeHead != nullptr) {
        destroyBST(TreeHead->getLeft());
        destroyBST(TreeHead->getRight());
        delete(TreeHead);
    }
}

void BST::insert(Node*& newNode, const char C, char* const Str)
{
    if (newNode == nullptr) {
        Node* pMem = new Node(C, Str);
        newNode = pMem;
    }

    else {
        if ((C < newNode->getChr())) {
            insert((newNode)->getLeft(), C, Str);
        }
        else if (C > newNode->getChr()) {
            insert((newNode)->getRight(), C, Str);
        }
    }
}

void BST::print(Node* Tree)
{
    if (Tree != nullptr) {
        print(Tree->getLeft());
        //cout << "Character:" << Tree->getChr() << " Code:" << Tree->getString() << endl;
        print(Tree->getRight());
    }
}

string BST::search(Node* Tree, char c)
{
    string Str;
    if (Tree != nullptr) {
        search(Tree->getLeft(), c);
        search(Tree->getRight(), c);
        if (Tree->getChr() == c) {
            Str = Tree->getString();
            cout << Tree->getString() << " ";
        }
    }
    return Str;
}

string BST::decode(Node* Tree, string c)
{
    string Str;
    if (Tree != nullptr)
    {
        decode(Tree->getLeft(), c);
        decode(Tree->getRight(), c);
        if (Tree->getString() == c)
        {
            Str = Tree->getChr();
            cout << Tree->getChr() << " ";
        }
    }
    return Str;
}



Node::Node()
{
    Node(Char, String);
}

Node::Node(char c, char* s)
{
    strcpy_s(String, s);
    Char = c;
    Left = nullptr;
    Right = nullptr;
}

Node::~Node()
{
    cout << "";
}

void Node::setChr(const char c)
{
    Char = c;
}

void Node::setStr(char* const s)
{
    strcpy_s(String, s);
}

void Node::setLeft(Node* const pLeft)
{
    Left = pLeft;
}

void Node::setRight(Node* const pRight)
{
    Right = pRight;
}

char Node::getChr() const
{
    return this->Char;
}

string Node::getString() const
{
    return String;
}

Node*& Node::getLeft()
{
    return this->Left;
}

Node*& Node::getRight()
{
    return this->Right;
}