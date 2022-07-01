#include <iostream>

using namespace std;

#define COUNT 10

struct Node{
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree{
private:
    Node* root;

    Node* newNode(int value){
        Node* node = new Node();

        node->value = value;
        node->left = nullptr;
        node->right = nullptr;

        return node;
    }

    void print2DUtil(Node *root, int space){
        // Base case
        if (root == NULL)
            return;
    
        // Increase distance between levels
        space += COUNT;
    
        // Process right child first
        print2DUtil(root->right, space);
    
        // Print current node after space
        // count
        cout << endl;

        for (int i = COUNT; i < space; i++)
            cout<<" ";
        cout<< root->value << "\n";
    
        // Process left child
        print2DUtil(root->left, space);
    }

public:
    BinarySearchTree(){
        this->root = nullptr;
    }

    BinarySearchTree(int value){
        this->root = newNode(value);
    }

    void insertNode(int value){
        if(this->root == nullptr){
            this->root = newNode(value);
        }
        else{
            Node* current = this->root;
            Node* parent;

            while(true){
                parent = current;
                if(value < current->value){
                    current = current->left;
                    if(current == nullptr){
                        parent->left = newNode(value);
                        break;
                    }
                }
                else{
                    current = current->right;
                    if(current == nullptr){
                        parent->right = newNode(value);
                        break;
                    }
                }
            }
        }
    }

    void deleteNode(int value){
        Node* current = this->root;
        Node* parent = nullptr;
        while (current != nullptr){
            if (value > current->value){
                parent = current;
                current = current->right;
            }
            else if (value < current->value){
                parent = current;
                current = current->left;
            }
            else {
                if (current->left == nullptr && current->right == nullptr){
                    if (parent->left == current){
                        parent->left = nullptr;
                    }
                    else if (parent->right == current){
                        parent->right = nullptr;
                    }
                    delete current;
                    return;
                }
                else if (current->left == nullptr){
                    if (parent->left == current){
                        parent->left = current->right;
                    }
                    else if (parent->right == current){
                        parent->right = current->right;
                    }
                    delete current;
                    return;
                }
                else if (current->right == nullptr){
                    if (parent->left == current){
                        parent->left = current->left;
                    }
                    else if (parent->right == current){
                        parent->right = current->left;
                    }
                    delete current;
                    return;
                }
                else {
                    Node* successor = current->right;
                    Node* successorParent = current;
                    while (successor->left != nullptr){
                        successorParent = successor;
                        successor = successor->left;
                    }
                    current->value = successor->value;
                    if (successorParent->left == successor){
                        successorParent->left = successor->right;
                    }
                    else if (successorParent->right == successor){
                        successorParent->right = successor->right;
                    }
                    delete successor;
                    return;
                }
            }
        }
    }

    void print(const std::string& prefix, Node* node, bool isLeft){
        if(node != nullptr){
            cout << prefix;

            cout << (isLeft ? "|--" : "L--" );

            // print the value of the node
            cout << node->value << endl;

            // enter the next tree level - left and right branch
            print(prefix + (isLeft ? "|   " : "    "), node->left, true);
            print(prefix + (isLeft ? "|   " : "    "), node->right, false);
        }
    }

    void print(Node* node){
        print("", node, false);    
    }
    
    Node* getRoot(){
        return this->root;
    }

    ~BinarySearchTree(){
        delete this->root;
        cout << "\nBinary search tree removed from memory!" << endl;
    }
};

int main(){
    BinarySearchTree bst;

    bst.insertNode(5);
    bst.insertNode(1323);
    bst.insertNode(3441);
    bst.insertNode(23);
    bst.insertNode(42);
    bst.insertNode(4);
    bst.insertNode(2);
    bst.insertNode(3);
    bst.insertNode(10);
    bst.print(bst.getRoot());

    bst.~BinarySearchTree();

    return 0;
}