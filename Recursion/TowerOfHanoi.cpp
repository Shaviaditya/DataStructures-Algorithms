#include<iostream>
using namespace std;
void Hanoi(int n,char src, char dest, char mid){
    if(n==0){
        return;
    }
    Hanoi(n-1,src,mid,dest);
    cout<<"Moved "<<(n-1)<<"from "<<src<<" to "<<dest<<endl;
    Hanoi(n-1,mid,dest,src);
}
int main(){
    int n;  cin>>n;
    Hanoi(n,'A','C','B');
    return 0;  
}