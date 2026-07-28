#include<iostream>
#include<string> 
#include<algorithm>

using namespace std;

string smallestpalindrome(string &s){
    int n = s.size();
    int mid = n/2;
    string half = s.substr(0,mid);
    string result = half;
    sort(result.begin(),result.end());

    string rev = result;
    reverse(rev.begin(),rev.end());

    if(n%2==1){
        result+=s[mid];
    }
    result+=rev;
    return result;
}
int main(){
    string s; cout<<"Enter the character: "; cin>>s;
    
    string result = smallestpalindrome(s);
    cout<<result<<" ";
}