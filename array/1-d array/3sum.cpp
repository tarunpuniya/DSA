#include<bits/stdc++.h>

int closest(std::vector<int>&nums , int target){
    int n = nums.size();
    int closestsum = nums[0]+nums[1]+nums[2];
    for(int i =0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int currentsum = nums[i]+nums[j]+nums[k];
                if(abs(currentsum-target)<abs(closestsum-target)){
                    closestsum=currentsum;
                }
                
            }
        }
    }
    return closestsum;
}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        nums.push_back(ele);
    }
    int target; std::cout<<"Enter the target: "; std::cin>>target;
    int ans = closest(nums,target);
    std::cout<<ans;
    return 0;


}