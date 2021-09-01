#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;  cin>>t;
    vector<string> v;
    while(t--){
        int n,m;    cin>>n>>m;
        string arr[2*n-1];
        for(int i=0;i<(2*n-1);i++){
            cin>>arr[i];
        }
        string sf="";
        int ch=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<(2*n-1);j++){
               ch = ch^(int)(arr[j][i]); 
            }
            sf = sf + (char)(ch);
            ch=0;
        }
        v.push_back(sf);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}