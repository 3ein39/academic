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
    
};