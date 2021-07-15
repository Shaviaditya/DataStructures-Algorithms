#include<iostream>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
int main(){
    int n;  cin>>n;
    int arr[n];
    loop(i,0,n){
        cin>>arr[i];
    }
    int k,mx=0;  cin>>k;
    loop(i,0,k){
        mx = max(mx,arr[i]);
    }
    cout<<mx<<endl;
    return 0;
}