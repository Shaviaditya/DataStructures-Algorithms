#include <iostream>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
int solve(int n, int pos,int pos2)
{
    return (n & (~(1 << pos))|(1<<pos2));
}
int main()
{
    int n, pos, pos2;
    cin >> n >> pos>>pos2;
    cout << solve(n, pos,pos2) << endl;
    return 0;
}