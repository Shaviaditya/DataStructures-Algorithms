/*
    Q: Wipro screening basic
    Replace each instace of 'pi' in pippxxppiixipi with 3.14 USING RECURSION!!
*/
#include<iostream>
using namespace std;
string replace(string st,string sg){
    if(st.length()==0){
        return sg;
    }
    if(st[0]=='p' && st[1]=='i'){
        sg = sg + "3.14";
        return replace(st.substr(2),sg);
    } else {
        sg = sg + st[0];
        return replace(st.substr(1),sg);
    }
}
int main(){
    string st;  cin>>st;
    string sg="";
    cout<<replace(st,sg)<<endl;
    return 0;
}