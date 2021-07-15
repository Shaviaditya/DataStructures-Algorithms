#include<iostream>
using namespace std;
int checksort(int A[],int n){
    if(A[n]-A[n-1]<0){
        return 0;
    } else if(n==1){
         return 1;
    } else {
        return checksort(A,n-1);
    }
}
int main(){
    int A[5] = {1,2,3,4,5};
    int B[5] = {3,4,5,1,2};
    cout<<checksort(A,5)<<endl;
    cout<<checksort(B,5)<<endl;
    return 0;
}