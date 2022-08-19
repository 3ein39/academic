#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data {};
    Node* next {};
    Node* prev {};

    Node(int data) : data(data) {}

    void Set(Node* next, Node* prev) {
        this->next = next;
        this->prev = prev;
    }
    
    ~Node() {
        cout << "Destroy value " << data << " at address " << this << "\n";
    }
};

int main() {

}