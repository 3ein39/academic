#include <iostream>
#include <cassert>
using namespace std;

class Queue {
    int size { };
    int front { 0 };
    int rear { 0 };
    int added_elements { };
    int *array { };
    int ticketIdx {299};

public:
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

    void enqueue() {
        assert(!isFull());
        array[rear] = ++ticketIdx; // serializing tickets from 300
        rear = next(rear);
        added_elements++;
    }

    int dequeue() {
        assert(!isEmpty());
        int ticketID = array[front];
        front = next(front);
        --added_elements;
        ticketIdx--;
        return ticketID;
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

    int isEmpty() {
        return added_elements == 0;
    }

    bool isFull() {
        return added_elements == size;
    }

    int numberOfCustomers() {
        return added_elements;
    }
};

int main() {
    // creating a queue with max size of 6
    Queue CustomerQueue(6);
    assert(CustomerQueue.isEmpty());

    // trying to display empty queue
    CustomerQueue.display();
    // the display function is visualizing the whole queue process
    // Note: circular queue is used

    for (int i = 1; i <= 6; ++i) {
        assert(!CustomerQueue.isFull());
        CustomerQueue.enqueue();
        CustomerQueue.display();
    }
    assert(CustomerQueue.isFull());

    for (int i = 1; i <= 6; ++i) {
        assert(!CustomerQueue.isEmpty());
        CustomerQueue.dequeue();
        //qu.display();
    }

    for (int i = 1; i <= 6; ++i) {
        assert(!CustomerQueue.isFull());
        CustomerQueue.enqueue();
        CustomerQueue.display();
    }

    // trying to crash the system .. these codes are handled tightly ;)
    CustomerQueue.dequeue();
    assert(!CustomerQueue.isFull());
    CustomerQueue.enqueue();
    assert(CustomerQueue.isFull());
    CustomerQueue.display();

    CustomerQueue.dequeue();
    CustomerQueue.dequeue();
    assert(!CustomerQueue.isFull());
    CustomerQueue.enqueue();
    assert(!CustomerQueue.isFull());
    CustomerQueue.display();
    CustomerQueue.enqueue();
    assert(CustomerQueue.isFull());
    CustomerQueue.display();

    for (int i = 1; i <= 6; ++i) {
        assert(!CustomerQueue.isEmpty());
        CustomerQueue.dequeue();
        CustomerQueue.display();
    }

    return 0;
}
