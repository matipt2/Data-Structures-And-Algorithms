#include <iostream>
#include <limits>

template <typename T>
class cell {
public:
    T element;
    cell* next;
    cell* prev;
};

template <typename T>
class Lista1 {
protected:
    cell<T>* header;

public:
    Lista1() : header(nullptr) {}

    ~Lista1() {
        while (header != nullptr) {
            cell<T>* kom = header;
            header = header->next;
            delete kom;
        }
    }

    void Insert(T x, cell<T>* p) {
        cell<T>* kom = new cell<T>;
        kom->element = x;

        if (p != nullptr) {
            kom->next = p->next;
            p->next = kom;
        } else {
            kom->next = header;
            header = kom;
        }

        if (kom->next != nullptr) {
            kom->next->prev = kom;
        }

        if (p == nullptr) {
            header->prev = nullptr;
        }
    }

    bool Delete(cell<T>* p) {
        if (p == nullptr || p->next == nullptr)
            return false;

        cell<T>* kom = p->next;
        p->next = kom->next;

        if (p->next != nullptr) {
            p->next->prev = p;
        } else {
            if (header != nullptr) {
                header->prev = nullptr;
            }
        }

        delete kom;
        return true;
    }

    T Retrieve(cell<T>* p) {
        return p->element;
    }

    cell<T>* Locate(T x) {
        cell<T>* kom = header;
        while (kom != nullptr && kom->element != x)
            kom = kom->next;
        return kom;
    }

    cell<T>* First() {
        return header;
    }

    cell<T>* Next(cell<T>* p) {
        return p->next;
    }

    cell<T>* Last() {
        cell<T>* kom = header;
        while (kom != nullptr && kom->next != nullptr)
            kom = kom->next;
        return kom;
    }

    cell<T>* Previous(cell<T>* p) {
        if (p == nullptr || p == header) {
            return nullptr;
        }

        cell<T>* kom = header;
        while (kom != nullptr && kom->next != p) {
            kom = kom->next;
        }

        return kom;
    }

    void print() {
        cell<T>* kom = header;
        while (kom != nullptr) {
            std::cout << kom->element << " ";
            kom = kom->next;
        }
        std::cout << std::endl;
    }
};

template <typename T>
class Stack {
private:
    Lista1<T> list;

public:
    void push(T x) {
        list.Insert(x, list.Last());
    }

    T pop() {
        if (empty()) {
            return std::numeric_limits<T>::max();
        }
        cell<T>* firstElement = list.Last();
        T top = list.Retrieve(firstElement);
        list.Delete(list.Previous(firstElement));
        return top;
    }

    T top() {
        if (empty()) {
            return std::numeric_limits<T>::max();
        }
        cell<T>* topElement = list.Last();
        return list.Retrieve(topElement);
    }

    void makenull() {
        while (!empty()) {
            list.Delete(list.Previous(list.First()));
        }
        return std::numeric_limits<T>::max();
    }

    bool empty() {
        return list.First() == nullptr;
    }

    void print() {
        list.print();
    }
};

template <typename T>
class Stack2{
private:
    static const int size = 100;
    T arr[size];
    int topIndex;
public:
    Stack2(): topIndex(-1){

    }
    bool push(T x){
        if(topIndex+1 >= size){
            return false;
        }
        arr[topIndex+1]= x;
        topIndex++;
        return true;
    }
    T pop() {
        if (!empty()) {
            T topElement = arr[topIndex];
            topIndex--;
            return topElement;
        }
        return std::numeric_limits<T>::max();
    }
    T top() {
        if (empty()) {
            return std::numeric_limits<T>::max();
        }
        return arr[topIndex];
    }
    void makenull(){
        topIndex = -1;
    }
    bool empty(){
        return topIndex==-1;
    }
};

