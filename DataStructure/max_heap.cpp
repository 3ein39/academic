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
};