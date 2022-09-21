#include "LinkedList.h"

Node LinkedList::get(int index){
    Node *node = head;
    while(index > 0){
        node = node -> next;
        index--;
    }
    return *node;
}

void LinkedList::push(int data){
    Node *tmp = new Node();
    tmp -> data = data;
    tmp -> next = NULL;
    Node *node = head;
    if(head == NULL){
        head = tmp;
        tail = tmp;
    }
    else{
        tail -> next = tmp;
        tail = tail -> next;
    }
}

void LinkedList::pushFront(int data){
    Node *tmp = new Node();
    tmp -> data = data;
    tmp -> next = head;
    head = tmp;
}

void LinkedList::remove(int index){
    Node *node = head;
    if(index == 0){popFirst();}
    else if(index == 0){pop();}
    while(index > 1){
        node = node -> next;
        index--;
    }
    node -> next = node -> next -> next;
}

void LinkedList::pop(){
    Node *node = head;
    while(node -> next -> next != NULL){
        node = node -> next;
    }
    node -> next = NULL;
}

void LinkedList::popFirst(){
    if(head != NULL){
        head = head -> next;
    }
}

int LinkedList::getLength(){
    Node *node = head;
    int counter = 0;
    while(node != NULL){
        node = node -> next;
        counter++;
    }
    return counter;
}

void LinkedList::set(int index, int data){
    Node *node = head;
    while(index > 0){
        node = node -> next;
        index--;
    }
    node -> data = data;
}

void LinkedList::sort(){
    if(head == NULL){
        return;
    }
    Node *node = head;
    int firstCounter = 0;
    int secondCounter = 0;
    int smallest = node -> data;
    int index = firstCounter;

    while(node -> next != NULL){
        Node *current = node;
        while(current != NULL){
            if(current -> data < smallest){
                smallest = current -> data;
                index = secondCounter;
            }
            current = current -> next;
            secondCounter++;
        }
        set(index+firstCounter, node -> data);
        node -> data = smallest;
        node = node -> next;
        firstCounter++;
        secondCounter = 0;
        smallest = node -> data;
        index  = 0;
    }
}
        
int LinkedList::search(int value){
    Node *node = head;
    int counter = 0;
    while(node != NULL){
        if(node -> data == value){
            return counter;
        }
        node = node -> next;
        counter++;
    }
    return -1;
}

void LinkedList::display(){
    Node *node = head;
    std::cout << "[" ;
    while(node != NULL){
        std::cout << node -> data << ",";
        node = node -> next;
    }
    std::cout << "]\n";
}