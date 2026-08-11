#include<iostream>
#include<vector>

std::vector<int>distinct(std::vector<int> &nums){
    int n = nums.size();
    int write = 0;
    for(int i=0; i<n; i++){
        if(nums[i-1]!=nums[i]){
            nums[write++]=nums[i];
        }
    }
    return nums;
}

int main(){
    int n; std::cin>>n;
    std::vector<int>nums;
    for(int i=0; i<n; i++){
        int ele; std::cin>>ele;
        nums.push_back(ele);
    }

    std::vector<int>result=distinct(nums);
    for(int x:result){
        std::cout<<x<<" ";
    }
    return 0;
}