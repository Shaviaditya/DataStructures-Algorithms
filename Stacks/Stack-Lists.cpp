#include<bits/stdc++.h>
using namespace std;
class StackNode {
    public:
        int data;
        StackNode* next;
};
StackNode* newNode(int data){
    StackNode* stknode = new StackNode();
    stknode->data = data;
    stknode->next = NULL;
    return stknode;
}
bool isEmpty(StackNode* root){
    return (!root);
}
void push(StackNode** root, int val){
    StackNode* node = newNode(val);
    node->next = *root;
    *root = node;
    printf("%d pushed into the stack",val);
}
int pop(StackNode** root){
    if(isEmpty(*root)){
        printf("Stack Underflow\n");
        return INT_MIN;
    } else {
       StackNode* temp = *root;
       *root = (*root)->next;
       int x = (*temp).data;
       free(temp);
       return x; 
    }
}
int peek(StackNode* root){
    if(isEmpty(root)){
        printf("Stack Underflow\n");
        return INT_MIN;
    } else {
        return root->data;
    }
}
//Driver Code
int main(){
    StackNode* stk = NULL;
    push(&stk,10);
    push(&stk, 15);
    push(&stk, 20);
    cout<< pop(&stk) << "popped from the stack\n";
    cout<< peek(stk) << "is the top element now\n";
    while(!isEmpty(stk)){
        cout<<peek(stk)<<" ";
        pop(&stk);
    }cout<<"\n";
    return 0;
}
