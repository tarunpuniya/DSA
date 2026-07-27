#include<iostream>
#include<vector> 


using namespace std;

vector<bool> Kidswithextracandy(vector<int> &candies){
    int n = candies.size();
    int max_val = candies[0];
    for(int i=0; i<n; i++){
        if(candies[i]>max_val){
            max_val=candies[i];
        }
    }

    vector<bool> ans;
    int extracandy; cout<<"Extra: "; cin>>extracandy;
    for(int i=0; i<n; i++){
        if(candies[i]+extracandy>=max_val){
            ans.push_back(true);
        }else{
            ans.push_back(false);
        }
    }
    return ans;
}


int main(){
    int n; cout<<"Enter the size: "; cin>>n;
    vector<int> candies;
    for(int i=0; i<n; i++){
        int ele; cout<<"Enter the candies: "; cin>>ele;
        candies.push_back(ele);
    }
    vector<bool> result = Kidswithextracandy(candies);
    for(int j=0; j<result.size(); j++){
        cout<<boolalpha<<result[j]<<" ";
    }cout<<endl;

    return 0;
}