#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* prev;
    Node* next;
};

class DoublyLinkedList{
private:
    Node* root;

    Node* newNode(int value){
        Node* node = new Node();

        node->value = value;
        node->prev = nullptr;
        node->next = nullptr;

        return node;
    }
public:
    DoublyLinkedList(){
        this->root = nullptr;
    }

    DoublyLinkedList(int value){
        this->root = newNode(value);
    }

    void insertAtHead(int value){
        Node* node = newNode(value);
        if (this->root == nullptr){
            this->root = node;
        }
        else {
            node->next = this->root;
            this->root->prev = node;
            this->root = node;
        }
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
            node->prev = current;
        }
    }

    void sort(){
        Node* current = this->root;
        while (current != nullptr){
            Node* next = current->next;
            while (next != nullptr){
                if (current->value > next->value){
                    int temp = current->value;
                    current->value = next->value;
                    next->value = temp;
                }
                next = next->next;
            }
            current = current->next;
        }
    }

    void print(){
        Node* current = this->root;
        while (current != nullptr){
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    
    ~DoublyLinkedList(){
        Node* current = this->root;
        while (current != nullptr){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        cout << "\nDoubly linked list removed from memory!" << endl;
    }
};

int main(){
    DoublyLinkedList dll;

    dll.insertAtBack(12);
    dll.insertAtHead(312);
    dll.insertAtHead(522);
    dll.insertAtBack(31231);
    dll.insertAtBack(1);
    dll.insertAtHead(5);
    dll.print();

    dll.sort();
    dll.print();
    
    dll.~DoublyLinkedList();

    return 0;
}