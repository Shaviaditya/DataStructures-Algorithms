/*
3 0 0
2 0 1
1 1 1
1 2 0
0 2 1
0 0 3
*/
#include<iostream>
using namespace std;
void ToI(int n,char src,char des,char help){
    if(n==0){
        return;
    } else {
        //cout << "Moving from" << src << " to " << des << endl;
        ToI(n-1, src, help , des);
        cout << "Moving from" << src << " to " << des << endl;
        ToI(n - 1, help,des,src);
    }
}
int main(){
    int n;  cin>>n;
    ToI(n,'A','C','B');
}