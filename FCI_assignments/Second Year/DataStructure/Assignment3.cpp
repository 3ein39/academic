#include <iostream>
#include <cassert>
#include<bits/stdc++.h>
using namespace std;

typedef char type;

class Stack {
private:
    struct Node {
        type data { };
        Node* next { };
        Node(type data) :
                data(data) {
        }
    };

    Node *head { };

public:
    ~Stack() {
        while (!isEmpty())
            pop();
    }
    void display() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    string toString() {
        string str;
        for (Node* cur = head; cur; cur = cur->next)
            str.push_back(cur->data);

        return str;
    }

    void push(type value) {
        Node* item = new Node(value);
        item->next = head;
        head = item;
    }

    type pop() {
        assert(!isEmpty());
        type element = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return element;
    }

    type peek() {
        assert(!isEmpty());
        type element = head->data;
        return element;
    }

    int isEmpty() {
        return !head;
    }


    string removeDublicates(string str) {
        for (auto& chr : str) {
            if (this->isEmpty() || chr != this->peek())
                this->push(chr);
            else
                this->pop();
        }

        string ret;
        ret = this->toString();
        reverse(ret.begin(), ret.end());
        return ret;
    }

};

int main() {
    Stack lls;
    string str = "abbaca";
    string ans = lls.removeDublicates(str);
    cout << ans;
}

