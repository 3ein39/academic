#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string data {};
    Node* left {};
    Node* right {};

    Node() : left(nullptr), right(nullptr) {}

    Node(string data) {
        this->data = data;
    }

    void print(Node* node) { // LVR printing
        if (!node->left && !node->right) {
            cout << node->data << " ";
            return;
        }

        if (node->left)
            print(node->left);


        if (node->right)
            print(node->right);

        cout << node->data << " ";
    }

    ~Node() {
        cout << "Node : " << data << " \tdestructed\n";
    }
};


int main() {

    Node* plus = new Node("+");
    Node* lop = new Node("2");
    Node* rop = new Node("3");

    plus->left = lop;
    plus->right = rop;

    Node* multi = new Node("*");
    Node* op = new Node("4");

    multi->right = op;
    multi->left = plus;

    plus->print(multi);

    return 0;

}

/*
    printing expression tree in post-order
 */
