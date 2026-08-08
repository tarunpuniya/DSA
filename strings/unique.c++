#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int firstunique(string s){
    int n = s.size();
    unordered_map<char,int> freq;
    for(char c:s) freq[c]++;
    for(int i=0; i<n; i++) if(freq[s[i]]==1) return i;
    return -1;
}

int main(){
    string s; cout<<"Enter the string: "; cin>>s;
    int result = firstunique(s);
    cout<<result<<" ";
}