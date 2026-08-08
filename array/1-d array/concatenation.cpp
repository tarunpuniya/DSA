#include<iostream>
#include<vector>

using namespace std;

vector<int> concatenation(vector<int> &nums){
    int n = nums.size();
    vector<int> ans = nums;
    for(int x:nums) ans.push_back(x);
    return ans;
}
int main(){
    int n; cout<<"Enter the size of the array: "; cin>>n;
    vector<int> num;
    for(int i=0; i<n; i++){
        int ele; cout<<"Enter the element: "; cin>>ele;
        num.push_back(ele);
    }

    vector<int> result = concatenation(num);
    for(int i:result) cout<<i<<" ";
    return 0;

}