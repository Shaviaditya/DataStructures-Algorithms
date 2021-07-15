/*Q: https://codeforces.com/problemset/problem/202/A
    The question is a conceptual and can be done in many ways but to make it insightful
    lets use bitmasks to get all the subjects in a vector and then filter out the palindrome
    ones after which choose the one which is lexicographically bigger.
*/
#include<bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define ln(x)   x.length()
int main(){
    int hash[26]={0};
    string st;  cin>>st;
    loop(i,0,ln(st)){
        hash[(int)(st[i])-97]++;
    }
    char ch;
    int freq=0;
    revloop(i,25,0){
        if(hash[i]>0){
            ch = (char)(97+i);
            freq = hash[i];
            break;
        }
    }
    loop(i,0,freq){
        cout<<ch;
    }cout<<endl;
    return 0;
}