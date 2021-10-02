#include<iostream>
#include<deque>
using namespace std;

int arr[10000005];
int main() {
    deque<int> dq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int mx=0;
    for(int i=0;i<k;i++){
        if(dq.empty())
            dq.push_front(i);
        else{
            while(!dq.empty()&&arr[i]>arr[dq.back()])
                    dq.pop_back();
            dq.push_back(i);
        }
    }
    cout<<arr[dq.front()]<<" ";
    for(int i=k;i<n;i++){
        if(dq.front()<=i-k)
            dq.pop_front();
        while(!dq.empty()&&arr[i]>arr[dq.back()])
                dq.pop_back();
        dq.push_back(i);
        cout<<arr[dq.front()]<<" ";
    }
	return 0;
}
