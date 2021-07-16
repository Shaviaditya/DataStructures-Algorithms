#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node* next;

    //Constructor
    node(int val){
        data = val;
        next = NULL;
    }
};
void print(node* head){
    //node* n = new node(val);
    node* temp= head;
    while(temp!=NULL){
        cout << temp->data <<"->";
        temp = temp->next;
    }cout<<"NULL";
    cout<<endl;
}
/*
void insertend(node* &head,int val){
    node* n = new node(val);
    if(head!=NULL){
        node *temp = head;
        while(temp->next!= NULL)
        {
            //cout << temp->data << endl;
            temp = temp->next;
        }
        temp->next = n;
    } else {
        head = n;
        return;
    }
}
void inserthead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}
*/
void insert(node* &head,int val,int pos){
    node* n = new node(val);
    if(pos==1){
        n->next = head;
        head = n;
    } else {
        node* temp = head;
        node* ptr;
        while (pos > 1)
        {
            ptr = temp;
            temp = temp->next;
            pos--;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}
void insertSorted(node* &head,int val){
    node* n = new node(val);
    node* temp = head;
    if(val<(head->data)){
        n->next = head;
        head = n;
    } else {
        node* ptr;
        while (val > (temp->data))
        {
            ptr = temp;
            temp = temp->next;
            if(temp==NULL){
                break;
            }
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}
int main(){
    node *head=NULL;
    insert(head,10,1);
    insert(head, 20, 2);
    insert(head, 40, 3);
    insert(head, 50, 4);
    insertSorted(head, 30);
    insertSorted(head, 95);
    print(head);
    return 0;
}