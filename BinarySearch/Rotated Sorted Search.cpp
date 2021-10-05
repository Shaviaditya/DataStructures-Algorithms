#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int b;
    cin>>b;
    int start = 0;
    int end = n-1;
    bool check = false;
    for(int i=0;i<n;i++){
        if(arr[i]==b)check=true;
    }
    while(start<=end){
        int mid= start + (end-start)/2;
        if(arr[mid]==b){
            cout<<mid;
            break;
        }
        else if(arr[mid]<b){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if(!check||start>end)cout<<"-1";
}