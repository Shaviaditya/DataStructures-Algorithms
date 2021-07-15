//Amazon X Oracle Interview 2010
//Find the least index that is being repeated
#include<iostream>
using namespace std;
typedef long long int lli;
#define loop(i,a,b) for(lli i=a;i<b;i++)
int main(){
    lli n;  cin>>n;
    lli A[n],mx=0;
    loop(i,0,n){
        cin>>A[i];
        mx=max(mx,A[i]);
    }
    lli B[mx+1] = {0};
    loop(i, 0, n){
        B[A[i]]++;
    }
    int val=0;
    loop(i,0,n){
        val = A[i];
        A[i] = B[A[i]];
        if(A[i]>1){
            cout<<val<<" "<<A[i]<<endl;
            break;
        }
    }
    return 0;
}