#include <iostream>
using namespace std;

class Stack {
private:
    int size{};
    int top{};
    int* array {};
public:
    Stack(int size) : size(size), top(-1) {
        array = new int[size];
    }
    
};

int main() {

    return 0;
}