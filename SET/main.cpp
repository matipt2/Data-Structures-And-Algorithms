#include <iostream>

template<typename T>
struct Node {
    T value;
    Node* next;

    Node(T val) {
        value = val;
        next = nullptr;
    }
};

template<typename T>
class Set {
private:
    Node<T>* head;

public:
    Set() : head(nullptr) {}


    void add(T value) {
        if(!contains(value)){
            Node<T>* newest_Node = new Node<T>(value);
            if(head == nullptr){
                head = newest_Node;
            }
            else{
                Node<T>* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newest_Node;
            }
        }
    }


    void remove(T value) {
        Node<T>* current_node = head;
        Node<T>* prev_node = nullptr;
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
        Node<T>* current_node = head;
        while(current_node!= nullptr){
            std::cout << "current_node = " << current_node->value << std::endl;
            current_node = current_node->next;
        }
    }


    bool contains(T value) const {
        Node<T>* current_node = head;
        while (current_node != nullptr) {
            if (current_node->value == value) {
                return true;
            }
            current_node = current_node->next;
        }
        return false;
    }


    Set<T> unionSet(const Set<T>& other) const {
        Set<T> unionedSet;
        Node<T>* current = head;
        while(current!= nullptr){
            unionedSet.add(current->value);
            current = current ->next;
        }
        current = other.head;
        while(current!= nullptr){
            unionedSet.add(current->value);
            current = current->next;
        }
        return unionedSet;
    }


    Set<T> difference(const Set<T>& other) const {
        Node<T>* current = head;
        Set<T> differencedSet;
        while(current!= nullptr){
            if(!other.contains(current->value)){
                differencedSet.add(current->value);
                current = current->next;
            }
            else{
                current = current->next;
            }
        }
        return differencedSet;
    }

    Set<T> intersection(const Set<T>& other) const {
        Set<T> intersectionSet;
        Node<T>* current = head;
        while (current != nullptr) {
            if (other.contains(current->value)) {
                intersectionSet.add(current->value);
            }
            current = current->next;
        }
        return intersectionSet;
    }

    ~Set() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {return 0;}