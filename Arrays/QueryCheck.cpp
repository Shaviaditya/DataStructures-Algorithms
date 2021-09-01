#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t;  cin>>t;
    while(t--){
        lli n,m,x=0;    cin>>n>>m;
        lli hashed[n+1];
        hashed[0] = 0;
        for(lli i=1;i<=n;i++){
            cin>>x;
            if(x%2==1){
                hashed[i] = hashed[i-1];
            } else {
                hashed[i] = hashed[i-1] + 1;
            }
        }
        while(m--){
            lli l1,l2;  cin>>l1>>l2;
            lli e = hashed[l2] - hashed[l1 - 1];
            lli o = (l2-l1+1)-e;
            //1 2 3 4 5 6 
            lli val = ((e*(e-1)*(e-2))/6)+((o*(o-1))/2)*e;
            cout<<val<<endl;
        }
    }
    return 0;
}