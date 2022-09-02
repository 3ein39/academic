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

    void display() {
        for (int i = top; i > -1; --i)
            cout << array[i] << " ";
        cout << "\n";
    }

    void insert_at_bottom(int x) {
        if (this->isEmpty()) {
            this->push(x);
            return;
        }

        int my_val = this->pop();
        insert_at_bottom(x);
        this->push(my_val);
    }

    void reverse() {
        if (isEmpty())
            return;

        int my_val = pop();

        reverse();

        insert_at_bottom(my_val);
    }
};

int main() {
    Stack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.reverse();

    s.display();

    return 0;
}

/*
 * instead of asserting .. more proper way is to throw an exception
 * but it is not our case her keep it simple fir educational purposes
 */