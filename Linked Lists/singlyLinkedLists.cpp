#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

class SinglyLinkedLists{
private:
    Node* root;

    Node* newNode(int value){
        Node* node = new Node();
        node->value = value;
        node->next = nullptr;

        return node;
    };

public:
    SinglyLinkedLists(){
        this->root = nullptr;
    }

    SinglyLinkedLists(int value){
        this->root = newNode(value);
    }

    void insertAtBack(int value){
        Node* node = newNode(value);
        if (this->root == nullptr){
            this->root = node;
        }
        else {
            Node* current = this->root;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = node;
        }
    }

    void insertAtHead(int value){
        Node* node = newNode(value);
        if (this->root == nullptr){
            this->root = node;
        }
        else{
            Node* temp = this->root;
            node->next = temp;
            this->root = node;
        }
    }

    void print(){
        Node* current = this->root;
        while (current != nullptr){
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "Print successfully" << endl;
    }

    ~SinglyLinkedLists(){
        Node* current = this->root;
        while(current->next != nullptr){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

};

int main(){
    SinglyLinkedLists singlyLinkedLists;

    singlyLinkedLists.insertAtHead(14);
    singlyLinkedLists.print();
    singlyLinkedLists.insertAtBack(15);
    singlyLinkedLists.print();
    singlyLinkedLists.insertAtBack(99);
    singlyLinkedLists.print();
    singlyLinkedLists.insertAtBack(144);
    singlyLinkedLists.print();
    singlyLinkedLists.insertAtHead(1);
    singlyLinkedLists.print();
    singlyLinkedLists.~SinglyLinkedLists();
    return 0;
}