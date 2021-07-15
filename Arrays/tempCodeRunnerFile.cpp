//Google Kickstart 2018A
#include<iostream>
using namespace std;
#define loop(i, a, b) for (int i = a; i < b; i++)
int main(){
    int t,m=1;  cin>>t;
    while(m!=t+1){
        int n;
        cin >> n;
        int arr[n];
        loop(i, 0, n)
        {
            cin >> arr[i];
        }
        int cnt = 0, mx = 0;
        loop(i, 0, n - 2)
        {
            int diff = arr[i + 1] - arr[i];
            int diff2 = arr[i + 2] - arr[i + 1];
            if (diff == diff2)
            {
                cnt++;
            }
            else
            {
                mx = max(mx, cnt + 2);
                cnt = 0;
            }
        }
        cout<<"Case #"<<m<<": "<<mx<<endl;
        m++;
    }
    return 0;
}
