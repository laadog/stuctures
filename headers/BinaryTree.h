#pragma once
#include <iostream>
#include <cmath>

class BinaryNode{
    public:
        int data;
        bool null = true;
        BinaryNode *left = 0;
        BinaryNode *right = 0;
        BinaryNode();
        BinaryNode(int val);
};

class BinaryTree{
    public:
        BinaryNode *root = NULL;

        void insert(int pos, int val);

        void display();

        BinaryNode* get(int pos);

        int getDepth();

};