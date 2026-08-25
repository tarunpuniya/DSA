#include<bits/stdc++.h>

void reverse(std::stack<int> &st){
    std::stack<int> temp1,temp2;
    while(!st.empty()){
        int current = st.top();
        st.pop();
        temp1.push(current);
    }
    while(!temp1.empty()){
        int curr = temp1.top();
        temp1.pop();
        temp2.push(curr);
    }
    while(!temp2.empty()){
        int cur = temp2.top();
        temp2.pop();
        st.push(cur);
    }
    
}

int main(){
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverse(s);
    while(!s.empty()){
        int x = s.top();
        s.pop();
        std::cout<<x<<" ";
    }
}