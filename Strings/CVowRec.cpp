#include<iostream>
using namespace std;
//pippxxppiixipi
string stringpi(string st,string sf){
    //base case
    if(st.length()==0){
        return sf;
    } else {
        if(st.substr(0,2)=="pi"){
            sf = sf + "3.14";
            return stringpi(st.substr(2),sf);
        } else {
            sf = sf + st[0];
            return stringpi(st.substr(1),sf);
        }
    }
}
int main(){
    string bt = "pippxxppiixipi";
    cout<<stringpi(bt,"")<<endl;
    return 0;
}