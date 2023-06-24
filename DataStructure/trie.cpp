#include <bits/stdc++.h>
using namespace std;

    class trie {
private:
    static const int MAX_CHAR = 26;
//    trie* child[MAX_CHAR]; // each array index represent an edge.
    // more memory effiecent implementation, but accessing becomes O(log n) due to AVL tree
    map<int, trie*> child;
    // we can use un orderd map for O(1), i.e. it uses hashing
    bool isLeaf {};
public:
    trie() {
    }

    void insert(string str, int idx = 0) {
        if (idx == str.size())
            isLeaf = true;
        else {
            int cur = str[idx] - 'a';
            if (!child.count(cur))
                child[cur] = new trie();
            child[cur]->insert(str, idx + 1);
        }
    }

    // insertion in iterative way
    void insert_iterative(string str) {
        trie* node = this;
        for (int idx = 0; idx < str.size(); ++idx) {
            int cur = str[idx] - 'a';
            if (!node->child.count(cur))
                node->child[cur] = new trie();
            node = node->child[cur];
        }
        node->isLeaf = true;
    }

    bool word_exist(string str, int idx = 0) {
        if (idx == str.size())
            return isLeaf;  // there is a string marked here

        int cur = str[idx] - 'a';
        if (!child.count(cur))
            return false;   // such path doessn't exist
        return child[cur]->word_exist(str, idx + 1);
    }


    bool word_exist_iterative(string str) {
        trie* node = this;

        for (int i = 0; i < str.size(); ++i) {
            int cur = str[i] - 'a';

            if (!node->child.count(cur))
                return false;

            node = node->child[cur];
        }

        return node->isLeaf;
    }

    bool prefix_exist(string str, int idx = 0) {
        if (idx == str.size())
            return true;    // all subwords covered

        int cur = str[idx] - 'a';
        if (!child.count(cur))
            return false; // this path do not exist

        return child[cur]->prefix_exist(str, idx + 1);
    }

    string first_word_prefix(const string& str) {
        trie* node = this;

        for (int i = 0; i < str.size(); ++i) {
            int cur = str[i] - 'a';

            if(node->isLeaf)
                return str.substr(0, i);
            if (!node->child.count(cur))
                break;

            node = node->child[cur];
        }

        return str;
    }
};

int main() {
trie root;

	root.insert_iterative("xyz");
	root.insert_iterative("xyzea");
	root.insert_iterative("bc");
	root.insert_iterative("a");

    cout << root.first_word_prefix("xyzabc") << endl;
    return 0;
}