#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Read front and back
    std::cout << "Front element: " << q.front() << "\n"; // Output: 10
    std::cout << "Back element: "  << q.back()  << "\n"; // Output: 30

    // Remove element (front)
    q.pop(); 

    std::cout << "New Front element: " << q.front() << "\n"; // Output: 20
    std::cout << "Queue size: " << q.size() << "\n";         // Output: 2

    return 0;
}