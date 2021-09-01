/*Q: https://codeforces.com/problemset/problem/978/C
    The problem is important because it features implemtation of 
    binary search
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
int main(){
    lli n,m;    cin>>n>>m;
    vector<lli> vn,vm,vb;
    lli s = 0;
    loop(i,0,n){
        lli x;  cin>>x;
        vb.push_back(x);
        s = s + x;
        vn.push_back(s);
    }
    loop(i,0,m){
        lli y;  cin>>y;
        vm.push_back(y);
    }
    loop(i,0,m){
        lli l =0,r = n-1,mid=0;
        while(l<=r){
            mid=(l+r)/2;
            if (vm[i] <= vn[mid]){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(l==0){
            cout<<l+1<<" "<<vm[i]<<endl;
        } else {
            cout<<l+1<<" "<<vb[l] -(vn[l]-vm[i])<<endl;
        }
    }
    return 0;
}