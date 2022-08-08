#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data {};
    Node* next {}; // pointer to same object

    Node(int data) : data(data) {}
};

class LinkedList {
private:
    Node* head {};
    Node* tail {};
    int length {};
public:
    // operations on them
    void print() {
        // convenient way of printing
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    // getting nth node 1-based
    Node* get_nth(int n) {
        int cnt {0};
        for (Node* cur = head; cur; cur = cur->next)
            if (++cnt == n) return cur;
        return nullptr;
    }

    // search for a value 0-based
    int search(int val) {
        int idx = 0;
        for(Node* cur = head; cur; cur = cur->next, idx++)
            if (cur->data == val)
                return idx;
        return -1;
    }

    void insertEnd(int val) {
        Node* item = new Node(val);

        if (!head)
            head = tail = item;
        else {
            tail-> next = item;
            tail = item;
        }
        length++;
    }
};

int main() {
    // creating 4 nodes
    Node* node1 = new Node(6);
    Node* node2 = new Node(10);
    Node* node3 = new Node(8);
    Node* node4 = new Node(15);
    // linking them together
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;


    return 0;
}