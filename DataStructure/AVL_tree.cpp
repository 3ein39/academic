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
};