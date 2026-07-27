#include<iostream>
#include<vector>

using namespace std;

int max(vector<int> &nums){
    int n = nums.size();
    int first=0 , second = 0;
    for(int num:nums){
        if(num>first){
            second = first;
            first=num;
        }else if(num>second){
            second=num;
        }
    }
    return (first-1) * (second-1);
}
int main(){
    int n ; cout<<"Enter the size: "; cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; cout<<"Enter the elements: "; cin>>ele;
        nums.push_back(ele);
    }
    int result = max(nums);
    cout<<result<<" ";
}