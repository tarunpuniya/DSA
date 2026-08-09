#include<iostream>
#include<vector>
#include<algorithm>

int ans(std::vector<int>nums){
    int n = nums.size();
    int k =0;
    for(int x:nums){
        if(x==1){
            k++;
        }
    }
    if(k==0) return -1;
    int left = 0;
    int ones = 0;
    int maxones = 0;

    for(int right=0; right<n; right++){
        if(nums[right]==1){
            ones++;
        }
        if(right-left+1>k){
            if(nums[left]==1){
                ones--;
            }
            left++;
        }
        maxones=std::max(maxones,ones);
    }
    return k-maxones;

}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int>nums;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        nums.push_back(ele);
    }
    int result = ans(nums);
    std::cout<<result<<" ";
    return 0;
}