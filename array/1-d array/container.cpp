// Brute force approach using nested loop check evry combination

#include<iostream>
#include<vector>
#include<algorithm>

int max(std::vector<int> &nums){
    int maxwater = 0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int width = j-i;
            int heigh = std::min(nums[i],nums[j]);
            int area = width*heigh;
            maxwater = std::max(maxwater,area);
        }
    }
    return maxwater;
}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        nums.push_back(ele);
    }

    int ans = max(nums);
    std::cout<<ans<<" ";
    return 0;
}

// Optimal aproach using two pointers 

#include<iostream>
#include<vector>
#include<algorithm>

int max(std::vector<int> &nums){
    int maxwater = 0;
    int n = nums.size();
    int left = 0;
    int right = n-1;
    while(left<right){
        int width = right-left;
        int height = std::min(nums[left],nums[right]);
        int current_water = height*width;
        maxwater=std::max(maxwater,current_water);
        if(nums[left]<nums[right]){
            left++;
        }else{
            right--;
        }
    }
    return maxwater;
}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        nums.push_back(ele);
    }

    int ans = max(nums);
    std::cout<<ans<<" ";
    return 0;
}

