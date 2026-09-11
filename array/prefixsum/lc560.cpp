#include<iostream>
#include<vector>
#include<unordered_map>

int result(std::vector<int>nums,int k){
    int n = nums.size();
    int prefixsum = 0;
    int ans = 0;
    std::unordered_map<int,int>freq;
    freq[1]=0;

    for(int i= 0; i<n; i++){
        prefixsum+=nums[i];
        int need = prefixsum-k;
        ans+=freq[need];
        freq[prefixsum]++;
    }
    return ans;

}

int main(){
    std::vector<int>nums = {1,2,3};
    int k = 3;

    int ans = result(nums,k);
    std::cout<<ans;
    return 0;
}