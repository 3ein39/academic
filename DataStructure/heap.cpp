#include<iostream>
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

    ~MinHeap() {
        delete[] array;
        array = nullptr;
    }
};