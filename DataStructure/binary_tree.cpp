#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class BinaryTree {

private:
    struct Node {
        int data {};
        Node* left {};
        Node* right {};

        Node(int data) : data(data){}
    };
    Node* root;

    void print_inorder(Node* current) {
        if (!current)
            return;
        print_inorder(current->left);
        cout << current->data << " ";
        print_inorder(current->right);
    }

    int get_max(Node* current) {
        int max_val = 0;

        if (!current)
            return 0;

        max_val = max(max_val, get_max(current->right));
        max_val = max(max_val, get_max(current->left));
        return max(max_val, current->data);
    }

    int get_height(Node* current) {
        int h = 0;

        if (!current)
            return 0;

        h = max(get_height(current->left), get_height(current->right));
        return h + 1;
    }
public:
    BinaryTree(int root_value) : root(new Node(root_value)) {}

    void add(vector<int> values, vector<char> directions) {
        assert(values.size() == directions.size());
        Node* current = this->root;

        for (int i = 0; i < values.size(); ++i) {
            if (directions[i] == 'L') {
                if (!current->left)
                    current->left = new Node(values[i]);
                else
                    assert(current->left->data == values[i]);
                current = current->left;
            }
            else {
                if (!current->right)
                    current->right = new Node(values[i]);
                else
                    assert(current->right->data == values[i]);
                current = current->right;
            }
        }
    }

    int tree_max() {
        return get_max(this->root);
    }

    int tree_height() {
        return get_height(this->root) - 1;
    }

    void print_inorder() {
        print_inorder(root);
        cout << "\n";
    }
};

int main() {

    BinaryTree tree(1);
    tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
    tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
    tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
    tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

    tree.print_inorder();
    // 7 4 8 2 5 9 1 3 10 6

    cout << tree.tree_height() << endl;
    return 0;


}

/*
    printing expression tree in post-order
 */