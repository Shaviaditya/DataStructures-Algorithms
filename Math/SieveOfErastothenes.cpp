/*Sieve of Erasthothenes Algorithm*/
#include <bits/stdc++.h>
using namespace std;
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime,true,sizeof(prime)/sizeof(prime[0]));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]){
            cout << p << " ";
        }cout<<endl;
}

int main()
{
    int n;  cin>>n;
    SieveOfEratosthenes(n);
    return 0;
}