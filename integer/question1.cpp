#include<iostream>
using namespace std;

int product(int num){
    int product=1;
    while(num){
        product*=num%10;
        num/=10;
    }
    return product;
}

int smallest(int n , int t){
    while(product(n)%t!=0){
        n++;
    }
    return n;
}


int main(){
    int n; cout<<"Enter the no. "; cin>>n; 
    int t; cout<<"Enter the value. "; cin>>t;

    int result = smallest(n,t);
    cout<<result<<" ";

    return 0;
}