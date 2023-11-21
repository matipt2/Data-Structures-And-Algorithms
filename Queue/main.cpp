#include <iostream>
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
class Queue{
private:
    Lista1<T> list;

public:
    void put(T x){
        list.Insert(x, list.Last());
    }

    T get(){
        if(empty()){
            throw std::out_of_range("queue empty");
        }
        else{
            cell<T>* firstElement = list.First();
            T element = list.Retrieve(firstElement);
            list.Delete(firstElement);
            return element;
        }
    }

    T front(){
        if(empty()){
            throw std::out_of_range("queue empty");
        }
        else{
            cell<T>* firstElement = list.First();
            return list.Retrieve(firstElement);

        }
    }

    void makenull(){
        while(!empty()){
            list.Delete(list.First());
        }
    }
    bool empty(){
        return list.First()==nullptr;
    }
};
template <typename T>
class CircularQueue {
private:
    T* array;
    int capacity;
    int frontIndex;
    int rearIndex;
    int currentSize;

public:
    CircularQueue(int size) : capacity(size), frontIndex(-1), rearIndex(-1), currentSize(0) {
        array = new T[capacity];
    }

    ~CircularQueue() {
        delete[] array;
    }

    bool put(T x) {
        if(currentSize == capacity){
            return false;
        }
        if(empty()){
            frontIndex = 0;
        }
        rearIndex = (rearIndex + 1) % capacity;
        array[rearIndex] = x;
        currentSize++;
        return true;
    }

    T get() {
        T firstElement = array[frontIndex];
        if(empty()){
            throw std::out_of_range("queue empty");
        }
        if(frontIndex==rearIndex){
            frontIndex= -1;
            rearIndex = -1;
        }
        else{
            frontIndex = (frontIndex+1)%capacity;
        }
        currentSize--;
        return firstElement;
    }

    T front() {
        if(empty()){
            throw std::out_of_range("queue empty");
        }
        T firstElement = array[frontIndex];
        return firstElement;
    }

    void makenull() {
        frontIndex = 0;
        rearIndex =0;
        currentSize = 0;
    }

    bool empty() {
        return currentSize==0;
    }

    bool isFull() {
        return currentSize == capacity;
    }
};

