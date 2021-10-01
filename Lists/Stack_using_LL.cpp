#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Node{
   public:
   int data;
   Node* next; 
};
void push(Node* head){
    while(head->next!=NULL)
    head=head->next;
    Node* node = new Node();
    int d;cin>>d;
    head->next=node;
    node->data=d;
    node->next=NULL;
}
void peek(Node* head){
     if(head==NULL)
     cout<<"Empty"<<endl;
     else{
         while(head->next!=NULL)
    head=head->next;
    cout<<head->data<<endl;
     }
}
void pop(Node* head){
     
   
        if(head->next==NULL)
    {
        delete head; head=NULL;
        }
    else{
        while(head->next->next!=NULL)
          head=head->next;
        delete head->next;
        head->next=NULL;
    }
    
}
void print(Node* head){
    while(head->next!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<head->data<<endl;
}
int main(){
    sync;
    Node* head = NULL;
     int c; cin>>c;
     while(c!=0){
         if(c==1)
         {
             if(head==NULL){
                 head=new Node();
                 int d;cin>>d;head->data=d;head->next=NULL;
             }
             else
             push(head);
         }
         if(c==2){
             peek(head);
         }
         if(c==3){
            if(head==NULL)
            cout<<"Empty"<<endl;
            else{
                 if(head->next!=NULL){
                   pop(head);  
             }
           
             else{
                 pop(head);
                 head=NULL;
             }
            }
             
         }
         if(c==4){
             if(head!=NULL)
             print(head);
             else
             cout<<"Empty"<<endl;
         }
         cin>>c;
     }
     return 0;
}