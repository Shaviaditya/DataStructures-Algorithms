/*Q: https://codeforces.com/problemset/problem/1474/B
*/
#include<bits/stdc++.h>
using namespace std;
bool checkprime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
            break;
        }
    }
    return true;
}
int genprime(int n,int d){
    int bk = n;
    while(true){
        n++;
        if(n-bk>=d && checkprime(n)==true){
            break;
        }
    }
    return n;
}
int main(){
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        //cout<<genprime(1, n)<<endl;
        cout << genprime(1, n) * genprime(genprime(1, n), n) << endl;
    }
    return 0;
}