//Checking number of 1s in a given binary!
#include <iostream>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
#define YY cout << "Yes" << endl;
#define NN cout << "No" << endl;
int count1(int n,int cnt){
    if(n==0){
        return cnt;
    } else {
        cnt=cnt+1;
        return count1(n&(n-1),cnt);
    }
}
int main()
{
    int n;
    cin >> n;
    cout<<count1(n,0)<<endl;
    return 0;
}