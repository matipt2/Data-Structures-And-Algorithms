#include <iostream>
using namespace std;

#define MIN (-10000000) // Definiujemy stałą MIN.

class List {
private:
    int array[10]; // Tablica przechowująca elementy listy.
    int size; // Aktualny rozmiar listy.
    int last; // Indeks ostatniego elementu na liście.

public:
    List() {
        size = 0; // Początkowo lista jest pusta, więc rozmiar wynosi 0.
        last = -1; // Brak elementów w tablicy, więc last jest -1.
        for (int i = 0; i < 10; i++) {
            array[i] = MIN; // Inicjalizujemy tablicę wartością MIN.
        }
    }

    int first() {
        if (size == 0) {
            return -1; // Lista jest pusta.
        }
        return 0; // Zwracamy indeks pierwszego elementu.
    }

    int end() {
        return last + 1; // Zwracamy indeks za ostatnim elementem.
    }

    int next(int p) {
        if (p < 0 || p >= last) {
            return -1; // Niepoprawna pozycja.
        }
        return p + 1; // Zwracamy indeks następnego elementu.
    }

    int previous(int p) {
        if (p <= 0 || p > last) {
            return -1; // Niepoprawna pozycja.
        }
        return p - 1; // Zwracamy indeks poprzedniego elementu.
    }

    bool Insert(int x, int p) {
        if (size >= 10) {
            return false; // Lista jest pełna.
        }

        if (p < 0 || p > last + 1) {
            return false; // Niepoprawna pozycja.
        }

        for (int i = last; i >= p; i--) {
            array[i + 1] = array[i]; // Przesuwamy elementy, aby zrobić miejsce dla nowego elementu.
        }

        array[p] = x; // Wstawiamy nowy element.
        size++; // Zwiększamy rozmiar listy.
        last++; // Aktualizujemy indeks ostatniego elementu.
        return true; // Operacja zakończona sukcesem.
    }

    bool Delete(int p) {
        if (p < 0 || p > last) {
            return false; // Niepoprawna pozycja.
        }

        for (int i = p; i < last; i++) {
            array[i] = array[i + 1]; // Usuwamy element przesuwając pozostałe elementy.
        }

        array[last] = MIN; // Ostatni element otrzymuje wartość MIN.
        size--; // Zmniejszamy rozmiar listy.
        last--; // Aktualizujemy indeks ostatniego elementu.
        return true; // Operacja zakończona sukcesem.
    }

    int Locate(int x) {
        for (int i = 0; i <= last; i++) {
            if (array[i] == x) {
                return i; // Znaleziono element.
            }
        }
        return -1; // Element nie został znaleziony.
    }

    int Retrieve(int p) {
        if (p >= 0 && p <= last) {
            return array[p]; // Zwracamy element na danej pozycji.
        }
        return MIN; // Niepoprawna pozycja lub brak elementu na danej pozycji.
    }

    void GetRidOffDuplicates() {
        for (int i = 0; i <= last; i++) {
            for (int j = i + 1; j <= last;) {
                if (array[i] == array[j]) {
                    Delete(j); // Usuwamy duplikat.
                } else {
                    j++; // Przechodzimy do następnego elementu.
                }
            }
        }
    }
};


int main() {
    List myList;

    // Test dla metody Insert
    myList.Insert(10, 0); // Dodajemy 10 na pozycję 0
    myList.Insert(20, 1); // Dodajemy 20 na pozycję 1
    myList.Insert(30, 2); // Dodajemy 30 na pozycję 2


    cout<<myList.Delete(2)<<endl;
    for(int i=0;i<5;i++){
        cout<<myList.Retrieve(i)<<endl;
    }

//    // Test dla metody Retrieve
//    cout << myList.Retrieve(0) << endl; // Powinno wyświetlić 10
//    cout << myList.Retrieve(1) << endl; // Powinno wyświetlić 20
//    cout << myList.Retrieve(2) << endl; // Powinno wyświetlić 30
//
//    // Test dla metody Locate
//    cout << myList.Locate(10) << endl; // Powinno wyświetlić 0
//    cout << myList.Locate(20) << endl; // Powinno wyświetlić 1
//    cout << myList.Locate(30) << endl; // Powinno wyświetlić 2
//
//    // Test dla metody Delete
//    myList.Delete(1); // Usuwamy element na pozycji 1
//
//    // Test dla metody Retrieve po usunięciu elementu
//    cout << myList.Retrieve(0) << endl; // Powinno wyświetlić 10
//    cout << myList.Retrieve(1) << endl; // Powinno wyświetlić 30

    return 0;
}

