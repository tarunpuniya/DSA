#include<bits/stdc++.h>

int result(std::vector<int>nums,int k){
    int n = nums.size();
    int left = 0;
    double maxsum = 0;
    double sum = 0;

    std::unordered_map<int,int>frequency;
    for(int right=0; right<k; right++){
        sum+=nums[right];
        frequency[nums[right]]++;
    }
    if(frequency.size()==k) maxsum=sum;
    for(int right=k; right<n; right++){
        sum+=nums[right];
        frequency[nums[right]]++;

        sum-=nums[left];
        frequency[nums[left]]--;

        if(frequency[nums[left]]==0){
            frequency.erase(nums[left]);
        }
        left++;

        if(frequency.size()==k) maxsum=std::max(maxsum,sum);
    }
    return maxsum;

}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int>nums;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        nums.push_back(ele);
    }
    int k; std::cout<<"Enter k: "; std::cin>>k;
    int ans = result(nums,k);
    std::cout<<ans;
    return 0;
}