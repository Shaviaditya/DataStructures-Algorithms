#include <iostream>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
int  solve(int n, int pos)
{
    return (n|(1 << pos));
}
int main()
{
    int n, pos;
    cin >> n >> pos;
    cout<<solve(n, pos)<<endl;
    return 0;
}