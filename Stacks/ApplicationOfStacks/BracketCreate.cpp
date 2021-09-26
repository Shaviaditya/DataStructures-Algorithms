// https://codeforces.com/problemset/problem/1547/A
#include <bits/stdc++.h>
using namespace std;
#define IOSfaststream            \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
typedef long long int lli;
#define ln(x) x.length()
#define YY cout << "YES" << endl
#define NN cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define auto_input(v, x) \
    for (auto &x : v)    \
    {                    \
        cin >> x;        \
    }
#define displayst(v, x)   \
    for (auto x : v)      \
    {                     \
        cout << x << " "; \
    }
#define displayMaps(v, x)                           \
    for (auto x : v)                                \
    {                                               \
        cout << x.first << " " << x.second << "\n"; \
    }
#define vec(v, n) vector<lli> v(n)
#define mapit map<lli, lli>
#define f(i, a, b) for (int i = a; i < b; i++)
#define sf scanf
#define pf printf
const lli MOD = 1e9 + 7;
int main()
{
    IOSfaststream
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        stack<char> stk;
        int n;
        cin >> n;
        int c = n;
        for (int i = 1; i <= n; i++)
        {
            {
                for (int j = 1; j <= i; j++)
                {
                    stk.push(')');
                }
                for (int j = 1; j <= i; j++)
                {
                    stk.push('(');
                }
                for (int j = 1; j <= (n - i); j++)
                {
                    stk.push(')');
                }
                for (int j = 1; j <= (n - i); j++)
                {
                    stk.push('(');
                }
            }
            while (!stk.empty())
            {
                cout << stk.top();
                stk.pop();
            }
            cout << "\n";
        }
    }
    return 0;
}