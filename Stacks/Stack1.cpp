//Q: Stack based Question to reverse a sentence
#include<iostream>
using namespace std;
#define n 100
class stack {
    string* arr;
    int head;
    public:
    stack(){
        arr = new string[n];
        head = -1;
    }
    void push(string x){
        if(head==(n-1)){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        head++;
        arr[head] = x;
    }
    void pop(){
        if(head==-1){
            cout<<"Noting to Pop out"<<endl;
            return;
        }
        head--;
    }
    string top(){
        if(head==-1){
            cout<<"Noting inserted"<<endl;
            return "";
        }
        return arr[head]; 
    }
    bool empty(){
        return (head==-1);
    }
};
int main(){
    stack st;
    string str,temp="";
    getline(cin,str);
    //cout<<str<<endl;
    str = str + " ";
    //cout<<str[0]<<endl;
    for(int i=0;i<str.length();i++){
        if(str[i]!=' '){
            temp = temp + str[i];
        } else {
            st.push(temp);
            temp = "";
        }
    }
    while(st.empty()!=1){
        cout << st.top() << " ";
        st.pop();
    }cout<<endl;
    return 0;
}