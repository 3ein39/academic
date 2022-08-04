//
// Created by hussein on 8/4/22.
//
#include<bits/stdc++.h>
using namespace std;

class myVector {
private:
    int* arr = nullptr;
    int size;
public:
    // constructor
    myVector(int size) : size(size) {
        // exception handling
        if (size < 0) size = 1;

        arr = new int[size] {};
    }

    // destructor
    ~myVector() {
        delete[] arr;
        arr = nullptr;
    }

    // setters and getters
    void set(int idx, int val) {
        if (!(idx >=0 && idx < size)) assert(false);
        arr[idx] = val;
    }

    // arr.get(idx) => rvalue
    int get(int idx) {
        if (!(idx >=0 && idx < size)) assert(false);
        return arr[idx];
    }

    void print() {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    // arr.find(val) => idx found, -1 !found
    int find(int val) {
        for (int i = 0; i < size; ++i)
            if (val == arr[i]) return i;
        return -1;
    }
};

int main() {
    myVector v(10);

    for (int i = 0; i < 10; ++i) {
        v.set(i, i);
    }

    v.print();
    cout << v.find(5) << " " << v.find(55);
}

