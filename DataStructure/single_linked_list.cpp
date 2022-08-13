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
        delete node;
        length--;
    }
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
        debug_add_node(item);
    }

    void insertFront(int val) {
        Node* item = new Node(val);

        if (!head)
            head = tail = item;
        else {
            item->next = head;
            head = item;
        }
        length++;
        debug_add_node(item);
    }

    void deleteFront() {
        if (!head) return;
        Node* current = head-> next;
        debug_delete_node(head);
        head = current;
        if(!length) tail = head;
        debug_verify_data_integrity();
    }

    void deleteLastNode() {
        if (!tail)
            return;
        debug_delete_node(tail);
        tail = get_nth(length);
        if (!tail)
            head = tail;
        else
            tail-> next = nullptr;

        debug_verify_data_integrity();
    }

    Node* getNthBack(int n) {
        int idx = 0;
        for(Node* cur = head; cur; cur = cur->next)
            if(++idx + n == length + 1) return cur;
        return nullptr;
    }

    bool isSame1(const LinkedList& other) { // without length
        Node *h1 = head, *h2 = other.head;

        while (h1 && h2) {
            if (h1->data != h2->data)
                return false;
            h1 = h1->next, h2 = h2->next;
        }
        return !h1 && !h2; // checking if they end together or not
        // !null && !null => true;
    }

    bool isSame(const LinkedList& other){ // with length
        if (length != other.length)
            return false;

        Node* other_h = other.head;
        for (Node* cur_h = head; cur_h; cur_h = cur_h->next) {
            if (cur_h->data != other_h->data) return false;
            else other_h = other_h->next;
        }
        return true;
    }

    void deleteFirstNode() {
        assert(length);

        Node* cur = head;
        head = head->next;
        debug_delete_node(cur);

        if (length == 0) head = tail = nullptr;

        debug_verify_data_integrity();
    }

    void deleteNthNode(int n) {
        if(!(n <= length && n > 0)) return;

        if (n == length) {
            deleteLastNode();
            return;
        }

        if (n == 1) {
            deleteFirstNode();
            return;
        }

        Node* prev = get_nth(n - 1);
        Node* cur = prev->next;
        prev-> next = cur->next;
        debug_delete_node(cur);
        debug_verify_data_integrity();
    }

    void delete_node_with_key(int value) {
        int pos = 1;
        for (Node* cur = head; cur; cur = cur->next){
            if (value == cur->data) {
                deleteNthNode(pos);
                return;
            }
        }
    }

    void swap_pairs() {
        for (Node* cur = head; cur; cur = cur->next->next) {
            Node* next = cur->next;
            if (next)
                swap(next->data, cur->data);
            else break;
        }
    }

    void delete_next_node(Node* node) {
        Node* to_delete = node->next;
        bool is_tail = to_delete == tail;

        node->next = node->next->next;
        debug_delete_node(to_delete);

        if(tail)
            tail = node;
    }

    void delete_even_positions() {
        for(Node *cur = head->next, *prv = head; cur;) {
            delete_next_node(prv);
            if (!prv->next)
                break;
            cur = prv->next->next;
            prv = prv->next;
        }
    }

    void insert_sorted(int value) {
        if (length == 0) {
            insertEnd(value);
            return;
        } else if (length == 1) {
            if (head->data > value) insertFront(value);
            else insertEnd(value);
            return;
        }

        if (value >= tail->data) {
            insertEnd(value);
            return;
        }

        if (value <= head->data) {
            insertFront(value);
            return;
        }

        Node* item = new Node(value);
        for(Node *cur = head->next, *prv = head; cur;) {
            if (value >= prv->data && value <= cur->data) {
                prv->next = item;
                item->next = cur;
                length++;
                debug_add_node(item);
                break;
            }
            else {
                cur = cur->next;
                prv = prv->next;
            }
        }
    }

    void swap_head_tail() {
        Node* prv = head;
        Node* cur = head->next;
        while (cur->next) cur = cur->next, prv = prv->next;

        prv->next = head;
        tail->next = head->next;
        head->next = nullptr;

        swap(head, tail);
    }

    void rotate_left(int k) {
        k = k % length;
        while (k--) {
            tail-> next = head;
            Node* new_head = head-> next;
            head-> next = nullptr;
            tail = head;
            head = new_head;
        }
    }

    void delete_duplicates() {
        vector<int> list;
        list.push_back(head->data);
        for(Node *cur = head->next, *prv = head; cur;) {
            if (find(list.begin(),list.end(), cur->data) != list.end()) {
                delete_next_node(prv);
                cur = prv->next;
            }
            else {
                list.push_back(cur->data);
                cur = cur->next;
                prv = prv->next;
            }
        }
    }

    void debug_verify_data_integrity() {
        // calling it after doing any operation
        // to make sure that our list isn't corrupted
        if (length == 0)
            assert(head == nullptr && tail == nullptr);

        if (length) {
            assert(head != nullptr && tail != nullptr);
            assert(!tail->next);
        }

        if (length == 1)
            assert(head == tail);


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

    ~LinkedList() {
        while(head) {
            Node* current = head-> next;
            delete head;
            head = current;
        }
    }
};

int main() {

    LinkedList list;
    list.insertEnd(1);
    list.insertEnd(1);
    list.insertEnd(1);

    list.delete_duplicates();
    list.print();
    list.debug_print_list();
    list.debug_verify_data_integrity();

// must see it, otherwise RTE
    cout << "\n\nNO RTE\n";

    return 0;
}