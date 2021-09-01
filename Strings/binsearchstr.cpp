#include <bits/stdc++.h>
using namespace std;
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
int main()
{
    fastIO int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string row1, row2;
        cin >> row1 >> row2;
        int c = 0;
        bool flag = false;
        if (row2[0] == '1' && row1[1] == '1')
        {
            row1[1] = '2';
            c++;
        }
        else if (row2[0] == '1' && row1[0] == '0')
        {
            row1[0] = '2';
            c++;
        }
        for (int i = 1; i <= (n - 2); i++)
        {
            if (row2[i] == '1')
            {
                if (row1[i - 1] == '1')
                {
                    row1[i - 1] = '2';
                    c++;
                }
                else if (row1[i + 1] == '1')
                {
                    row1[i + 1] = '2';
                    c++;
                }
                else if (row1[i] == '0')
                {
                    row1[i] = '2';
                    c++;
                }
            }
        }
        if (row2[n - 1] == '1' && row1[n - 2] == '1')
        {
            row1[n - 2] = '2';
            c++;
        }
        else if (row2[n - 1] == '1' && row1[n - 1] == '0')
        {
            row1[n - 1] = '2';
            c++;
        }
        cout << c << endl;
    }
    return 0;
}