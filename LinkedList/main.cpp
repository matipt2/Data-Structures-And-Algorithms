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
class Lista2 {
protected:
    cell<T>* header;

public:
    Lista2() {
        header = nullptr;
    }

    ~Lista2() {
        while (header != nullptr) {
            cell<T>* kom = header;
            header = header->next;
            delete kom;
        }
    }


    void Insert(T x, cell<T>* p) {
        cell<T>* kom = new cell<T>;
        kom->element = x;
        kom->next = nullptr;
        kom->prev = nullptr;


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

    cell<T>* Previous(cell<T>* p) {
        return p->prev;
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


    void print() {
        cell<T>* kom = header;
        while (kom != nullptr) {
            std::cout << kom->element << " ";
            kom = kom->next;
        }
        std::cout << std::endl;
    }
};
