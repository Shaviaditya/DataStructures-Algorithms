#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Node{
   public:
   int data;
   Node* next; 
};
Node* pop(Node* head){
    if(head==NULL)
    return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
void push(Node* head){
    while(head->next!=NULL)
    head=head->next;
    int d; cin>>d;
    Node* node = new Node();
    node->data=d;node->next=NULL;
    head->next=node;
}
void peek(Node* head){
    if(head==NULL){
        cout<<"EMPTY"<<endl;
    }
    else
    cout<<head->data<<endl;
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
   Node* head = NULL;
   int c; cin>>c;
   while(c!=0){
       if(c==1){
           if(head==NULL){
               int d;cin>>d; head=new Node(); head->data=d;head->next=NULL;
           }
           else
           push(head);
       }
       if(c==2){
           head=pop(head);
       }
       if(c==3){
           peek(head);
       }
       if(c==4){
           print(head);
       }
       cin>>c;
   }
}