#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int longestConsecutive(vector<int> &nums){
    if(nums.empty()) return 0;
    int n = nums.size();
    int count = 1;
    int ans = 1;
    sort(nums.begin(),nums.end());
    for(int i=1; i<n; i++){
        if(nums[i]==nums[i-1]) continue;
        if(nums[i]==nums[i-1]+1) count++;
        else count=1;

        ans = max(ans,count);
        
    }
    return ans;

}
int main(){
    int n; cout<<"Enter the size: "; cin>>n;
    vector<int> nums;
    for(int i=0; i<n;  i++){
        int ele; cout<<"Enter the elements: "; cin>>ele;
        nums.push_back(ele);
    }
    int result = longestConsecutive(nums);
    cout<<result<<" ";
}