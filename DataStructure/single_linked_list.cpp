#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next; // pointer to same object

    Node(int data) : data(data) {}
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

    cout << node4->data << "\n";
    cout << node3->next->data << "\n";
    cout << node2->next->next->data << "\n";
    cout << node1->next->next->next->data << "\n";

    return 0;
}