//CF=>1373A(Donut Shop)
#include<iostream>
using namespace std;
typedef long long int lli;
int main(){
    lli t;  cin>>t;
    while(t--){
        lli a,b,c;  cin>>a>>b>>c;
        if(a>=c){
            cout << -1 << " " <<((a==c)?(2):(1))<< endl;
        } 
        else if (a < c)
        {
            cout << 1 << " " << ((a*b > c) ? (b) : (-1)) << endl;
        } 
    }
    return 0;
}
