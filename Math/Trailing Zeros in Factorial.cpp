#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A;
    cin >> A;
    int ans = 0;
    if(A >= 0 && A < 5)cout<<"0"<<endl;
    for(int i=5;i<=A;i=i*5){
        ans += A/i;
    }
    cout<<ans<<endl;
}
