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
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll x=0; x<n; x++){
            cin>>a[x];
        }
        ll dp[n+1][k+1];
        memset(dp,-1,sizeof(dp));
        for(ll y=1; y<=k; y++){
            ll flag=-1;
            for(ll x=0; x<n; x++){
                ll t=y-a[x];
                if(t<0){
                    dp[x][y]=-1;
                    //flag=-1;
                }
                else{
                    if(dp[n][t]==1){
                        dp[x][y]=2;
                        if(flag==-1){
                            flag=0;
                        }
                    }
                    else{
                        dp[x][y]=1;
                        flag=1;
                    }
                }
                //cout<<dp[x][y]<<" ";
            }
            //cout<<"\n";
            if(flag==1){
                dp[n][y]=1;
            }
            else if(flag==0){
                dp[n][y]=2;
            }
            else{
                dp[n][y]=-1;
            }
            //cout<<dp[n][y]<<"\n";
        }
        if(dp[n][k]==1||dp[n][k]==-1){
            cout<<"First\n";
        }
        else{
            cout<<"Second\n";
        }
        mp.clear();  
        v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}