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

    // arr.insert(pos, val)
    void insert(int pos, int val) {
        if (size++ == capacity) expandCapacity();
        // shifting elements to the right
        for (int i = size; i > pos; i--)
            arr[i] = arr[i-1];
        // inserting val at pos
        arr[pos] = val;
    }

    void rightRotate() {
        int last = arr[size - 1]; // storing last element
        // shifting right
        for (int i = size - 1; i > 0; i--)
            arr[i] = arr[i - 1];
        // adding last as first
        arr[0] = last;
    }

    /*
     * right rotation with steps
     * 1 2 3
     * 3 1 2
     * 2 3 1
     * 1 2 3
     */
    void rightRotate(int times) {
        if (times % size + 1 == 0) times = 1;
        while (times--) {
            int last = arr[size - 1]; // storing last element
            // shifting right
            for (int i = size - 1; i > 0; i--)
                arr[i] = arr[i - 1];
            // adding last as first
            arr[0] = last;
        }
    }

    /*
     * deleting a position
     * 4 0 1 2 3
     * 0 1 2 3 4
     * pop(2)
     * 4 0 2 3
     * 0 1 2 3
     * cp = arr[pos]
     * shift left from pos to last - 1
     * size--
     * return cp;
     */
    int pop(int pos) {
        int cp = arr[pos];
        // shifting left
        for(int i = pos; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
        return cp;
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

    void leftRotate() {
        int first = arr[0];
        // shifting left
        for (int i = 0; i < size - 1; ++i)
            arr[i] = arr[i+1];
        // adding first as last
        arr[size - 1] = first;
    }
};

int main() {
    int n = 5;
    myVector v(n);

    for (int i = 0; i < n; ++i)
        v.set(i,i);

    v.print(); // 0 1 2 3 4

    cout << v.pop(2) << "\n"; // 2
    v.print(); // 0 1 3 4

    return 0;
}

