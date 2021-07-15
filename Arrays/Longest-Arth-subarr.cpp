//Google Kickstart 2018A
#include<iostream>
using namespace std;
#define loop(i, a, b) for (int i = a; i < b; i++)
int main(){
    int t,m=1;  cin>>t;
    while(m!=t+1){
        int n;
        cin >> n;
        int arr[n];
        loop(i, 0, n)
        {
            cin >> arr[i];
        }
        int cnt = 1, mx = -100001;
        int diff = arr[1]- arr[0];
        loop(i,1,n-1){
            if(arr[i+1]-arr[i]==diff){
                cnt++;
            } else {
                mx = max(mx,cnt);
                diff = arr[i + 1] - arr[i];
                cnt = 1;
            }
        }
        if(cnt>=1){
            mx = max(mx,cnt);
        }
        cout<<"Case #"<<m<<": "<<mx+1<<endl;
        m++;
    }
    return 0;
}
