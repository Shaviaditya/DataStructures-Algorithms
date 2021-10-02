//https://codeforces.com/problemset/problem/1020/B

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) (a).begin(),(a).end()
#define FOR(i, a, n) for(int i = a; i < (n); i++)
#define r0 return 0;
#define endl '\n'
#define INF (int)1e15
#define SIZE 100010
// Debugger
string to_string(string s) { return '"' + s + '"';}
string to_string(bool f) { if(f) return "True"; else return "False";}
string to_string(const char* s) { return to_string((string) s);}

struct Optimizer{
  Optimizer(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
};

Optimizer opt;

vector<int> graph[SIZE];
bool visited[SIZE];
vector<int> results;

void dfs(int node){
  visited[node] = true;

  for (int i = 0; i < graph[node].size(); ++i){
    int next = graph[node][i];
    if (!visited[next])
      dfs(next);

    else if (visited[next])
      results.push_back(next);
  }
}

void solve () {
  int n; cin >> n;
  
  FOR(i, 1, n+1){
    int p; cin >> p;
    graph[i].push_back(p);
  }

  FOR (i, 1, n+1){
    memset(visited, 0, n+2);
    visited[i] = true;
    dfs(graph[i][0]);
  }
  // cout << "Visited: "; 
  // for (int i = 0; i < n+1; i++) cout << visited[i] << " ";
  // cout << "\n\nResults: "; 
  for (auto result: results) cout << result << " ";

}

signed main(){

  solve();

  r0
}