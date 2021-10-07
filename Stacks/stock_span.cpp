// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

// The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) 
// for which the stock price was less than or equal to today's price.


#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

vector <int> solve(vector <int> arr){
    stack<pair<int,int> > stk;
    vector <int> sol(arr.size());
    stk.push(make_pair(arr[0], 1));
    sol[0] = 1;
    for (int i = 1; i < arr.size(); i++){
        pair <int, int> temp = {arr[i], 1};
        while(!stk.empty() && stk.top().first<arr[i]){
            temp.second+=stk.top().second;
            stk.pop();
        }
        stk.push(temp);
        sol[i]=temp.second;
    }
    return sol;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector <int> sol =solve(arr);
    for(int i=0; i<n; i++){
        cout<<sol[i]<<" ";
    }
    return 0;
}