#include <iostream>

template <typename T>
class cell {
public:
    T element;
    cell *next;
};

template <typename T>
class Lista {
protected:
    cell<T> *header;
public:
    Lista() {
        header = nullptr;
    }

    ~Lista() {
        while (header != nullptr) {
            cell<T> *temp = header;
            header = header->next;
            delete temp;
        }
    }

    void Insert(T x, cell<T> *p) {
        cell<T> *newCell = new cell<T>;
        newCell->element = x;
        if (p == nullptr) {
            newCell->next = header;
            header = newCell;
        } else {
            newCell->next = p->next;
            p->next = newCell;
        }
    }

    bool Delete(cell<T> *p) {
        if (p == nullptr || p->next == nullptr) {
            return false;
        }
        cell<T> *temp = p->next;
        p->next = p->next->next;
        delete temp;
        return true;
    }

    T Retrieve(cell<T> *p) {
        if (p != nullptr && p->next != nullptr) {
            return p->next->element;
        }
        return T();
    }

    cell<T> *Locate(T x) {
        cell<T> *temp = header;
        while (temp != nullptr) {
            if (temp->element == x) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    cell<T> *First() {
        return header;
    }

    cell<T> *Next(cell<T> *p) {
        if (p != nullptr) {
            return p->next;
        }
        return nullptr;
    }

    cell<T> *Previous(cell<T> *p) {
        if (p == nullptr || p == header) {
            return nullptr;
        }
        cell<T> *temp = header;
        while (temp != nullptr && temp->next != p) {
            temp = temp->next;
        }
        return temp;
    }

    cell<T> *Last() {
        cell<T> *temp = header;
        while (temp != nullptr && temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

    void print() {
        cell<T> *temp = header;
        while (temp != nullptr) {
            std::cout << temp->element << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    Lista<int> lista;

    // Testujemy metodę Insert
    lista.Insert(1, nullptr); // Dodajemy 1 na początek listy
    lista.Insert(2, lista.First()); // Dodajemy 2 na drugą pozycję
    lista.Insert(3, lista.Last()); // Dodajemy 3 na koniec listy

    // Wyświetlamy listę, powinno wyjść: 1 2 3
    lista.print();

    // Testujemy metodę Delete
    lista.Delete(lista.First()); // Usuwamy pierwszy element
    lista.Delete(lista.Last()); // Usuwamy ostatni element

    // Wyświetlamy listę, powinno wyjść: 2
    lista.print();

    // Testujemy metodę Retrieve
    std::cout << "Element na pierwszej pozycji: " << lista.Retrieve(lista.First()) << std::endl;

    // Testujemy metodę Locate
    cell<int> *cell = lista.Locate(2);
    if (cell != nullptr) {
        std::cout << "Znaleziono element 2" << std::endl;
    } else {
        std::cout << "Nie znaleziono elementu 2" << std::endl;
    }

    // Testujemy metodę Next
    cell = lista.Next(lista.First());
    if (cell != nullptr) {
        std::cout << "Następny element po pierwszym: " << cell->element << std::endl;
    } else {
        std::cout << "Brak następnego elementu po pierwszym" << std::endl;
    }

    // Testujemy metodę Previous
    cell = lista.Previous(lista.First());
    if (cell != nullptr) {
        std::cout << "Poprzedni element przed pierwszym: " << cell->element << std::endl;
    } else {
        std::cout << "Brak poprzedniego elementu przed pierwszym" << std::endl;
    }

    // Testujemy metodę Last
    std::cout << "Ostatni element na liście: " << lista.Last()->element << std::endl;

    return 0;
}
