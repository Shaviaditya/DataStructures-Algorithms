/* Q: The Question is a classic to understand how recursion works:
        For decreasing we print first then call say for n = 3
        print(3) call(2) print(2) call(1) print(1) => 3 2 1
        recursion now calls the blocks as: 
        call(1) print(1) call(2) print(2) call(3) print(3) => 1 2 3
        Voila!
*/
#include<iostream>
using namespace std;
void dec(int n){
    if(n==0){
        cout<<"Increasing Order"<<endl;
    } else {
        cout<<n<<endl;
        dec(n-1);
        cout<<n<<endl;
    }
}
int main(){
    int n;  cin>>n;
    cout<<"Decreasing Order"<<endl;
    dec(n);
    return 0;
}