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
void insert_at_head(node * &head,int x)
{
    node *n=new node(x);
    n->next=head;
    head=n;
    return ;
}
void cycle_detection(node * &head)
{
    node* rabbit=head;
    node * turtle=head;
    
    while(rabbit!=NULL)
    {
        if(rabbit->next==NULL)
            return;
        rabbit=rabbit->next->next;
        turtle=turtle->next;
        if(turtle->next->data==rabbit->next->data)
        {
            turtle->next=NULL;
            return;
        }
        
    }
}
int main()
{
    class node *head=NULL;
    class node* temp=new node(59);
    insert_at_last(head,91);
    head->next=temp;

    insert_at_head(head,11);
    insert_at_head(head,17);
    insert_at_head(head,31);
    display(head);
    display(temp);
    temp->next=head;
    
    insert_at_head(temp,111);
    insert_at_head(temp,199);
    cycle_detection(temp);
    display(temp);
    return 0;
}