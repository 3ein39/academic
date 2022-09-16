#include <iostream>
#include <cassert>
using namespace std;

class Queue {
    int size { };
    int front { 0 };
    int rear { 0 };
    int added_elements { };
    int *array { };

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

    int dequeue() {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
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

    int isEmpty() {
        return added_elements == 0;
    }

    bool isFull() {
        return added_elements == size;
    }
};

int main() {
    Queue q(10);

    q.enqueue_rear(1);
    q.enqueue_rear(2);
    q.enqueue_rear(3);
    q.enqueue_rear(4);
    q.enqueue_rear(5); // 1 2 3 4 5
                        // f       r
    q.dequeue(); // 2 3 4 5
    q.display();

    q.enqueue_front(9); // 9 2 3 4 5
    q.enqueue_front(10); // 9 2 3 4 5
    q.display();



    return 0;
}
