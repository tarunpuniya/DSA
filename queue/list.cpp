// Implementation of a queue using linked list 

#include<iostream>

class node{
    public:
    int value;
    node*next;

    node(int data){
        value=data;
        next=nullptr;
    }
};
class queue{
    private:
    node*head;
    node*tail;
    int size;
public:
    queue(){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

// Insert element at the tail with O(1) time complexity
    void enqueue(int val){
    node*newnode = new node(val);
    if(this->head==nullptr){
        this->head=this->tail=newnode;
    }else{
        this->tail->next = newnode;
        this->tail=newnode;
    }
    this->size++;
}

// Remove element from the front with O(1) time complexity

    void dequeue(){
        if(this->head==nullptr){
            std::cout<<"Queue in underflow condition";
            return;
        }
        node*oldhead = this->head;
        node*newhead = this->head->next;
        this->head = newhead;
        if(this->head==nullptr) this->tail==nullptr;
        oldhead->next = nullptr;
        delete oldhead;
        this->size--;
    }

    bool isempty(){
        return this->head==nullptr;
    }
    int getsize(){
        return this->size;
    }
    int front(){
        if(this->head==nullptr) return -1;
        return this->head->value;
    }
};

int main(){
    queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);

    std::cout<<"Front element: "<<qu.front()<<"\n";
    std::cout<<"Queue size: "<<qu.getsize()<<"\n";

    qu.dequeue();

    std::cout << "New Front after 1 dequeue: " << qu.front() << "\n";


}

