/*
    https://codeforces.com/problemset/problem/1530/C
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define ld long double
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (lli i = a; i < b; i++)
#define revloop(i, a, b) for (lli i = a; i >= b; i--)
#define pb push_back
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define YY cout << "YES" << endl
#define NN cout << "NO" << endl
#define input(arr, n)             \
    for (ll i1 = 0; i1 < n; i1++) \
    cin >> arr[i1]
#define sz(x) x.size()
#define ln(x) x.length()
typedef vector<lli> vectorlli;
typedef vector<int> vectorint;
typedef vector<char> vectorchar;
typedef vector<string> vectorst;
typedef vector<ll> vectorll;
typedef pair<lli, lli> pairlli;
typedef pair<ll, ll> pairll;
typedef map<lli, lli> maplli;
typedef map<ll, ll> mapll;
typedef map<char, ll> mapch;
typedef map<string, ll> mapst;
const lli mod = 1e9 + 7;
const lli inf = 1e18;
int check(int n)
{
    return n - floor((double)n / 4);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        lli bk = n;
        vectorlli a, b, c, d;
        loop(i, 0, n)
        {
            lli x;
            cin >> x;
            a.pb(x);
        }
        loop(i, 0, n)
        {
            lli x;
            cin >> x;
            b.pb(x);
        }
        sort(all(a), greater<lli>());
        sort(all(b), greater<lli>());
        lli s = 0, s1 = 0;
        loop(i, 0, n)
        {
            s = s + a[i];
            c.pb(s);
            s1 = s1 + b[i];
            d.pb(s1);
        }
        lli k = check(n);
        lli maxc = c[n - 1], maxd = d[n - 1];
        if (c[k - 1] >= d[k - 1])
        {
            cout << 0 << endl;
        }
        else
        {
            int cnt = 0, v1 = c[k - 1], v2 = d[k - 1];
            while (v1 < v2)
            {
                n++;
                k = check(n);
                cnt++;
                if ((k - 1 - cnt) > (n - 1))
                {
                    v1 = maxc + (100 * cnt);
                }
                else if ((k - 1 - cnt) < 0)
                {
                    v1 = c[0] + (100 * cnt);
                }
                else
                {
                    v1 = c[k - 1 - cnt] + (100 * cnt);
                }
                if ((k) > bk)
                {
                    v2 = maxd;
                }
                else
                {
                    v2 = d[k - 1];
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}