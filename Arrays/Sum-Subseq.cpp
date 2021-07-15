#include <iostream>
using namespace std;
#define loop(i, a, b) for (int i = a; i < b; i++)
int main()
{
    int n;
    cin >> n;
    int arr[n];
    loop(i, 0, n)
    {
        cin >> arr[i];
    }
    int k=0,s=0;
    loop(i, 0, n)
    {
        s = s + arr[i];
        loop(j,i+1,n){
            s = s + arr[j];
            k = k + s;
            cout<<k<<endl;
        }
    }
    //cout << k << endl;
    return 0;
}