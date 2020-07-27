// Cristian Lopez
// CS 303
// 7-26-2020

#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    char c = '\0';
    string d;
    fstream Encode, Decode;
    Encode.open("message.txt");
    Decode.open("morse.txt");
    BST Tree;
    //Tree.print();
    //cout << endl << endl;
    cout << "Encoded message: ";
    while (!Encode.eof()) 
    {
        Encode >> c;
        Tree.search(c);
    }

    cout << endl << "Decoded message: ";
    while (!Decode.eof())
    {
        Decode >> c;
        if (c != ' ')
        {
            d += c;
        }
        else
        {
            cout << c;
            Tree.decode(d);
        }
    } 

    Encode.close();
    Decode.close();

	return 0;
}