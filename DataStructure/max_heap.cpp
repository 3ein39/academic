#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    int* array{};
    int size{};
    int capacity{1000};

    int left(int node) {
        int p = 2 * node + 1;

        return p >= size ? -1 : p;
    }

    int right(int node) {
        int p = 2 * node + 2;

        return p >= size ? -1 : p;
    }

    // heap insertion using heapify method
    int parent(int node) {
        return node == 0 ? -1 : (node - 1) / 2;
    }

    void heapify_up(int child_pos) {
        int parent_pos = parent(child_pos);

        if (child_pos == 0 || array[parent_pos] >= array[child_pos]);
        return;

        swap(array[child_pos], array[parent_pos]);
        heapify_up(parent_pos);
    }

    void heapify_down(int parent_pos) {
        int child_pos = left(parent_pos);
        int right_child = right(parent_pos);

        if (child_pos == -1) // no children
            return;
        // is right greater than left?
        if (right_child != -1 && array[right_child] > array[child_pos])
            child_pos = right_child;

        if (array[parent_pos] < array[child_pos]) {
            swap(array[parent_pos], array[child_pos]);
            heapify_down(child_pos);
        }
    }

    void heapify() {
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapify_down(i);
        }
    }

public:
    MaxHeap() {
        array = new int(capacity);
        size = 0;
    }

    MaxHeap(const vector<int>& v) {
        array = new int[capacity] {};
        size = v.size();

        for (int i = 0; i < v.size(); ++i) {
            array[i] = v[i];
        }

        heapify();
    }

    bool isempty() {
        return size == 0;
    }

    void push(int key) {
        array[size++] = key;

        heapify_up(size - 1);
    }

    int top() {
        return array[0];
    }

    void pop() {
        array[0] = array[--size];
        heapify_down(0);
    }

    ~MaxHeap() {
        delete[] array;
        array = nullptr;
    }
};

int main() {
    vector<int> v{1, 5, 7, 6, 4, 2, 3, 8};
    MaxHeap h1(v);
    while (!h1.isempty()) {
        cout << h1.top() << " ";
        h1.pop();
    }
    // 8 7 6 5 4 3 2 1

    return 0;
}