// Reverse a string using recursion
#include<iostream>
using namespace std;
#define newline printf("\n")
void revstring(string st){
    if(st==""){
        return;
    }
    revstring(st.substr(1));
    cout<<st[0];
}
int main(){
    string st = "kuchipuddi";
    revstring(st);
    newline;
    return 0;
}