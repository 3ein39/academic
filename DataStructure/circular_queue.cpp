#include <iostream>
#include <cassert>
#include <map>
using namespace std;

class Queue {
    int size { };
    int front { 0 };
    int rear { 0 };
    int added_elements { };
    int *array { };

public:
    Queue() {}
    Queue(int size) :
            size(size) {
        array = new int[size];
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
        added_elements++;
    }

    void enqueue_front(int value) {
        assert(!isFull());
        front = previous(front);
        array[front] = value;
        added_elements++;
    }

    int dequeue_front() {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
        --added_elements;
        return value;
    }

    int dequeue_rear() {
        assert(!isEmpty());
        int value = array[rear];
        rear = previous(rear);
        --added_elements;
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

        for (int cur = front, step = 0; step < added_elements; ++step, cur = next(cur))
            cout << array[cur] << " ";
        cout << "\n\n";
    }

    void display_nums_only() {
        for (int cur = front, step = 0; step < added_elements; ++step, cur = next(cur))
            cout << array[cur] << " ";
    }

    int isEmpty() {
        return added_elements == 0;
    }

    bool isFull() {
        return added_elements == size;
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

    PriorityQueue tasks(8);

    tasks.enqueue(1131, 1);
    tasks.enqueue(3111, 3);
    tasks.enqueue(2211, 2);
    tasks.enqueue(3161, 3);

    tasks.display();

    cout << tasks.dequeue() << endl;
    cout << tasks.dequeue() << endl;

    tasks.enqueue(1535, 1);
    tasks.enqueue(2815, 2);
    tasks.enqueue(3845, 3);
    tasks.enqueue(3145, 3);

    tasks.display();

    while(!tasks.is_empty())
        cout << tasks.dequeue() << " ";

    return 0;
}
