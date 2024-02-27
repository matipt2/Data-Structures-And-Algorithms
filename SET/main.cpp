#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Set {
private:
    Node* head;

public:
    Set() : head(nullptr) {}


    void add(int value) {
        if(!contains(value)){
            Node* newest_Node = new Node(value);
            if(head == nullptr){
                head = newest_Node;
            }
            else{
                Node* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newest_Node;
            }
        }
    }


    void remove(int value) {
        Node* current_node = head;
        Node* prev_node = nullptr;
        while(current_node!= nullptr && current_node->value != value){
            prev_node = current_node;
            current_node = current_node->next;
        }
        if(current_node!= nullptr){
            if(prev_node == nullptr){
                head = current_node->next;
            }
            else{
                prev_node->next = current_node->next;
            }
            delete current_node;
        }

    }


    void display() {
        Node* current_node = head;
        while(current_node!= nullptr){
            std::cout << "current_node = " << current_node->value << std::endl;
            current_node = current_node->next;
        }
    }


    bool contains(int value) {
        Node* current_node = head;
        while(current_node != nullptr){
            if(current_node->value == value){
                return true;
            }
            current_node = current_node->next;
        }
        return false;

    }


    Set unionSet(const Set& other) const {

    }


    Set difference(const Set& other) const {

    }


    Set intersection(const Set& other) const {

    }

    ~Set() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {


    return 0;
}
