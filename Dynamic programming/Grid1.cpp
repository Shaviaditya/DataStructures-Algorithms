//   Rishabh Agarwal
#include <bits/stdc++.h>
#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long int ll;
const ll mod = 1e9+7;
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

vector<pair<ll,ll>>v;
vector<ll>::iterator it;
map<ll,ll>mp;

void primeFactors(ll n)  
{  
    while (n % 2 == 0)  
    {  
        mp[2]++;
        n = n/2;  
    }  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            mp[i]++;
            n = n/i;  
        }  
    }  
    if (n > 2){ 
        mp[n]++; 
    } 
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
        ll h,w;
        cin>>h>>w;
        char a[h][w];
        for(ll x=0; x<h; x++){
            for(ll y=0; y<w; y++){
                cin>>a[x][y];
            }
        }
        ll dp[h+1][w+1];
        for(ll x=0; x<=h; x++){
            for(ll y=0; y<=w; y++){
                if(x-1>=0&&y-1>=0&&a[x-1][y-1]=='#'){
                    dp[x][y]=0;
                }
                else if(x==0||y==0){
                    dp[x][y]=0;
                }
                else{
                    dp[x][y]=dp[x-1][y]+dp[x][y-1];
                }
                dp[1][1]=1;
                dp[x][y]%=mod;
            }
        }
        cout<<dp[h][w]<<"\n";
        mp.clear();  
        v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}