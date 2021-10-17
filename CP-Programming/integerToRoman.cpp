// Given an integer less than 10000, return the number in its Roman type.
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// R             for others (unkonwn)

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);


void allot(string &l, string &m, string &h, int n){
    if(n==1){
        l="I";
        m="V";
        h="X";
    }
    if(n==10){
        l="X";
        m="L";
        h="C";
    }
    if(n==100){
        l="C";
        m="D";
        h="M";
    }
    if(n==1000){
        l="M";
        m="R"; //don't know
        h="R"; //don't know
    }
    return;
}

string intToRoman(int num) {
    string sol="";
    int c=num;
    int n=10000;
    string l, m, h;
    while(n>1){
        n/=10;
        allot(l,m,h,n);  
        c= num/n;
        if(c==0);
        else if(c<4){
            int t=c;
            while(t--){
                sol+=l;
            }
        }
        else if(c==4){
            sol+=l;
            sol+=m;
        }
        else if(c==5){
            sol+=m;
        }
        else if(c<9) {
            sol+=m;
            int t=c%5;
            while(t--){
                sol+=l;
            }
        }
        else if (c==9) {
            sol+=l;
            sol+=h;
        }
        num=num%n;
    }
    return sol;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    string sol = intToRoman(n);
    cout << sol;
    return 0;
}