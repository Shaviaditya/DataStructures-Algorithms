//!!!!!!!!!!!!!!!!!!!!<< Highly Important  >>!!!!!!!!!!!!!!!!!!
//Program : All elements have been repeated exactly twice except two such unique number find it!
/*
    Properties to keep in mind:
    0 ^ Y = Y
    Y ^ Y = 0
    X ^ Y = Z
    X = Z ^ Y
*/
#include <iostream>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
int get_bit(int n)
{
    int cnt = 0;
    while ((n & (1 << cnt)) == 0)
    {
        cnt++;
    }
    return cnt;
}
void solve(int A[], int n)
{
    int c = A[0];
    loop(i, 1, n)
    {
        c = c ^ A[i];
    }
    //cout<<c<<endl;
    int pos = get_bit(c),d=0;
    loop(i,0,n){
        if((A[i]&(1<<pos))!=0){
            d = d^A[i];
        }
    }
    cout<<(c^d)<<" "<<d<<endl;
    
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    loop(i, 0, n)
    {
        cin >> A[i];
    }
    solve(A, n);
    return 0;
}