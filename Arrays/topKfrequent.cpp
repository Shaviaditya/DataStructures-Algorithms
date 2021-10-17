// Given an array of integers and a number K, return the top K most frequent elements in the array.
// If the frequency for two or more elements is same, return them in sorted order.
// input : n (number of integers), k (number of elements to return), followed by n integers
// output: k most frequent integeres
// Example
// input: 
// 7 2
// 1 2 3 1 3 3 2
// output:
// 3 2

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

vector <int> topKFrequent (vector <int>& nums, int k){
    map <int, int> freq;
    vector <int> sol(k);
    multiset<pair<int,int>> multi;
    for(int i=0; i<nums.size(); i++){
        freq[nums[i]]++;
    }
        
    for(auto i=freq.begin(); i!=freq.end(); i++){
        pair<int, int> temp;
        temp.first= i->second;
        temp.second = i->first;
        multi.insert(temp);
    }
    
    int j = 0;
    for (auto i = multi.rbegin(); i != multi.rend() && j<k; i++){
        sol[j]=(i->second);
        j++;
    }
    return sol;
}

vector <int> topKFrequent_fast (vector <int>& nums, int k){
    map <int, int> freq;
    vector <int> sol(k);
    multiset <pair<int,int>> multi;
    for(int i=0; i<nums.size(); i++){
        freq[nums[i]]++;
    }
    int j=0;
    auto i=freq.begin();    
    for( ; j<k; i++, j++){
        pair<int, int> temp;
        temp.first= i->second;
        temp.second = i->first;
        multi.insert(temp);
    }
        
    for( ; i!=freq.end(); i++){
        pair<int, int> temp;
        temp.first= i->second;
        temp.second = i->first;
        multi.insert(temp);
        auto it=multi.begin();
        multi.erase(it);
    }
    j = 0;
    for (auto it = multi.rbegin(); it != multi.rend(); it++){
        sol[j]=(it->second);
        j++;
    }
    return sol;
}


int main(){
    fast_cin();
    int n,k;
    cin>>n>>k;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector <int> sol = topKFrequent_fast(arr, k);
    for(int i=0; i<sol.size(); i++){
        cout << sol[i];
    }
    return 0;
}