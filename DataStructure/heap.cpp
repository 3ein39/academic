#include<iostream>
#include <cassert>
using namespace std;

class MinHeap {
private:
    int* array{};
    int size {};
    int capacity {1000}; // as same as capacity in vector ... for simplicity
public:
    MinHeap() {
        array = new int(capacity) {};
        size = 0;
    }

    // heap insertion using heapify method
    int parent(int child_pos) {
        return child_pos == 0 ? -1 : (child_pos - 1) / 2;
    }

    void heapify_up(int child_pos) {
        int parent_pos = parent(child_pos);

        if (child_pos == 0 || array[parent_pos] <= array[child_pos])
            return;

        swap(array[child_pos], array[parent_pos]);
        heapify_up(parent_pos);
    }

    void push(int key) {
        assert(size + 1 <= capacity);
        array[size++] = key;

        heapify_up(size - 1);
    }

    int top() {
        assert(!isempty());
        return array[0];
    }

    ~MinHeap() {
        delete[] array;
        array = nullptr;
    }
};