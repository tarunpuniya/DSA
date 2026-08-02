#include<iostream>
#include<string>

using namespace std;

int validprefixces(string &s){
    int zero=0;
    int one=0;
    int count=0;

    for(char ch:s){
        if(ch=='0'){
            zero++;
        }
        else{
            one++;
        }
        if(abs(zero-one)<=1){
            count++;
        }
    }
    return count;
}

int main(){
    string s; cout<<"Enter binar no."; cin>>s;
    int result = validprefixces(s);
    cout<<result<<" ";
}
