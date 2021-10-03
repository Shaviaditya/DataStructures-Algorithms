#include <bits/stdc++.h> 
#define F first 
#define S second 
#define MAX 10000003 
using namespace std; 

typedef long long int ll; 
const ll mod = 1000000007;

ll max(ll a, ll b) { return (a > b)? a : b; } 
  
ll knapSack(ll W, ll wt[], ll val[], ll n) 
{ 
   ll i, w; 
   ll K[n+1][W+1]; 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
   return K[n][W]; 
}  

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,w;
    cin>>n>>w;
    ll a[n],b[n];
    for(ll x=0; x<n; x++){
        cin>>a[x]>>b[x];
    }
    cout<<knapSack(w, a,b,  n) <<"\n";
    return 0;
}
