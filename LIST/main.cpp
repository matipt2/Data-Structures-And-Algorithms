#include <iostream>
using namespace std;

#define MIN (-10000000)

class List {
private:
    int* array;
    int size;
    int last;
    int listCapacity;

public:
    List() {
        size = 0;
        last = -1;
        listCapacity = 10;
        array = new int[listCapacity];
        for (int i = 0; i < listCapacity; i++) {
            array[i] = MIN;
        }
    }

    ~List() {
        delete[] array;
    }

    // Funkcja addMoreSpace() dynamicznie zwieksza pojemnosc tablicy
    // gdy lista osiąga swoją pojemność. Nowa pojemność wynosi dwukrotność

    void addMoreSpace() {
        // stworzenie nowej tablicy z dwa razy wieksza pojemnoscia
        int* newArray = new int[listCapacity * 2];

        //przeniesienie elementow ze starej tablicy do nowej
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        // wypelnienie tych pozostalych miejsc liczba MIN
        for (int i = size; i < listCapacity * 2; i++) {
            newArray[i] = MIN;
        }
        // usuneicie starej tablicy i przypisanie nowej tablicy wartosci starej
        delete[] array;
        array = newArray;
        listCapacity *= 2;
    }

    int Next(int p) {
        if (p < 0 || p >= last) {
            return -1;
        }
        return p + 1;
    }

    bool Delete(int p) {
        if (p < 0 || p > last) {
            return false;
        }

        for (int i = p; i < last; i++) {
            array[i] = array[i + 1];
        }

        array[last] = MIN;
        size--;
        last--;
        return true;
    }

    int Previous(int p) {
        if (p <= 0 || p > last) {
            return -1;
        }
        return p - 1;
    }

    bool Insert(int x, int p) {
        if (size >= listCapacity) {
            addMoreSpace();
        }

        if (p < 0 || p > last + 1) {
            return false;
        }

        for (int i = last; i >= p; i--) {
            array[i + 1] = array[i];
        }

        array[p] = x;
        size++;
        last++;
        return true;
    }

    int Locate(int x) {
        for (int i = 0; i <= last; i++) {
            if (array[i] == x) {
                return i;
            }
        }
        return -1;
    }
    int First() {
        if (size == 0) {
            return -1;
        }
        return 0;
    }

    int End() {
        return last + 1;
    }

    int Retrieve(int p) {
        if (p >= 0 && p <= last) {
            return array[p];
        }
        return MIN;
    }

};


int main() {
    List myList;



    myList.Insert(5, 0);
    myList.Insert(16, 1);
    myList.Insert(53, 2);
    myList.Insert(23,3);
    myList.Insert(432,4);


    for (int i = 0; i < myList.End(); i++) {
        cout << "elementy listy " << i << ": " << myList.Retrieve(i) << endl;
    }
    cout<<" "<<endl;
    cout << "usuniecie pierwszego indexu: " << myList.Delete(1) << endl;
    cout<<" "<<endl;

    for (int i = 0; i < myList.End(); i++) {
        cout << "elementy indexowane po i:  " << i << ": " << myList.Retrieve(i) << endl;
    }

    cout<<" "<<endl;

    cout << "53 jest na miejscu: " << myList.Locate(53) << endl;

    cout<<" "<<endl;

    cout << "pozycja po 0: " << myList.Next(0) << endl;

    cout<<" "<<endl;

    cout << "pozycja przed 2: " << myList.Previous(2) << endl;
    cout<<" "<<endl;

    cout << "pierwszy index: " << myList.First() << endl;
    cout<<" "<<endl;

    cout << "ostatni index: " << myList.End() << endl;
    cout<<" "<<endl;


    cout << "wartosc na indexie -1: " << myList.Retrieve(-1) << endl;
    cout << "wartosc na indexie 0: " << myList.Retrieve(0) << endl;
    cout << "wartosc na indexie 3: " << myList.Retrieve(3) << endl;
    cout << "wartosc na indexie 5: " << myList.Retrieve(5) << endl;

    return 0;
}

