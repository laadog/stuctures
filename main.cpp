#include <iostream>
#include "headers/BinaryTree.h"

using namespace std;


int main(int argc, char const *argv[])
{
    BinaryTree tree;


    tree.binaryInsert(2);
    tree.binaryInsert(20);
    tree.binaryInsert(19);
    tree.binaryInsert(21);
    tree.binaryInsert(2);
    tree.binaryInsert(3);
    tree.binaryInsert(4);

    tree.display();
}
