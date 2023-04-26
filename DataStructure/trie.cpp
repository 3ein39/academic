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

    bool word_exist(string str, int idx = 0) {
        if (idx == str.size())
            return isLeaf;  // there is a string marked here

        int cur = str[idx] - 'a';
        if (!child[cur])
            return false;   // such path doessn't exist
        return child[cur]->word_exist(str, idx + 1);
    }

    bool prefix_exist(string str, int idx = 0) {
        if (idx == str.size())
            return true;    // all subwords covered

        int cur = str[idx] - 'a';
    }
};

int main() {

    return 0;
}