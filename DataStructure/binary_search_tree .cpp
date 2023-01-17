#include <bits/stdc++.h>
using namespace std;

class BST {
private:
    int val;
    BST* left;
    BST* right;

public:
    BST(int val) : val(val), left(nullptr), right(nullptr) {};

    bool search(int target) {
        if (target == val)
            return true;

        if (target < val)
            return left && left->search(target);

        return right && right->search(target);
    }

    void insert(int target) {
        if (target > val) {
            if (right)
                right->insert(target);
            else
                right = new BST(target);
        }
        else if (target < val) {
            if (left)
                left->insert(target);
            else
                left = new BST(target);
        }
    }

    int min_value() {
        BST *node = this;

        while (node && node->left)
            node = node->left;

        return node->val;
    }
};

int main() {
    BST root(1);
    root.insert(2);
    root.insert(3);
    root.insert(4);

    cout << root.min_value() << endl;
    return 0;
}