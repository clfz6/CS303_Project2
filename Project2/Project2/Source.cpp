// Cristian Lopez
// CS 303
// 7-26-2020

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    char c = '\0';
    fstream Convert;
    Convert.open("Convert.txt");
    BST Tree;
    Tree.print();
    cout << endl << endl;
    while (!Convert.eof()) {
        Convert >> c;

        Tree.search(c);
    }

    cout << endl;

    if (Convert.is_open()) {
        Convert.close();
    }
	return 0;
}