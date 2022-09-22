#include <iostream>
#include "headers/BinaryTree.h"
#include <cmath>

using namespace std;


int main(int argc, char const *argv[])
{
    BinaryTree tree;
    tree.root = new BinaryNode(10); // 1
    tree.root -> left = new BinaryNode(5); // 2
    tree.root -> left -> right = new BinaryNode(9); // 2
    tree.root -> right = new BinaryNode(9); // 3
    tree.root -> right -> right = new BinaryNode(6); // 7
    tree.root -> left -> left = new BinaryNode(3); // 4
    tree.root -> left -> left->left = new BinaryNode(9); // 4
    tree.root -> left -> left->right = new BinaryNode(9); // 4
    tree.insert(10, 5);
    tree.insert(21, 8);
    tree.insert(24, 7);
    tree.insert(25, 0);

    tree.display();

    tree.binaryInsert(2);
    tree.binaryInsert(20);
    tree.binaryInsert(19);
    tree.binaryInsert(21);
    tree.binaryInsert(2);
    tree.binaryInsert(3);

    tree.display();

}
