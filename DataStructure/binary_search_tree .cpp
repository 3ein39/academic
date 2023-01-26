#include <bits/stdc++.h>
using namespace std;

class BST {
private:
    int val;
    BST* left;
    BST* right;
    BST* parent;

public:
    BST(int val) : val(val), left(nullptr), right(nullptr), parent(nullptr) {};

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
            else {
                right = new BST(target);
                right->parent = this;
            }
        }
        else if (target < val) {
            if (left)
                left->insert(target);
            else {
                left = new BST(target);
                left->parent = this;
            }
        }
    }

    int min_value() {
        BST *node = this;

        while (node && node->left)
            node = node->left;

        return node->val;
    }

    // returns the chain of ancestors from node to target
    bool find_chain(vector<BST*>& ancestors, int target) {
        ancestors.push_back(this);

        if (target == val)
            return true;

        if (target < val)
            return left && left->find_chain(ancestors, target);

        return right && right->find_chain(ancestors, target);
    }

    // return max in a BST
    int get_max() {
        BST *node = this;

        while (node && node->right)
            node = node->right;

        return node->val;
    }
    // utility: extracts next parent from back
    BST* get_next(vector<BST*>& ancestors) {
        if (ancestors.size() == 0)
            return nullptr;

        BST* node = ancestors.back();
        ancestors.pop_back();

        return node;
    }

    // you should always call it with root
    pair<bool, int> get_successor(int target) {
        vector<BST*> ancestors;

        if (!find_chain(ancestors, target))
            return {false, -1};

        BST* child = get_next(ancestors);

        if (child->val == this->get_max())
            return {false, -1};

        if (child->right)
            return {true, child->right->min_value()};

        BST* parent = get_next(ancestors);

        while (parent && parent->right == child){
            child = parent;
            parent = get_next(ancestors);
        }

        if (parent)
            return {true, parent->val};

        return {false, -1};
    }

    BST* get_node(int target) {
        if (target == this->val)
            return this;

        if (target > this->val)
            return this->right->get_node(target);
        else if (target < this->val)
            return this->left->get_node(target);
    }

    pair<bool, int> get_successor2(int target) {
        BST* my_node = get_node(target);

        if (my_node->right)
            return {true, my_node->right->min_value()};

        BST* par = my_node->parent;

        while (parent->right == my_node) {
            my_node = parent;
            par = par->parent;
        }

        return {true, parent->val};
    }
};

int main() {
    BST root(50);
    root.insert(4);
    root.insert(3);
    root.insert(2);
    root.insert(1);
    root.insert(60);


    cout << root.get_successor(4).second << endl;
    return 0;

}