#include<iostream>
#include <sstream>
#include<vector>

using namespace std;

int lengthofwords(vector<string> &words){
    int n =words.size();
    string ans = words[n-1];
    int m = ans.size();
    return m;
}


int main(){
    string s ; cout<<"Enter the word: "; getline(cin,s);
    cout<<s<<" ";
    
    vector<string> words;
    string word;
    stringstream ss(s);

    while (ss >> word) {
        words.push_back(word);
    }
    for (string w : words) {
        cout << w << endl;
    }
    int result = lengthofwords(words);
    cout<<result<<" ";
    
    
    
}