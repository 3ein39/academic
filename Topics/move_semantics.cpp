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
        if (firstPtr != nullptr)
            delete firstPtr;

        if (secondPtr != nullptr)
            delete secondPtr;
    }
};

int main() {
    vector<MyPair> v;

    v.push_back(MyPair(3, 6)); // rvalue
    // Constructor for temp MyPair(3, 6)       ^
    // Create 2 integers                       |
    // Copy Constructor                        |
    // Create 2 integers, copy data            |
    // ~MyPair()                               |
    // Delete 2 integers of tmp  - - - - - - - |
    // ~MyPair()
    // Delete 2 integers from the actual vector


    return 0;
}
