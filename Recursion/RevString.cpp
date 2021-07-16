#include<iostream>
using namespace std;
void reverse(string st){
    if(st.length()==0){
        return;
    } else {
        reverse(st.substr(1));
        cout<<st[0];
    }
}
int main(){
    string st;  cin>>st;
    reverse(st);
    cout<<"\n";
    return 0;
}