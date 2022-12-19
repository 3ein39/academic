#include <bits/stdc++.h>
using namespace std;

class BST {
private:
    int val;
    BST* left;
    BST* right;

public:
    BST(int val) : val(val), left(nullptr), right(nullptr) {};
};

int main() {
    BST root(1);
    return 0;
}