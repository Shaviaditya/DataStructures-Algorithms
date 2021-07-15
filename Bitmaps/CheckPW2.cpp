//Checking Power of 2 in <<O(1)>>
#include <iostream>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
#define YY  cout<<"Yes"<<endl;
#define NN cout << "No" << endl;
void check(int n){
    if(!(n&(n-1))){
        YY
    } else {
        NN
    }
}
int main()
{
    int n;  cin>>n;
    check(n);
    return 0;
}