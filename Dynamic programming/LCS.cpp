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

vector<ll>v;
vector<ll>::iterator it;
map<ll,ll>mp;

void primeFactors(ll n)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        //cout << 2 << " ";  
        mp[2]++;
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            //cout << i << " ";  
            mp[i]++;
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2){ 
        mp[n]++; 
        //cout << n << " "; 
    } 
}  

ll dp[3001][3001];

void solve(string a, string b){
    ll an=a.length();
    ll bn=b.length();
    for(ll x=0; x<=an; x++){
        for(ll y=0; y<=bn; y++){
            dp[x][y]=0;
        }
    }
    for(ll x=1; x<=an; x++){
        for(ll y=1; y<=bn; y++){
            dp[x][y]=max(dp[x-1][y],dp[x][y-1]);
            if(a[x-1]==b[y-1]){
                if(dp[x][y]<=dp[x-1][y-1]+1){
                    dp[x][y]=dp[x-1][y-1]+1;
                }
            }
        }
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
        string s,t;
        cin>>s>>t;
        solve(s,t);
        string out="";

        ll x=s.length();
        ll y=t.length();
        while(x>0&&y>0){
            if(s[x-1]==t[y-1]){
                out+=s[x-1];
                x--;
                y--;
            }
            else{
                if(dp[x-1][y]>dp[x][y-1]){
                    x--;
                }
                else{
                    y--;
                }
            }
        }

        reverse(out.begin(),out.end());
        cout<<out<<"\n";
        mp.clear();  
        v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}