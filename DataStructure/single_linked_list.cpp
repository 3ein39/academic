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

    vector<Node*> debug_data; // add/remove nodes you use
public:
    LinkedList() {}

    // preventing copy && assignment constructors
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList& another) = delete;

    void print() {
        // convenient way of printing
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    Node* get_nth(int n) {
        // getting nth node 1-based
        int cnt {0};
        for (Node* cur = head; cur; cur = cur->next)
            if (++cnt == n) return cur;
        return nullptr;
    }

    int search(int val) {
        // search for a value 0-based
        // try to improve it by shifting the searched val one step to the left
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

    void debug_verify_data_integrity() {
        // calling it after doing any operation
        // to make sure that our list isn't corrupted
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

    string debug_to_string() {
        // converting the list to a single string for comparison

        if (length == 0) return "";

        ostringstream oss;
        for(Node* cur = head; cur; cur = cur->next){
            oss << cur->data;
            if (cur->next) oss << " ";
        }
        return oss.str();
    }


    void debug_add_node(Node* node){
        // vector<Nodes*> will allow us to print the list content
        // even if it is not linked
        debug_data.push_back(node);
    }

    void debug_delete_node(Node* node){
        auto it = find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }

    void debug_print_node(Node* node, bool is_separate = false) {
        // printing one node info
        // called by another debug function
        if (is_separate)
            cout << "Sep: ";
        if (node == nullptr){
            cout << "nullptr\n";
            return;
        }
        cout << node->data << " ";
        if (node->next == nullptr)
            cout << "X ";
        else
            cout << node->next->data << " ";

        if (node == head)
            cout << "head\n";
        else if (node == tail)
            cout << "tail\n";
        else
            cout << "\n";
    }

    void debug_print_list(string msg = "") {
        if (msg != "")
            cout << msg << "\n";
        for (int i = 0; i < (int) debug_data.size(); ++i)
            debug_print_node(debug_data[i]);
        cout << "****************\n" << flush;
    }
};

int main() {


    return 0;
}