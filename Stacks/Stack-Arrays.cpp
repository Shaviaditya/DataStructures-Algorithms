//Stack Implementation using arrays C++
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

//Defining a class to implement functions like push,pop,peek etc
class Stack {
    int top;
    public:
        int arr[MAX];
        Stack(){
            top = -1;
        };
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

//Pushing in a stack
bool Stack::push(int val){
    if(top>=(MAX-1)){
        printf("Stack Overflow\n");
        return false;
    } else {
        arr[++top] = val;
        printf("%d pushed into the stack!\n",val);
        return true;
    }
}

//Popping from a stack
int Stack::pop(){
    if(top<0){
        printf("Stack Underflow\n");
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
}

//Check isEmpty
bool Stack::isEmpty(){
    return (top<0);
}

//Peek the stack
int Stack::peek(){
    if(top<0){
        printf("Stack is empty\n");
        return 0;
    } else {
        int x =arr[top];
        return x; 
    }
}

//Driver Code
int main(){
    class Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    printf("Elements present in the Stack\n");
    while(!stk.isEmpty()){
        printf("%d ",stk.peek());
        stk.pop();
    }printf("\n");
    return 0;
}