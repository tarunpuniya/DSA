#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxproduct(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int ans1 = nums[n-1]*nums[n-2]*nums[n-3];
    int ans2 = nums[0]*nums[1]*nums[n-1];
    return max(ans1,ans2);
}
int main(){
    int n; cout<<"Enter the size: "; cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; cin>>ele;
        nums.push_back(ele);
    }
    int result = maxproduct(nums);
    cout<<result<<" ";   

    return 0;
}
