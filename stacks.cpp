#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node * low;
    node(int x)
    {
        data=x;
        low=NULL;
    }

};
void push(node*& head,int x)
{
    node* n=new node(x);
    n->low=head;
    head=n;
}
int pop(node *&head)
{
    int x=head->data;
    head=head->low;
    return x;
}
void display(node*head)
{
    if(head==NULL)
    return ;
    while(head!=NULL)
    {
        cout<<head->data<<endl<<"^"<<endl;
        head=head->low;
    }
    cout<<"NULL"<<endl;
    return ;
}

int main()
{
    node *head=NULL;
    push(head,5);
    push(head,10);
    push(head,8);
    push(head,11);
    display(head);
    cout<<pop(head)<<endl;
    display(head);
}