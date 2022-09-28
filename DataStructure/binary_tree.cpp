#include <iostream>
using namespace std;

class Node {
public:
    int data {};
    Node* left {};
    Node* right {};

    Node() : left(nullptr), right(nullptr) {}

    Node(int data) {
        this->data = data;
    }

    void print(Node* node) { // LVR printing
        if (!node->left && !node->right) {
            cout << node->data << " ";
            return;
        }

        if (node->left)
            print(node->left);

        cout << node->data << " ";

        if (node->right)
            print(node->right);
    }
};


int main() {

    // Create Nodes
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);

    // Link them!
    root->left = node2;
    root->right = node3;

    node2->left = node4;
    node2->right = node5;

    node5->right = node7;

    node3->right = node6;

    node6->left = node8;

    root->print(root); // 4 2 5 7 1 3 8 6

    return 0;
}

/*
 * traversing a binary tree LVR
 */
