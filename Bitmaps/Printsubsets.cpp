/*
    TCSNinja =>>
    Important: The program code uses bitwise operators to check for 1's in the binary till 2^length-1 and
    using it as a reference printing corresponding index values using a nested loop construct...
*/
#include <iostream>
#include <math.h>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
void solve(int A[],int n) {
    loop(i,0,1<<n){
        loop(j,0,n){
            if(i&(1<<j)){
                cout<<A[j]<<" ";
            } 
        }cout<<endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    loop(i,0,n){
        cin>>A[i];
    }
    solve(A,n);
    return 0;
}