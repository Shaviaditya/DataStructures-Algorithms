#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};
void print(node* &head){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }cout<<endl;
}
//Iterative Method
node* reverse(node* &head){
    //Uses 3 pointer concept to reverse a list
    node* pre = NULL;
    node* cur = head;
    node* then;
    while(cur!=NULL){
        then = cur->next;
        cur->next = pre;
        pre = cur;
        cur = then;
    }
    return pre;
}
//Recursive Method
node* Recursive_reverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead = Recursive_reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
void insert(node *&head, int val, int pos)
{
    node *n = new node(val);
    if (pos == 1)
    {
        head = n;
        n->next = NULL;
    }
    else
    {
        node *temp = head;
        node *ptr;
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
int main()
{
    node *head = NULL;
    insert(head, 10, 1);
    insert(head, 20, 2);
    insert(head, 40, 3);
    insert(head, 50, 4);
    insert(head, 60, 3);
    //insertSorted(head, 30);
    //insertSorted(head, 95);
    print(head);
    node *head2 = Recursive_reverse(head);
    print(head2);
    return 0;
}