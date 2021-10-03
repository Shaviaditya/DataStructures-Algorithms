#include <bits/stdc++.h>
using namespace std;

bool isSafe (int **arr, int x, int y, int n){

    if (x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **resultArr){

    if (x == n-1 && y == n-1){
        resultArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n)){
        resultArr[x][y] = 1;
        if (ratInMaze (arr, x+1, y, n, resultArr)){
            return true;
        }
        if (ratInMaze (arr, x, y+1, n, resultArr)){
            return true;
        }

        resultArr[x][y] = 0; //Backtracking
        return false;
    }

    return false;

}

int main() {

    int n; cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++){
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    cout << "\n";

    int **resultArr = new int*[n];
    for (int i = 0; i < n; i++){
        resultArr[i] = new int[n];
        for (int j = 0; j < n; j++){
            resultArr[i][j] = 0;
        }
    }


    if(ratInMaze(arr, 0, 0, n, resultArr)){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << resultArr[i][j] <<" ";
            }
            cout << "\n";
        }
    }

    return 0;
}

/* 

1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

 */