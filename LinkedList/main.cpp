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
        // destruktor, usuwanie wszystkich komorek
        while (header != nullptr) {
            cell<T>* kom = header;
            header = header->next;
            delete kom;
        }
    }

    // Wstawia nowy element x za komorke p
    void Insert(T x, cell<T>* p) {
        cell<T>* kom = new cell<T>;
        kom->element = x;

        // Aktualizuje wskazniki next i prev
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

        // Aktualizuje wskaznik prev
        if (p == nullptr) {
            header->prev = nullptr;
        }
    }

    // Usuwa komorke p z listy
    bool Delete(cell<T>* p) {
        if (p == nullptr || p->next == nullptr)
            return false;

        cell<T>* kom = p->next;
        p->next = kom->next;

        // Aktualizuje wskaznik prev komorki po usunieciu
        if (p->next != nullptr) {
            p->next->prev = p;
        } else {
            // Aktualizuje wskaznik prev
            if (header != nullptr) {
                header->prev = nullptr;
            }
        }

        delete kom;
        return true;
    }

    // Zwraca element komorki p
    T Retrieve(cell<T>* p) {
        return p->element;
    }

    // Znajduje komorke z elementem x
    cell<T>* Locate(T x) {
        cell<T>* kom = header;
        while (kom != nullptr && kom->element != x)
            kom = kom->next;
        return kom;
    }

    // Zwraca wskaznik do pierwszej komorki
    cell<T>* First() {
        return header;
    }

    // Zwraca wskaznik do następnej komorki po p
    cell<T>* Next(cell<T>* p) {
        return p->next;
    }

    // Zwraca wskaznik do ostatniej komorki
    cell<T>* Last() {
        cell<T>* kom = header;
        while (kom != nullptr && kom->next != nullptr)
            kom = kom->next;
        return kom;
    }

    // Zwraca wskaznik do poprzedniej komorki przed komorka p
    cell<T>* Previous(cell<T>* p) {
        if (p == nullptr || p == header) {
            return nullptr; // brak poprzedniego elementu dla pierwszej komorki
        }

        cell<T>* kom = header;
        while (kom != nullptr && kom->next != p) {
            kom = kom->next;
        }

        return kom;
    }

    // wyswietla elementy listy
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
class Lista2 {
protected:
    cell<T>* header;

public:
    Lista2() {
        header = nullptr;
    }

    ~Lista2() {
        // destruktor, usuwanie komorek
        while (header != nullptr) {
            cell<T>* kom = header;
            header = header->next;
            delete kom;
        }
    }


    void Insert(T x, cell<T>* p) {
        cell<T>* kom = new cell<T>;
        kom->element = x;
        kom->next = nullptr;  // inicjalizacja komorek
        kom->prev = nullptr;

        // Aktualizuje wskazniki next oraz prev komorek
        if (p != nullptr) {
            kom->next = p->next;
            p->next = kom;
            kom->prev = p;
        } else {
            if (header != nullptr) {
                header->prev = kom;
            }
            kom->next = header;
            header = kom;
        }

        if (kom->next != nullptr) {
            kom->next->prev = kom;
        }
    }

    // Usuwa komorke p z listy
    bool Delete(cell<T>* p) {
        if (p == nullptr)
            return false;

        if (p->prev != nullptr) {
            p->prev->next = p->next;
        } else {
            header = p->next;
        }

        if (p->next != nullptr) {
            p->next->prev = p->prev;
        }

        delete p;
        return true;
    }

    // Zwraca wskaznik do poprzedniej przed p
    cell<T>* Previous(cell<T>* p) {
        return p->prev;
    }

    // Zwraca element komorki p
    T Retrieve(cell<T>* p) {
        return p->element;
    }

    // Znajduje komorke zawierajaca element x
    cell<T>* Locate(T x) {
        cell<T>* kom = header;
        while (kom != nullptr && kom->element != x)
            kom = kom->next;
        return kom;
    }

    // Zwraca wskaznik do pierwszej komorki
    cell<T>* First() {
        return header;
    }

    // Zwraca wskaznik do nastepnej komorki po p
    cell<T>* Next(cell<T>* p) {
        return p->next;
    }

    // Zwraca wskaznik do ostatniej komorki
    cell<T>* Last() {
        cell<T>* kom = header;
        while (kom != nullptr && kom->next != nullptr)
            kom = kom->next;
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
    T* array;           // Tablica przechowująca elementy kolejki
    int capacity;       // Pojemność kolejki (maksymalna liczba elementów)
    int frontIndex;      // Indeks początku kolejki
    int rearIndex;       // Indeks końca kolejki
    int currentSize;     // Aktualna liczba elementów w kolejce

public:
    // Konstruktor
    CircularQueue(int size) : capacity(size), frontIndex(-1), rearIndex(-1), currentSize(0) {
        array = new T[capacity];
    }

    // Destruktor
    ~CircularQueue() {
        delete[] array;
    }

    // Dodaje element do kolejki
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

    // Pobiera (i usuwa) pierwszy element z kolejki
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
            frontIndex = (frontIndex+1)%capacity; //gdy indeks frontu osiągnie końcową pozycję tablicy, dzięki wyrażeniu (frontIndex + 1) % capacity
            // , indeks frontu jest przesuwany na początek tablicy, tworząc efekt cykliczny w kolejkach.
        }
        currentSize--;
        return firstElement;
    }

    // Zwraca element znajdujący się na początku kolejki (bez usuwania)
    T front() {
        if(empty()){
            throw std::out_of_range("queue empty");
        }
        T firstElement = array[frontIndex];
        return firstElement;
    }

    // Usuwa wszystkie elementy z kolejki
    void makenull() {
        frontIndex = 0;
        rearIndex =0;
        currentSize = 0;
    }

    // Sprawdza, czy kolejka jest pusta
    bool empty() {
        if(currentSize==0) {
            return false;
        }else{
            return true;
        }
    }

    // Sprawdza, czy kolejka jest pełna
    bool isFull() {
        return currentSize == capacity;
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


int main() {
    // Test the Stack class

    Stack<int> intStack;

    // Push some elements onto the stack
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    // Print the stack
    std::cout << "Stack: ";
    intStack.print();

    // Pop an element
    int poppedElement = intStack.pop();
    std::cout << "Popped Element: " << poppedElement << std::endl;

    // Print the stack after popping
    std::cout << "Stack: ";
    intStack.print();

    // Get the top element
    int topElement = intStack.top();
    std::cout << "Top Element: " << topElement << std::endl;

    // Check if the stack is empty
    std::cout << "Is the stack empty? " << (intStack.empty() ? "Yes" : "No") << std::endl;

    Stack2<int> myStack;
    std::cout << "Pushing elements onto the stack:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Push: " << i << std::endl;
        myStack.push(i);
    }

    std::cout << "Testing top() without popping:" << std::endl;
    std::cout << "Top: " << myStack.top() << std::endl;

    // Test case 2: Create a stack, push elements, and pop one element
    std::cout << "Pushing elements onto the stack:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Push: " << i << std::endl;
        myStack.push(i);
    }

    std::cout << "Popping one element from the stack:" << std::endl;
    std::cout << "Pop: " << myStack.pop() << std::endl;

    // Test case 3: Create a stack, push one element, and pop it
    std::cout << "Pushing one element onto the stack:" << std::endl;
    std::cout << "Push: 42" << std::endl;
    myStack.push(42);

    std::cout << "Popping one element from the stack:" << std::endl;
    std::cout << "Pop: " << myStack.pop() << std::endl;



    return 0;
}