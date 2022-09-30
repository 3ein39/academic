#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class BinaryTree {

private:
    struct Node {
        char data {};
        Node* left {};
        Node* right {};

        Node(char data) : data(data){}
    };
    Node* root;

public:
    BinaryTree(char root_value) : root(new Node(root_value)) {}
};

int main() {
    return 0;

}

/*
    printing expression tree in post-order
 */
