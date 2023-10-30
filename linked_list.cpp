#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }

};
void insert_at_last(node * &head,int y)
{
    node * n=new node(y);
    if(head==NULL)
    {
        head=n;
        return ;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    return;

}
void display(node * & head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    return ;
}
void insert_at_head(node * & head,int x)
{
    node *n=new node(x);
    n->next=head;
    head=n;
    return ;
}
void insert_after(node* &head,int x,int y)
{
    node * temp=head;
    if(head==NULL)
    {
        return;
    }
    while(temp->data!=x)
    {
        temp=temp->next;
    }
    node* n=new node(y);
    n->next=temp->next;
    temp->next=n;
    return ;

}
void reverse_list(node* & head)
{
    node * prev=head;
    node * curr=head;
    node * upcom=head->next;
    prev->next=NULL;
    int n=0;
    while(upcom!=NULL )
    {
        if (n==10)
        return ;
        curr=upcom;
        upcom=upcom->next;
        curr->next=prev;
        prev=curr;
        
        n++;
    }
    head=curr;
}
int size(node* &head)
{
    int count=0;
    node* temp=head;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int reverse_k_node(node * &head,int k)
{
    node * temp=head;
    int n=size(head)-k;
    if (n<0) {
        cout<<"ask nodes for reverse are more than size of list"<<endl;
        return 0;
    }
    while(n--)
    {
        temp=temp->next;
    }
    
    node* prev=temp->next;
    node* curr=temp->next;
    node* upcom=temp->next->next;
    curr->next=NULL;
    while(upcom!=NULL)
    {
        curr=upcom;
        upcom=upcom->next;
        curr->next=prev;
        prev=curr;
    }
    temp->next=prev;
    return 1;

}
int main()
{
    node *head=NULL;
    insert_at_last(head,11);
    insert_at_last(head,1);
    insert_at_last(head,2);
    insert_at_last(head,3);
    display(head);
    display(head);
    insert_at_head(head,-1);
    display(head);
    insert_after(head,2,10);
    display(head);
    cout<<"reverse list is here";
    reverse_list(head);
    display(head);
    if(reverse_k_node(head,10))
    {
    cout<<"half reverse list is here";
    display(head);
    }
    return 0;
}