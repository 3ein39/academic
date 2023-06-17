#include <bits/stdc++.h>
using namespace std;

    class trie {
private:
    static const int MAX_CHAR = 26;
    trie* child[MAX_CHAR]; // each array index represent an edge.
    bool isLeaf {};
public:
    trie() {
        // set the pointers to null
        ::memset(child, 0, sizeof(child));
    }

    void insert(string str, int idx = 0) {
        if (idx == str.size())
            isLeaf = true;
        else {
            int cur = str[idx] - 'a';
            if (child[cur] == 0)
                child[cur] = new trie();
            child[cur]->insert(str, idx + 1);
        }
    }

    // insertion in iterative way
    void insert_iterative(string str) {
        trie* node = this;
        for (int idx = 0; idx < str.size(); ++idx) {
            int cur = str[idx] - 'a';
            if (node->child[cur] == 0)
                node->child[cur] = new trie();
            node = node->child[cur];
        }
        node->isLeaf = true;
    }

    bool word_exist(string str, int idx = 0) {
        if (idx == str.size())
            return isLeaf;  // there is a string marked here

        int cur = str[idx] - 'a';
        if (!child[cur])
            return false;   // such path doessn't exist
        return child[cur]->word_exist(str, idx + 1);
    }


    bool word_exist_iterative(string str) {
        trie* node = this;

        for (int i = 0; i < str.size(); ++i) {
            int cur = str[i] - 'a';

            if (!node->child[cur])
                return false;

            node = node->child[cur];
        }

        return node->isLeaf;
    }

    bool prefix_exist(string str, int idx = 0) {
        if (idx == str.size())
            return true;    // all subwords covered

        int cur = str[idx] - 'a';
        if (!child[cur])
            return false; // this path do not exist

        return child[cur]->prefix_exist(str, idx + 1);
    }
};

int main() {
trie root;

	root.insert_iterative("abcd");
	root.insert_iterative("xyz");
	root.insert_iterative("abf");
	root.insert_iterative("xn");
	root.insert_iterative("ab");
	root.insert_iterative("bcd");

	cout << root.word_exist_iterative("xyz") << "\n";
	cout << root.word_exist_iterative("xy") << "\n";
	cout << root.prefix_exist("xy") << "\n";
    return 0;
}