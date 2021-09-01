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
        ptr->next = n;
        n->next = temp;
        //n->next = ptr->next;
        //ptr->next = n;
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
void deletion(node* &head,int val){
    node* temp=head;
    if(temp==NULL){
        return;
    }
    if(temp->next==NULL){
        node *rem = head;
        head = temp->next;
        delete rem;
        return;
    }
    if(temp->data==val){
        node* rem = head;
        head = temp->next;
        delete rem;
    } else {
        while(temp->next->data!=val){
            temp = temp->next;
        }
        node* rem = temp->next;
        temp->next = temp->next->next;
        delete rem;
    }
}
void deleteAlt(node* &head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        node *ptr2 = ptr->next;
        ptr = ptr2->next;
        ptr2 = NULL;
    }
}
int main(){
    node *head=NULL;
    insert(head,10,1);
    insert(head, 20, 2);
    insert(head, 40, 3);
    insert(head, 50, 4);
    insert(head,60,5);
    insert(head,70,6);
    //insertSorted(head, 30);
    //insertSorted(head, 95);
    print(head);
    deleteAlt(head);
    print(head);
    return 0;
}