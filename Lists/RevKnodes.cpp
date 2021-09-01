#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void print(node *&head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
node* revKnode(node* &head,int k){
    node* preptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count=0;
    while(count<k && currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = preptr;
        preptr = currptr;
        currptr = nextptr;
        count++;
    }
    //Recursive Call for rest of LL
    if(nextptr!=NULL){
        head->next = revKnode(nextptr,k);
    }
    return preptr;

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
    node *head2 = revKnode(head,2);
    print(head2);
    return 0;
}