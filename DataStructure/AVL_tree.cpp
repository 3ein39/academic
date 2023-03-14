#include <iostream>
#include <cassert>
#include <queue>
using namespace std;


class AVLTree {
private:
    struct BinaryNode {
        int data { };
        int height { };
        BinaryNode* left { };
        BinaryNode* right { };

        BinaryNode(int data) :
                data(data) {
        }

        int ch_height(BinaryNode* node) {	// child height
            if (!node)
                return -1;			// -1 for null
            return node->height;	// 0 for leaf
        }
        int update_height() {	// call in end of insert function
            return height = 1 + max(ch_height(left), ch_height(right));
        }
        int balance_factor() {
            return ch_height(left) - ch_height(right);
        }
    };

    BinaryNode *root { };

    ///////////////////////////
    bool search(int target, BinaryNode* node) {
        if(!node)
            return false;

        if (target == node->data)
            return true;

        if (target < node->data)
            return search(target, node->left);

        return search(target, node->right);
    }

    BinaryNode* right_rotation(BinaryNode* Q) {
        cout << "right_rotation " << Q->data << "\n";
        BinaryNode* P = Q->left;
        Q->left = P->right;
        P->right = Q;
        Q->update_height();
        P->update_height();
        return P;
    }

    BinaryNode* left_rotation(BinaryNode* P) {
        cout << "left_rotation " << P->data << "\n";
        BinaryNode* Q = P->right;
        P->right = Q->left;
        Q->left = P;
        P->update_height();
        Q->update_height();
        return Q;
    }

    BinaryNode* balance(BinaryNode* node) {
        if (node->balance_factor() == 2) { 			// Left
            if (node->left->balance_factor() == -1)	// Left Right?
                node->left = left_rotation(node->left);	// To Left Left

            node = right_rotation(node);	// Balance Left Left
        } else if (node->balance_factor() == -2) {
            if (node->right->balance_factor() == 1)
                node->right = right_rotation(node->right);

            node = left_rotation(node);
        }
        return node;
    }

    BinaryNode* insert_node(int target, BinaryNode* node) {
        if (target < node->data) {
            if (!node->left)
                node->left = new BinaryNode(target);
            else	// change left. update left as it might be balanced
                node->left = insert_node(target, node->left);
        } else if (target > node->data) {
            if (!node->right)
                node->right = new BinaryNode(target);
            else
                node->right = insert_node(target, node->right);
        }
        node->update_height();
        return balance(node);
    }

    BinaryNode* min_node(BinaryNode* cur) {
        while (cur && cur->left)
            cur = cur->left;
        return cur;
    }


public:
    void insert_value(int target) {
        if (!root)
            root = new BinaryNode(target);
        else
            root = insert_node(target, root);

        verify();
    }
    bool search(int target) {
        return search(target, root);
    }
};

