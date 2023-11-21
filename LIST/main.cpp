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

    void addMoreSpace() {
        int* newArray = new int[listCapacity * 2];

        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        for (int i = size; i < listCapacity * 2; i++) {
            newArray[i] = MIN;
        }
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


