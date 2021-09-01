#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
    lli t;  cin>>t;
    while(t--){
        lli a,b;    cin>>a>>b;
        if(__gcd(a,b)>1){
            cout<<0<<endl;
        } else {
            if ((a % 2 == 0 && b % 2 != 0)||(a % 2 != 0 && b % 2 == 0))
            {
                cout<<1<<endl;
            }
            else{
                if(__gcd(a+1,b)>1){
                    cout<<1<<endl;
                }
                else if (__gcd(a, b+1) > 1)
                {
                    cout<<1<<endl;
                } else { 
                    cout<<2<<endl;
                }
            }
        }
    }
    return 0;
}