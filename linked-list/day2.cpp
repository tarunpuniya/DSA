// ✅ Reverse Linked List (master karo)
// Middle of Linked List (Fast & Slow pointers)
// Detect Cycle (Floyd's Algorithm)
// Merge Two Sorted Lists
// Remove Nth Node From End
// Reverse Linked List II
// Copy List with Random Pointer
// LRU Cache (Linked List + HashMap)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Display function
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Reverse function
Node* reverse(Node* head) {

    Node* previous = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {

        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

int main() {

    // Manually creating linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    display(head);

    head = reverse(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}