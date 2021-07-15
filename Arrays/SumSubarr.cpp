//Google 2008 X Google Kickstart 2019A
//Find constinuous subarray that adds to a given number S
/*
Logic: We would apply 2 pointers and increase till (ptr1+ptr2<=S)
*/
#include <iostream>
using namespace std;
typedef long long int lli;
#define loop(i, a, b) for (lli i = a; i < b; i++)
void solve(lli A[],lli n,lli s){
    lli c=0;
    lli ptr1=A[c],i=c+1;
    lli ptr2 = A[i];
    ptr2 = ptr2+ptr1;
    while(ptr2!=s){
        while(ptr2 < s)
        {
            i++;
            ptr2 = ptr2 + A[i];
        }
        if(ptr2==s){
            cout<<c+1<<" "<<i+1<<endl;
            break;
        } else {
            c++;
            ptr1 = A[c];
            i = c+1;
            ptr2 = A[i];
            ptr2 = ptr2+ptr1;
        }
    }
    if(ptr2==s){
        cout << c + 1 << " " << i + 1 << endl;
    }
}
int main()
{
    lli n;  cin>>n;
    lli A[n];
    loop(i,0,n){
        cin>>A[i];
    }
    lli s;  cin>>s;
    solve(A,n,s);
    return 0;
}