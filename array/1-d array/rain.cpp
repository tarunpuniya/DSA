// leetcode problem no. 42

#include<iostream>
#include<algorithm>
#include<vector>

int max(std::vector<int> height){
    int n = height.size();
    int maxwater = 0;
    int left = 0;
    int right = n-1;
    int leftmax = height[left];
    int rightmax = height[right];
    while(left<right){
        if(leftmax<rightmax){
            left++;
            leftmax = std::max(leftmax,height[left]);
            maxwater+=leftmax-height[left];
        }else{
            right--;
            rightmax = std::max(rightmax,height[right]);
            maxwater+=rightmax-height[right];
        }
    }
    return maxwater;
   
}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int> height;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        height.push_back(ele);
    }
    int result = max(height);
    std::cout<<result<<" ";
    return 0;
}