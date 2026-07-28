#include<iostream>
#include<vector>

using namespace std;

int singlenumber(vector<int> &nums){
    int ans = 0;
    for(int x:nums){
        ans^=x;
    }
    return ans;
}
int main(){
    int n; cout<<"Enter the size: "; cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; cout<<"Enter the elements: "; cin>>ele;
        nums.push_back(ele);
    }
    int answer = singlenumber(nums);
    cout<<answer<<" ";

}

