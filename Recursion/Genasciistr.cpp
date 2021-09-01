#include <bits/stdc++.h>
using namespace std;
void subseq(string st, string ans)
{
    if (st.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = st[0];
    string asc = to_string((int)(ch));
    string sf = st.substr(1);
    subseq(sf, ans);
    subseq(sf,ans+asc);
    subseq(sf, ans + ch);
}
int main()
{
    string st = "BA";
    subseq(st, "");
    return 0;
}