#include <iostream>
#include "LinkedList.h"
#include <cmath>

using namespace std;

void PrintSpaces(int num){
    for(int i = 0; i < num; i++){
        cout << " ";
    }
}

class BinaryNode{
    public:
        int data;
        bool null = true;
        BinaryNode *left = NULL;
        BinaryNode *right = NULL;
        BinaryNode(){

        }
        BinaryNode(int val){
            data = val;
            left = NULL;
            right = NULL;
            null = false;
        }
};

class BinaryTree{
    public:
        BinaryNode *root = NULL;
        void Insert(int pos, int val){
            if(root == NULL){
                root = new BinaryNode();
            }
            BinaryNode *node = root;
            for(int i = floor(log2(pos)); i > 0;i--){
                if(pos%int(pow(2, i)) < pow(2, i-1)){
                    if(node -> left == NULL){
                        BinaryNode *tmp = new BinaryNode();
                        node -> left = tmp;
                    }
                    node = node -> left;
                }else{
                    if(node -> right == NULL){
                        BinaryNode *tmp = new BinaryNode();
                        node -> right = tmp;
                    }
                    node = node -> right;
                }
            }
            node->data = val;
            node->null = false; 
        }

        void display(){
            int astmeid = getDepth();
            BinaryNode *node = root;
            PrintSpaces((pow(2, astmeid-1) - 1)*2);
            cout << "[" <<root -> data << "]" << endl;
            bool roots = true;
            for(int i = 1; roots == true && i < 5; i++){
                roots = false;
                PrintSpaces((pow(2, astmeid-1-i) - 1)*2);
                for(int j = 0; j < pow(2, i); j++){
                    if(get(pow(2, i) + j) != NULL){
                        if(!get(pow(2, i) + j) -> null){
                            cout << "["<<get(pow(2, i) + j) -> data << "]";
                        }else{
                            cout << "[ ]";
                        }
                        if(get(pow(2, i) + j) -> left || get(pow(2, i) + j) -> right){
                            roots = true;
                        }
                    }else{
                        cout << "[ ]";
                    }
                    PrintSpaces((pow(2, astmeid-i) - 1)*2-1);
                }
                cout << endl;
            }
        }

        BinaryNode* get(int pos){
            BinaryNode *node = root;
            for(int i = floor(log2(pos)); i > 0;i--){
                if(pos%int(pow(2, i)) < pow(2, i-1)){
                    node = node -> left;
                }else{
                    node = node -> right;
                }
                if(node == NULL){
                    return NULL;
                }
            }
            return node;
        }

        int getDepth(){
            if(root == NULL){
                return 0;
            }
            int astmeid = 2;
            BinaryNode *node = root;
            if(node -> left || node -> right){
                bool roots = true;
                while(roots){
                    roots = false;
                    for(int j = 0; j < pow(2, astmeid); j++){
                        if(get(pow(2, astmeid) + j)){
                            if(get(pow(2, astmeid) + j) -> left || get(pow(2, astmeid) + j) -> right){
                                roots = true;
                            }
                        }
                    }
                    astmeid++;
                }
            return astmeid;
            }else{
                return 1;
            }

        }

};

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
    tree.Insert(10, 5);
    tree.Insert(20, 7);

    tree.display();

}
