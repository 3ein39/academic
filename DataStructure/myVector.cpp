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

    int get_front() {
        return arr[0];
    }

    int get_back() {
        return arr[size - 1];
    }

    // appending to the end of the array
    // arr.push_back(val) => void
    void push_back(int val) {
        // create new array of bigger size
        int* new_arr = new int[size + 1];
        // copy old data
        for (int i = 0; i < size; i++)
            new_arr[i] = arr[i];
        // add new el and increase the size
        new_arr[size++] = val;
        // change the pointers
        swap(new_arr,arr);
        // remove the useless data
        delete[] new_arr;
    }
};

int main() {
    int n = 4;
    myVector v(n);

    for (int i = 0; i < n; ++i)
        v.set(i,i);

    v.push_back(15);
    v.push_back(17);
    v.push_back(19);
    v.print(); // 0 1 2 3 15 17 19
    
}

