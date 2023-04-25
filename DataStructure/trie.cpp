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
};

int main() {

    return 0;
}