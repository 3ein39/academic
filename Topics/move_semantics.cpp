#include<iostream>
#include<utility>
#include<vector>
using namespace std;

class MyPair {
private:
    int *firstPtr = nullptr;
    int *secondPtr = nullptr;
public:
    MyPair(int first = 0, int second = 0) {
        cout<<"Constructor\n";
        SetFirst(first), SetSecond(second);
    }
    /*
     * as operator overloading
     * but ...
     * Rvalue reference has a higher priority
     */
    MyPair(MyPair&& other) {
        // rvalue reference operator
        // move constructor
        cout << "move constructor\n";
        // 1) copy pointer address
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        // 2) Null other
        other.firstPtr = other.secondPtr = nullptr;

    }
    /*
     * in copy constructors we are creating new int *
     * and then moving the data
     * ... that's why move constructors is more optimized in terms of performance
     */
    MyPair(const MyPair& other) {
        cout<<"Copy Constructor\n";
        SetFirst(*other.firstPtr), SetSecond(*other.secondPtr);
    }
    void print() {
        cout << "(" << *firstPtr << "," << *secondPtr << ")\n";
    }
    int GetFirst() const {
        return *firstPtr;
    }
    void SetFirst(int first) {
        if (firstPtr == nullptr)
            firstPtr = new int;
        *firstPtr = first;
    }
    int GetSecond() const {
        return *secondPtr;
    }
    void SetSecond(int second) {
        if (secondPtr == nullptr)
            secondPtr = new int;
        *secondPtr = second;
    }
    ~MyPair() {
        cout<<"~MyPair()\n";

        if (!firstPtr && !secondPtr)
            cout << "\tFreed already by a move!\n";
        /*
         * very important before deleting anything to double-check
         * if it is freed or not
         */
        if (firstPtr != nullptr)
            delete firstPtr;

        if (secondPtr != nullptr)
            delete secondPtr;
    }
};

int main() {
    vector<MyPair> v;

    v.push_back(MyPair(3, 6)); // rvalue
    // Constructor for temp MyPair(3, 6)
        // Create 2 integers
    // Move constructor
        // No creation/copying
    // ~MyPair()
        // already freed by a move
    // ~MyPair()
        // Delete 2 integers from the actual vector

        MyPair p1(1, 5);
        MyPair p2(p1); // lvalue gonna call copy constructor

    return 0;
}
