#include <iostream>
#include<vector>

using namespace std;

int peakelement(vector<int> &nums){
    int n = nums.size();
    int low=0;
    int high = n-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if(nums[mid]<nums[mid+1]){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return low;
}

int main(){
    int n; cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; cin>>ele;
        nums.push_back(ele);
    }
    int result = peakelement(nums);
    cout<<result;
}