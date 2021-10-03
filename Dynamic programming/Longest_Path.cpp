//   Rishabh Agarwal
#include <bits/stdc++.h>
#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long int ll;
const ll mod = 1e18;
const ll INF= 1e18;
long double PI=3.1415926;

ll power(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll temp=power(a,b/2)%mod;
    if(b%2==0){
        return (temp*temp)%mod;
    }
    else{
        return ((a*temp)%mod*temp)%mod;
    }
}

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

vector<vector<ll>> adj(100000); 
vector<ll> visited;
vector<ll> ans;

void dfs(ll v) {
    visited[v] = true;
    for (ll u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort(ll n) {
    visited.assign(n, false);
    ans.clear();
    for (ll i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    //cin>>t;
    t=1;
    //ll c=1;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>adj2(n+1);
        for(ll x=0; x<m; x++){
            ll y,z;
            cin>>y>>z;
            adj[y-1].push_back(z-1);
            adj2[z].push_back(y);
        }
        topological_sort(n);
        for(ll x=0; x<ans.size(); x++){
            ans[x]++;
        }
        ll dp[n+1]={0};
        ll an=0;
        for(ll x=0; x<ans.size(); x++){
            dp[ans[x]]=0;
            for(ll y=0; y<adj2[ans[x]].size(); y++){
                dp[ans[x]]=max(dp[ans[x]],dp[adj2[ans[x]][y]]+1);
            }
            an=max(an,dp[ans[x]]);
        }
        cout<<an<<"\n";
        adj2.clear();
        adj.clear();
        visited.clear();
        ans.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}