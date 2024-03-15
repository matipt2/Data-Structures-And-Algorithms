#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class PriorityQueue {
private:
    std::vector<T> heap;

    void heapifyUp(int i) {
        if (i && heap[parent(i)] < heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            heapifyUp(parent(i));
        }
    }

    void heapifyDown(int i) {
        int left = child(i);
        int right = child(i) + 1;

        int largest = i;

        if (left < size() && heap[left] > heap[i])
            largest = left;

        if (right < size() && heap[right] > heap[largest])
            largest = right;

    }

    int parent(int i) { return (i - 1) / 2; }
    int child(int i) { return 2 * i + 1; }

public:
    unsigned int size() const { return heap.size(); }

    bool empty() const { return size() == 0; }

    void push(const T& key) {
        heap.push_back(key);
        int index = size() - 1;
        heapifyUp(index);
    }

    void pop() {
        if (size() == 0)
            throw std::out_of_range("Heap is empty");

        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
    }

    const T& top() const {
        if (size() == 0)
            throw std::out_of_range("Heap is empty");

        return heap.front();
    }
};

int main() {
    return 0;
}
