#include <iostream>
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
};

int main() {
    cout << "Hello world";

    return 0;
}