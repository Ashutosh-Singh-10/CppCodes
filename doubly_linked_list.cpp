#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        next=NULL;
        prev=NULL;
        data=x;
    }
};
void double_display(node * & head)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
    return ;
}
void display(node *&head)
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
void insert_at_last(node * &head,int x)
{
    node *n=new node(x);
    if(head==NULL)
    {
        head=n;
        cout<<"head shot";
        return;
    }
    node * temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=n;
    n->prev=temp;
    n->next=NULL;
}

void insert_at_head(node * &head,int x)
{
    node *n=new node(x);
    if(head==NULL)
    {
        head=n;
        return ;
    }
    n->next=head;
    head->prev=n;
    head=n;
    return ;
    
}
void deletion(node * &head,int x)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            return;
        }
        temp=temp->next;
    }
    return;
}
int main()
{
    node * head=NULL;
    insert_at_last(head,4);
    insert_at_last(head,18);
    insert_at_last(head,11);
    insert_at_last(head,55);
    insert_at_head(head,555);
    display(head);
    deletion(head,11);
    display(head);


    return 0;
}