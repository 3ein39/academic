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
};

int main() {
    BST root(1);
    return 0;
}