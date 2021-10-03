#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define ll long long
#define N 101

using namespace std;

/* struct Optimizer{
    Optimizer(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
};

Optimizer opt; */

int arr[N][N], I[N][N];

void mul(int A[N][N] , int B[N][N] , int dim){
    int res[dim+1][dim+1];

    REP(i, dim) REP(j, dim) {
        res[i][j] = 0;
        REP(k, dim) res[i][j] += A[i][k] * B[k][j];
    }

    REP(i, dim) REP(j, dim) A[i][j] = res[i][j];
}

void power(int A[N][N], int dim, int n){
    REP(i, dim) REP(j, dim){
        if(i == j) I[i][j] = 1;
        else       I[i][j] = 0;
    }

    // Complexity of O(M^3 * N)
    /* REP(i, n) 
    mul(I, A, dim); */

    //Complexity of O(M^3 * logN)
    while(n){
        if(n % 2) mul(I, A, dim), n--;

        else mul(A, A, dim), n /= 2;
    }

    REP(i, dim) REP(j, dim) A[i][j] = I[i][j];
}

void printMat(int A[][N], int dim){
    REP(i, dim) {
        REP(j, dim) cout << A[i][j] << " ";
        cout << "\n";
    }
}

int main(){

    int t, dim, n; cin >> t;
    while (t--){
        cin >> dim >> n;

        REP(i, dim) REP(j, dim) cin >> arr[i][j];

        power(arr, dim, n);
        printMat(arr, dim);    
    }    

    return 0;
}