#include "../headers/BinaryTree.h"

BinaryNode::BinaryNode(int val){
            data = val;
            left = NULL;
            right = NULL;
            null = false;
}

BinaryNode::BinaryNode(){}

void PrintSpaces(int num){
    for(int i = 0; i < num; i++){
        std::cout << " ";
    }
}

void BinaryTree::insert(int pos, int val){
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

void BinaryTree::display(){
    int astmeid = getDepth();
    BinaryNode *node = root;
    PrintSpaces((pow(2, astmeid-1) - 1)*2);
    std::cout << "[" <<root -> data << "]" << std::endl;
    bool roots = true;
    for(int i = 1; roots == true && i < 5; i++){
        roots = false;
        PrintSpaces((pow(2, astmeid-1-i) - 1)*2);
        for(int j = 0; j < pow(2, i); j++){
            if(get(pow(2, i) + j) != NULL){
                if(!get(pow(2, i) + j) -> null){
                    std::cout << "["<<get(pow(2, i) + j) -> data << "]";
                }else{
                    std::cout << "[ ]";
                }
                if(get(pow(2, i) + j) -> left || get(pow(2, i) + j) -> right){
                    roots = true;
                }
            }else{
                std::cout << "[ ]";
            }
            PrintSpaces((pow(2, astmeid-i) - 1)*2-1);
        }
        std::cout << std::endl;
    }
}

BinaryNode* BinaryTree::get(int pos){
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

int BinaryTree::getDepth(){
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

BinaryNode* BinaryTree::search(int val){
    BinaryNode *node = root;
    if(!root){
        return NULL;
    }else if(root -> data == val && !root -> null){
        return root;
    }
    

    BinaryNode *history[10] = {root};

    int depth = 1;

    while(true){
        std::cout << depth << " , " << node -> data << std::endl;
        if(node -> left){
            node = node -> left;
            if(node -> data == val && !node -> null){
                return node;
            }
            history[depth++] = node;
        }else{
            if(node -> right){
                node = node -> right;
                if(node -> data == val && !node -> null){
                    return node;
                }
                history[depth++] = node;
            }else{
                bool found = false;
                while(!found){
                    if(depth == 0){
                        return NULL;
                    }
                    node = history[--depth];

                    if(node -> right){
                        node = node -> right;
                        if(node -> data == val && !node -> null){
                            return node;
                        }
                        history[depth++] = node; 
                        found = true;
                    }
                }
            }

        }

    }
    return NULL;
}