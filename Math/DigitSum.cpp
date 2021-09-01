#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        string st = to_string(n);
        if (st[st.length() - 1] == '9')
        {
            cout << (n - (n % 10)) / 10 + 1 << endl;
        }
        else
        {
            cout << (n - (n % 10)) / 10 << endl;
        }
    }
    return 0;
}