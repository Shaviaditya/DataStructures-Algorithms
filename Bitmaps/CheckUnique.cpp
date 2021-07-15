//Program : All elements have been repeated exactly twice except one such number find it!
/*
    Properties to keep in mind:
    0 ^ Y = Y
    Y ^ Y = 0
*/
#include <iostream>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
void solve(int A[],int n){
    int c=A[0];
    loop(i,1,n){
        c = c^A[i];
    }
    cout<<c<<endl;
}
int main(){
    int n;  cin>>n;
    int A[n];
    loop(i,0,n){
        cin>>A[i];
    }
    solve(A,n);
    return 0;
}