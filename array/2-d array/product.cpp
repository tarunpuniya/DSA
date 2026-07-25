#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int num; cout<<"Enter the digits: "; cin>>num;
    vector<int> arr;

    while (num > 0) {
        arr.push_back(num%10);
        num/=10;
}
reverse(arr.begin(),arr.end());

int m = arr.size();
int count = 0;
for(int i=0; i<m; i++){
    for(int j=i+1; j<m; j++){
        count = max(count,arr[i]*arr[j]);
    }
}
cout<<count<<" ";


}