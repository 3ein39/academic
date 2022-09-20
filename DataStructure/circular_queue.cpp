#include <iostream>
#include <cassert>
#include <map>
using namespace std;

class Queue {
    int size { };
    int front { 0 };
    int rear { 0 };
    int *array { };

public:
    Queue() {}
    Queue(int size) :
            size(size + 1) {
        array = new int[size + 1];
    }

    ~Queue() {
        delete[] array;
    }

    int next(int pos) {
        ++pos;
        if (pos == size)
            pos = 0;
        return pos;
        //return (pos + 1) % size;	//  Or shorter way
    }

    int previous(int pos) {
        --pos;
        if (pos == -1)
            pos = size - 1;
        return pos;
    }

    void enqueue_rear(int value) {
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
    }

    void enqueue_front(int value) {
        assert(!isFull());
        front = previous(front);
        array[front] = value;
    }

    int dequeue_front() {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
        return value;
    }

    int dequeue_rear() {
        assert(!isEmpty());
        int value = array[rear];
        rear = previous(rear);
        return value;
    }

    void display() {
        cout << "Front " << front << " - rear " << rear << "\t";
        if (isFull())
            cout << "full";
        else if (isEmpty()) {
            cout << "empty\n\n";
            return;
        }
        cout << "\n";

        for (int cur = front, step = 0; cur != rear; ++step, cur = next(cur))
            cout << array[cur] << " ";
        cout << "\n\n";
    }

    void display_nums_only() {
        for (int cur = front, step = 0; cur != rear; ++step, cur = next(cur))
            cout << array[cur] << " ";
    }

    int isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return next(rear) == front;
    }
};

class PriorityQueue {
    int size {};
    map<int, Queue*> priority_to_queue_map;
    int added_elements {};
public:
    PriorityQueue(int size) : size(size), added_elements(0) {
        for(int p = 1; p <= 3; ++p){
            Queue* q = new Queue(size);
            priority_to_queue_map[p] = q;
        }
    }

    void enqueue(int value, int priority) {
        assert(added_elements < size);
        priority_to_queue_map[priority]->enqueue_rear(value);
        added_elements++;
    }

    void display() {
        for(int p = 3; p > 0; --p) {
            if (priority_to_queue_map.count(p)) {
                cout << "Priority #" << p << " tasks: ";
                priority_to_queue_map[p]->display_nums_only();
                cout << "\n";
            }
        }
    }

    int dequeue() {
        for(int p = 3; p > 0; --p) {
            if (priority_to_queue_map.count(p) && !priority_to_queue_map[p]->isEmpty()) {
                int val = priority_to_queue_map[p]->dequeue_front();
                --added_elements;
                return val;
            }
        }
    }

    bool is_empty() {
        return added_elements == 0;
    }

};

int main() {

    Queue qu(6);
    assert(qu.isEmpty());
    qu.display();

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isFull());
        qu.enqueue_rear(i);
        qu.display();
    }
    assert(qu.isFull());

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isEmpty());
        qu.dequeue_front();
        //qu.display();
    }

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isFull());
        qu.enqueue_rear(i);
        qu.display();
    }

    qu.dequeue_front();
    assert(!qu.isFull());
    qu.enqueue_rear(7);
    assert(qu.isFull());
    qu.display();

    qu.dequeue_front();
    qu.dequeue_front();
    assert(!qu.isFull());
    qu.enqueue_rear(8);
    assert(!qu.isFull());
    qu.display();
    qu.enqueue_rear(9);
    assert(qu.isFull());
    qu.display();

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isEmpty());
        qu.dequeue_front();
        qu.display();
    }

    return 0;
}
