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
            if(head == nullptr || head->value >= value){
                newest_Node->next=head;
                head = newest_Node;
            }
            else{
                Node<T>* temp = head;
                while(temp->next != nullptr && temp->next->value<value){
                    temp = temp->next;

                }
                newest_Node->next = temp->next;
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
            std::cout << "\nnode: " << current_node->value << std::endl;
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
        unionSetRecursive(unionedSet, head, other.head);
        return unionedSet;
    }

    void unionSetRecursive(Set<T>& result, Node<T>* L, Node<T>* M) const {
        if (L == nullptr && M == nullptr)
            return;
        else if (L == nullptr)
            result.add(M->value), unionSetRecursive(result, nullptr, M->next);
        else if (M == nullptr)
            result.add(L->value), unionSetRecursive(result, L->next, nullptr);
        else if (L->value == M->value)
            result.add(L->value), unionSetRecursive(result, L->next, M->next);
        else if (L->value < M->value)
            result.add(L->value), unionSetRecursive(result, L->next, M);
        else
            result.add(M->value), unionSetRecursive(result, L, M->next);
    }


    Set<T> difference(const Set<T>& other) const {
        Set<T> differencedSet;
        differenceRecursive(differencedSet, head, other);
        return differencedSet;
    }

    void differenceRecursive(Set<T>& result, Node<T>* L, const Set<T>& other) const {
        if (L == nullptr)
            return;
        if (!other.contains(L->value))
            result.add(L->value);
        differenceRecursive(result, L->next, other);
    }


    Set<T> intersection(const Set<T>& other) const {
        Set<T> intersectionSet;
        intersectionRecursive(intersectionSet, head, other.head);
        return intersectionSet;
    }

    void intersectionRecursive(Set<T>& result, Node<T>* L, Node<T>* M) const {
        if (L == nullptr || M == nullptr)
            return;
        if (L->value == M->value) {
            result.add(L->value);
            intersectionRecursive(result, L->next, M->next);
        } else if (L->value < M->value) {
            intersectionRecursive(result, L->next, M);
        } else {
            intersectionRecursive(result, L, M->next);
        }
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




int main() {
    return 0;
}
