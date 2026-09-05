#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int>maxsliding(std::vector<int>nums,int k){
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int maxsum = 0;
    std::vector<int>result;

    for(int right=0; right<k; right++){
        maxsum = std::max(maxsum,nums[right]);
    }
    result.push_back(maxsum);

    for(int right=k; right<n; right++){
        sum -=nums[left];
        sum+=nums[right];
        left++;
        maxsum=std::max(maxsum,nums[right]);
        result.push_back(maxsum);
    }
    return result;

}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int>nums;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        nums.push_back(ele);
    }
    int k; std::cout<<"Enter k: "; std::cin>>k;
    std::vector<int>ans=maxsliding(nums,k);
    for(int i=0; i<ans.size(); i++){
        std::cout<<ans[i]<<" ";
    }
    return 0;

}