#include <iostream>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
void solve(int n,int pos){
    cout<<((n&(1<<pos))!=0?(1):(0))<<endl;
}
int main()
{
    int n,pos;  cin>>n>>pos;
    solve(n,pos);
    return 0;
}