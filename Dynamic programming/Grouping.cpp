#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};
void solve()
{
    ll n,c;
    cin>>n>>c;
    ll h[n];
    ll dp[n];
    for(int i=0;i<n;i++)
        cin>>h[i];
        HullDynamic e;
        e.insert_line(2ll*h[0],-(h[0]*h[0]));
    for(int i=1;i<n;i++)
    {
        dp[i]=-e.eval(h[i])+h[i]*h[i]+c;
        e.insert_line(2ll*h[i],-dp[i]-h[i]*h[i]);
    }
    cout<<dp[n-1];
}
int main()
{
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
}

