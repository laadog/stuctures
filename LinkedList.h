#pragma once
#include <iostream>

class Node{
    public:
        int data;
        Node *next = NULL;
};

class LinkedList{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        Node get(int index);

        void push(int data);

        void pushFront(int data);

        void remove(int index);

        void pop();

        void popFirst();

        int getLength();

        void set(int index, int data);

        void sort();
        
        int search(int value);

        void display();
};