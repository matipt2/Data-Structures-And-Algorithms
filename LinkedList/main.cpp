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


int main() {
    std::cout << "" << std::endl;
    std::cout << "Lista jednokierunkowa" << std::endl;
    std::cout << "" << std::endl;
    Lista1<int> list1;
    list1.Insert(55, list1.Last());
    list1.Insert(31, list1.Last());
    list1.Insert(44, list1.Last());
    std::cout << "po wstawieniu 3 elementow: ";
    list1.print();


    list1.Insert(5, 0);
    std::cout << "po wstawieniu na poczetku 5: ";
    list1.print();

    list1.Delete(list1.Previous(list1.Last()));
    std::cout << "po usunieciu ostatniego elementu: ";
    list1.print();

    cell<int>* cell5 = list1.Locate(5);
    if (cell5 != nullptr)
        std::cout << "Znaleziono element 5\n";
    else
        std::cout << "Nie znaleziono elementu 5\n";

    cell<int>* cell6 = list1.Locate(30);
    if (cell6 != nullptr) {
        std::cout << "Znaleziono element 30\n";
        list1.Delete(cell6);
        std::cout << "po usunieciu elementu 30: ";
        list1.print();
    } else {
        std::cout << "Nie znaleziono elementu 30\n";
    }
    std::cout << "" << std::endl;
    std::cout << "Lista dwukierunkowa" << std::endl;
    std::cout << "" << std::endl;
    Lista2<int> list2;
    list2.Insert(230, list2.Last());
    list2.Insert(24, list2.Last());
    list2.Insert(36, list2.Last());
    std::cout << "po wstawieniu 3 elementow: ";
    list2.print();

    list2.Insert(15, list2.Previous(list2.Last()));
    std::cout << "po wstawieniu przed ostatnim elementem 15: ";
    list2.print();

    list2.Delete(list2.First());
    std::cout << "po usunieciu pierwszego elementu: ";
    list2.print();

    cell<int>* cell7 = list2.Locate(15);
    if (cell7 != nullptr)
        std::cout << "Znaleziono element 15\n";
    else
        std::cout << "Nie znaleziono elementu 15\n";

    cell<int>* cell8 = list2.Locate(10);
    if (cell8 != nullptr) {
        std::cout << "Znaleziono element 10\n";
        list2.Delete(cell8);
        std::cout << "po usunieciu elementu 10: ";
        list2.print();
    } else {
        std::cout << "Nie znaleziono elementu 10\n";
    }


    cell<int>* cell30 = list2.Locate(30);
    if (cell30 != nullptr) {
        int wartość = list2.Retrieve(cell30);
        std::cout << "Pobrana wartosc z komorki z elementem 30: " << wartość << std::endl;
    }

    cell<int>* pierwszaKomorka = list2.First();
    std::cout << "Pierwszy element: " << list2.Retrieve(pierwszaKomorka) << std::endl;
    //koniec

    return 0;
}
