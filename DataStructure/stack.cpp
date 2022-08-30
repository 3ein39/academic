#include <iostream>
#include <cassert>

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

    void push(int e) {
        assert(!isFull());
        array[++top] = e;
    }

    int pop() {
        assert(!isEmpty());
        return array[top--];
    }

    int peek() {
        assert(!isEmpty());
       return array[top];
    }

    bool isFull() {
        if (top == size)
            return 1;
        return 0;
    }

    bool isEmpty() {
        if (top == -1)
            return 1;
        return 0;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek();

    return 0;
}

/*
 * instead of asserting .. more proper way is to throw an exception
 * but it is not our case her keep it simple fir educational purposes
 */