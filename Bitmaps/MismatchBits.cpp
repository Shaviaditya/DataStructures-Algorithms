/*
    Brian Kerningham's Algorithm
*/
#include <bits/stdc++.h>
using namespace std;
#define NN cout << "NO" << endl
#define YY cout << "YES" << endl
#define ln(x) x.length()
typedef long long int lli;
bool checkbit(int a, int b, int k)
{
    int XOR = a ^ b, cnt = 0;
    while (XOR)
    {
        XOR = XOR & (XOR - 1);
        cnt++;
    }
    if (cnt <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(m);
    for (auto &i : v)
    {
        cin >> i;
    }
    int key, c = 0;
    cin >> key;
    for (auto i : v)
    {
        if (checkbit(i, key, k) == true)
        {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}