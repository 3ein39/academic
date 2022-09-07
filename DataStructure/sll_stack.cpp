#include <iostream>
#include <cassert>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next{};

        Node(int data) : data(data) {};
    };
    Node* head{};

    void link(Node* first, Node* second) {
        if (first)
            first->next = second;
    }
public:
    void push(int data) {
        // Great match with stack
        Node* item = new Node(data);

        link(item, head);
        head = item;
        // This push function works as long as machine has more ram
    }

    int peek() {
        assert(!isEmpty());

        return head->data;
    }

    int pop() {
        assert(!isEmpty());

        int el = head->data;
        Node* temp = head;
        head = head->next;

        delete temp;
        return el;
    }

    bool isEmpty() {
        return !head;
    }
};

int main() {
    cout << "Hello world";

    return 0;
}