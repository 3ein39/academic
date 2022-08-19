#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
    int data { };
    Node* next { };
    Node* prev { };	 // Previous node!

    Node(int data) : data(data) {}

    void set(Node* next, Node* prev) {
        this->next = next;
        this->prev = prev;
    }

    ~Node() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class LinkedList {
private:
    Node *head { };
    Node *tail { };
    int length = 0;

    // let's maintain how many nodes

    vector<Node*> debug_data;	// add/remove nodes you use

    void debug_add_node(Node* node) {
        debug_data.push_back(node);
    }
    void debug_remove_node(Node* node) {
        auto it = std::find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }

public:

    // Below 2 deletes prevent copy and assign to avoid this mistake
    LinkedList() {
    }
    LinkedList(const LinkedList&) = delete;
    LinkedList &operator=(const LinkedList &another) = delete;

    void debug_print_address() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur << "," << cur->data << "\t";
        cout << "\n";
    }

    void debug_print_node(Node* node, bool is_seperate = false) {
        if (is_seperate)
            cout << "Sep: ";
        if (node == nullptr) {
            cout << "nullptr\n";
            return;
        }

        if (node->prev == nullptr)
            cout << "X\t";
        else
            cout << node->prev->data << "\t";

        cout << " <= [" <<node->data << "]\t => \t";

        if (node->next == nullptr)
            cout << "X\t";
        else
            cout << node->next->data << "\t";

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
        cout << "************\n" << flush;
    }

    string debug_to_string() {
        if (length == 0)
            return "";
        ostringstream oss;
        for (Node* cur = head; cur; cur = cur->next) {
            oss << cur->data;
            if (cur->next)
                oss << " ";
        }
        return oss.str();
    }

    void debug_verify_data_integrity() {
        if (length == 0) {
            assert(head == nullptr);
            assert(tail == nullptr);
        } else {
            assert(head != nullptr);
            assert(tail != nullptr);
            if (length == 1)
                assert(head == tail);
            else
                assert(head != tail);
            assert(!head->prev);
            assert(!tail->next);
        }
        int len = 0;
        for (Node* cur = head; cur; cur = cur->next, len++) {
            if (len == length-1)	// make sure we end at tail
                assert(cur == tail);
        }

        assert(length == len);
        assert(length == (int )debug_data.size());

        len = 0;
        for (Node* cur = tail; cur; cur = cur->prev, len++) {
            if (len == length-1)	// make sure we end at head
                assert(cur == head);
        }
        cout << "\n";
    }
    ////////////////////////////////////////////////////////////

    void print() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    // These 2 simple functions just to not forget changing the vector and length
    void delete_node(Node* node) {
        debug_remove_node(node);
        --length;
        delete node;
    }

    void add_node(Node* node) {
        debug_add_node(node);
        ++length;
    }

    void print_reversed()  {
        for (Node* cur = tail; cur; cur = cur->prev)
            cout << cur->data << " ";
        cout << "\n";
    }

    void link(Node* first, Node* second) {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }

    void insertEnd(int value) {
        Node* item = new Node(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else {
            link(tail, item);
            tail = item;
        }
        debug_verify_data_integrity();
    }

    void insertFront(int value) {
        Node* item = new Node(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else {
            link(item, head);
            head = item;
        }

        debug_verify_data_integrity();
    }

    void insertSorted(int value) {
        if (!head || value <= head->data)
            insertFront(value);
        else if (tail->data <= value)
            insertEnd(value);
        else {
            // Find the node i am less than
            for (Node* cur = head; cur; cur = cur->next) {
                if (value <= cur->data) {
                    embed_after(cur->prev, value);
                    break;
                }
            }
        }
        debug_verify_data_integrity();
    }

    void embed_after(Node* node_before, int value) {
        Node* middle = new Node(value);
        ++length;
        debug_add_node(middle);

        Node* node_after = node_before->next;
        link(node_before, middle);
        link(middle, node_after);
    }

    void delete_front() {
        if (!head)
            return;

        Node* cur = head->next;
        delete_node(head);
        head = cur;

        // Integrity things
        if (head)
            head->prev = nullptr;
        else if (!length)
            tail = nullptr;

        debug_verify_data_integrity();
    }

    void delete_end() {
        if (!head)
            return;

        Node* cur = tail->prev;
        delete_node(tail);
        tail = cur;

        // Integrity
        if (tail)
            tail->next = nullptr;
        else if (!length)
            head = nullptr;

        debug_verify_data_integrity();
    }

    Node* delete_and_link(Node* cur) {
        // useful utility returns the node before the deleted one
        Node* ret = cur->prev;
        link(cur->prev, cur->next);
        delete_node(cur);

        return ret;
    }

    void delete_node_with_key(int value) {
        if (!length)
            return;
        if (head->data == value)
            delete_front();
        else {
            for (Node* cur = head; cur; cur = cur->next) {
                if (cur->data == value) {
                    cur = delete_and_link(cur);
                    if (!cur->next) // if we removed last node
                        tail = cur;
                    break;
                }
            }
        }
        debug_verify_data_integrity();
    }
    void delete_all_nodes_with_key(int value) {
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->data == value) {
                cur = delete_and_link(cur);

                // Integrity
                if (!cur->next)
                    tail = cur;
            }
        }

        debug_verify_data_integrity();
    }

};
int main() {
    LinkedList list;
    list.insertSorted(1);
    list.insertSorted(2);
    list.insertSorted(5);
    list.insertSorted(4);
    list.insertSorted(5);
    list.insertSorted(4);
    list.insertSorted(4);

    list.delete_all_nodes_with_key(5);
    list.print();
    list.debug_print_list();

    return 0;
}

