#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data {};
    Node* next {}; // pointer to same object

    Node(int data) : data(data) {}

    ~Node() {
        cout << "Destroy value " << data << " at address " << this << "\n";
    }
};

class LinkedList {
private:
    Node* head {};
    Node* tail {};
    int length {};
public:
    // operations on them
    void print() {
        // convenient way of printing
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    // getting nth node 1-based
    Node* get_nth(int n) {
        int cnt {0};
        for (Node* cur = head; cur; cur = cur->next)
            if (++cnt == n) return cur;
        return nullptr;
    }

    // search for a value 0-based
    // try to improve it by shifting the searched val one step to the left
    int search(int val) {
        int idx = 0;
        Node* previous = nullptr;
        for(Node* cur = head; cur; cur = cur->next, idx++) {
            if (cur->data == val) {
                if (!previous)
                    return idx;
                swap(previous->data, cur->data);
                return idx - 1;
            }
            previous = cur;
        }
        return -1;
    }

    void insertEnd(int val) {
        Node* item = new Node(val);

        if (!head)
            head = tail = item;
        else {
            tail-> next = item;
            tail = item;
        }
        length++;
    }

    // calling it after doing any operation
    // to make sure that our list isn't corrupted
    void debug_verify_data_integrity() {
        if (length == 0)
            assert(head == nullptr && tail == nullptr);

        if (length)
            assert(head != nullptr && tail != nullptr);

        if (length == 1)
            assert(head == tail);

        assert(!tail->next);

        int cur_length = 0;
        for (Node* cur = head; cur; cur = cur->next, cur_length++)
            assert(cur_length < 10000); // handling infinite cycle

        assert(cur_length == length);
    }

    // converting the list to a single string for comparison
    string debug_to_string() {
        if (length == 0) return "";

        ostringstream oss;
        for(Node* cur = head; cur; cur = cur->next){
            oss << cur->data;
            if (cur->next) oss << " ";
        }
        return oss.str();
    }
};

int main() {


    return 0;
}