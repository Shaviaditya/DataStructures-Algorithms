#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fo(i,a,b) for(int i=a ; i<b ; i++)
#define foe(i,a,b) for(int i=a ; i<=b ; i++)
#define endl '\n'
#define ff first
#define ss second
#define MOD 1000000007

vi adjl[1000001];
bool vis[1000001];
int col[1000001];

bool dfs(int node, int c)
{
    vis[node]=true;
    col[node]=c;
    for(int child : adjl[node])
    {
        if(!vis[child])
        {
            if(dfs(child, c^1)==false) return false;
        }
        else if(col[child] == col[node]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(col, -1, sizeof(col));
    int n,m; cin>>n>>m;
    fo(i,0,m)
    {
        int x,y; cin>>x>>y;
        adjl[x].pb(y);
        adjl[y].pb(x);
    }
    int flag=0;
    foe(i,1,n)
    {
        if(!vis[i])
        {
            if(dfs(i,0)==false) flag=1;
        }
    }
    if(flag==0) cout<<"Bipartite Graph"<<endl;
    else cout<<"Not Bipartite Graph"<<endl;
    
    return 0;
}