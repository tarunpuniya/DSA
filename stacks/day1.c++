#include<iostream>
#include<stack>

int main(){
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout<<"Top element: "<<s.top()<<std::endl;

    s.pop();
    std::cout<<"Top element after pop: "<<s.top()<<std::endl;

    std::cout<<"Size: "<<s.size()<<std::endl;
    if(s.empty()){
        std::cout<<"Stack is empty: ";
    }else{
        std::cout<<"Stack is not empty: ";
    }
}

