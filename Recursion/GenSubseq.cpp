#include<bits/stdc++.h>
using namespace std;
vector<string> vst;
void subseq(string st,string ans){
    if(st.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = st[0];
    string sf = st.substr(1);
    subseq(sf,ans);
    subseq(sf,ans+ch);
}
int main(){
    string st = "abcdabcd";
    subseq(st,"");
    return 0;
}