#include <iostream>
#include "headers/BinaryTree.h"
#include <cmath>

using namespace std;


int main(int argc, char const *argv[])
{
    BinaryTree tree;
    tree.root = new BinaryNode(1); // 1
    tree.root -> left = new BinaryNode(5); // 2
    tree.root -> right = new BinaryNode(7); // 3
    tree.root -> right -> right = new BinaryNode(6); // 7
    tree.root -> left -> left = new BinaryNode(3); // 4
    // tree.root -> left -> left->left = new BinaryNode(3); // 4
    // tree.root -> left -> left->left->right = new BinaryNode(3); // 4
    // tree.root -> right -> right->left = new BinaryNode(3); // 4
    // tree.root -> right -> right->left->left = new BinaryNode(3); // 4
    tree.insert(10, 5);
    tree.insert(20, 7);
    tree.insert(24, 7);

    tree.display();

}
