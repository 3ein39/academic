//
// Created by hussein on 8/4/22.
//
#include<bits/stdc++.h>
using namespace std;

class myVector {
private:
    int* arr = nullptr;
    int size;
    int capacity {};
public:
    // constructor
    myVector(int size) : size(size) {
        // exception handling
        if (size < 0) size = 1;

        capacity = size + 10;

        arr = new int[capacity] {};
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

    int get_front() {
        return arr[0];
    }

    int get_back() {
        return arr[size - 1];
    }

    // appending to the end of the array
    // arr.push_back(val) => void
    void push_back(int val) {
        // expanding if size matches capacity
        if (size == capacity)
            expandCapacity();
        arr[size++] = val;
    }

    void expandCapacity() {
        capacity *= 2;
        cout << "Expanding capacity to " << capacity << endl;
        // creating new array
        int* new_arr = new int[capacity];
        // copying old data
        for(int i = 0; i < size; i++)
            new_arr[i] = arr[i];
        // swapping the two pointers
        swap(arr, new_arr);
        // deleting the pointer
        delete[] new_arr;
        new_arr = nullptr;
    }
};

int main() {
    int n = 5;
    myVector v(n);

    for (int i = 0; i < n; ++i)
        v.set(i,i);

    for(int i = 0; i < n*2+1; i++)
        v.push_back(i+n);

    v.print();
}

