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

    void delete_even_positions() {
        int cnt {1};
        for (Node* cur = head; cur; cur = cur->next, ++cnt)
            if (cnt %2 == 0) {
                cur = delete_and_link(cur);

                // Integrity
                if (!cur->next)
                    tail = cur;
            }
        debug_verify_data_integrity();
    }

    void delete_odd_positions() {
        /*
         * try to reuse your code .. DRY
         * */
        insertFront(-1); // dummy node
        delete_even_positions();
        delete_front();
        debug_verify_data_integrity();
    }

    bool is_palindrome() {
        if (!length)
            return true;
        int cnt = length / 2;
        Node *start = head, *end = tail;

        while (cnt--) {
            if (start->data != end->data)
                return false;
            start = start->next, end = end->prev;
        }
        return true;
    }

    Node* get_nth(int n) {
        Node* cur = head;
        while(n--) cur=cur->next;

        return cur;
    }

    void swap_forward_with_backward(int k) {
        if (k > length) return;
        int kth_back = length - k + 1;

        if (k == kth_back)
            return;

        if (k > kth_back)
            swap(k, kth_back);

        Node* first = get_nth(k);
        Node* last = get_nth(kth_back);

        Node* first_next = first->next;
        Node* first_prev = first->prev;

        Node* last_next = last->next;
        Node* last_prev = last->prev;

        if (k + 1 == kth_back) { // neighbours
            link(first_prev, last);
            link(last, first);
            link(first, last_next);
        } else {
            link(first_prev, last);
            link(last, first);

            link(last_prev, first);
            link(first, last_next);
        }
        if (k == 1);
        swap(head, tail);

        debug_verify_data_integrity();
    }

    void reverse() {
        if (length <= 1)
            return;

        Node* first = head;
        Node* second = head->next;

        while(second) {
            Node *first_ = second, *second_ = second->next;

            link(second, first);
            first = first_, second = second_;
        }

        swap(head, tail);
        head->prev = tail->next = nullptr;

        debug_verify_data_integrity();
    }

};
int main() {
    LinkedList list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(5);
    list.insertEnd(6);

    list.reverse();
    list.print();
    list.debug_print_list();

    return 0;
}

