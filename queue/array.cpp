// Implementation of the Queue using array

#include<bits/stdc++.h>

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count; // Tracks current number of elements

public:
    Queue(int cap) : capacity(cap), front(0), rear(-1), count(0) {
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    // Insert element at the rear - O(1)
    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Queue Overflow! Cannot enqueue " << val << "\n";
            return;
        }
        // Circular advancement of rear index
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }

    // Remove element from the front - O(1)
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! Queue is empty.\n";
            return;
        }
        // Circular advancement of front index
        front = (front + 1) % capacity;
        count--;
    }

    // Access front element - O(1)
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty.");
        }
        return arr[front];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    int size() const {
        return count;
    }
};

int main() {
    Queue q(3); // Capacity of 3

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40); // Output: Queue Overflow!

    std::cout << "Front element: " << q.peek() << "\n"; // Output: 10

    q.dequeue(); // Removes 10, frees index 0
    q.enqueue(40); // Circularly wraps around to index 0!

    std::cout << "New Front: " << q.peek() << "\n";      // Output: 20
    std::cout << "Current Size: " << q.size() << "\n";  // Output: 3

    return 0;
}
