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
void delete_at_last(node * &head )
{
        if(head==NULL)
    {
      
        return ;
    }
    if(head->next==NULL)
    {
        head=NULL;   
        return ;
    }
    node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return ;
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
void merge_point(node * &first,node * & second)
{
    int first_size=size(first);
    int second_size=size(second);
    node *temp_first=first;
    node *temp_second=second;
    
    if(first_size>second_size)
    {
        while(first_size!=second_size)
        {
            cout<<"first_while";
            first_size--;
            temp_first=temp_first->next;
        }
    }
    else
    {
        while(first_size!=second_size)
        {
            
            second_size--;
            temp_second=temp_second->next;
        }
    }

    while(temp_first!=NULL)
    {
        if(temp_first->data==temp_second->data)
        {
            cout<<"element is found    ";
            cout<<temp_first->data<<endl;
            return ;
        }
        temp_first=temp_first->next;
        temp_second=temp_second->next;
    }
    return;
}
int main()
{
    node * head=NULL;
    insert_at_last(head,1);
    insert_at_last(head,2);
    insert_at_last(head,3);
    insert_at_last(head,4);
    insert_at_last(head,5);
    delete_at_last(head);
    display(head);
    // node* tail=NULL;
    // insert_at_last(tail,10);
    // insert_at_last(tail,9);
    // insert_at_last(tail,8);
    // insert_at_last(tail,7);
    // insert_at_last(tail,6);
    // insert_at_last(tail,4);
    // insert_at_last(tail,5);
    // display(head);
    // display(tail);
    // merge_point(head,tail);

    return 0;
}