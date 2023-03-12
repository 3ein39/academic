#include <bits/stdc++.h>
using namespace std;

class AVLtree {
private:
    int data{};
    int height {};
    AVLtree* left{};
    AVLtree* right{};

    int child_height(AVLtree* node) {
        if (!node)
            return -1;
        return node->height;
    }

    void update_height() {
        height = 1 + max(child_height(left), child_height(right));
    }

    int balance_factor() {
        return child_height(left) - child_height(right);
    }

    AVLtree* right_rotation(AVLtree* Q) {
        AVLtree* P = Q->left;
        Q->left = P->right;
        P->right = Q;

        Q->update_height();
        P->update_height();

        return P;
    }

    AVLtree* left_rotation(AVLtree* P) {
        AVLtree * Q = P->right;
        P->right = Q->left;
        Q->left = P;

        P->update_height();
        Q->update_height();

        return Q;
    }

public:
    // handling the 4 imbalance cases in one function
    AVLtree* balance(AVLtree* node) {
        if (node->balance_factor() == 2) {
            if (node->left->balance_factor() == -1)
                node->left = left_rotation(node->left);

            node = right_rotation(node);
        }
        else if (node->balance_factor() == -2) {
            if (node->right->balance_factor() == 1)
                node->right = right_rotation(node->right);

            node = left_rotation(node);
        }

        return node;
    }

};