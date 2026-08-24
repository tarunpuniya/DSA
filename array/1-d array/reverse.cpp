#include<iostream>
using namespace std;
int main(){
    int arr[] = {4,8,3,7,9,0};
    int n = sizeof(arr)/4;
    cout<<"Elements in array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

   
    int start = 0;
    int end = n-1;
    cout<<endl;
    cout<<"Reverse an array: ";
    while(start<end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
    
}
   for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
   }
}