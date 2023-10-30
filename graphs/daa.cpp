#include <bits/stdc++.h>
using namespace std;
class linkedlist
{
    public:
    int x;
    linkedlist* next;
    linkedlist(int a)
    {
        x=a;
        next=NULL;
    }

};
class Stack{
    public:
int sz=0;
linkedlist *head=NULL;
Stack(int x){
    head=new linkedlist(x);
    sz++;
}
bool isEmpty()
{
    return sz==0?1:0;
}
void pop(){
    head=head->next;
    
}
int push(int x)
{
    linkedlist * n=new linkedlist(x);
    n->next=head;
    head=n;
}
int size()
{
    return sz;
}
int top()
{
    return head->x;
}

};
int main()
{
    Stack * st=new Stack(5);
    cout<<st->top()<<endl;
    cout<<st->size()<<endl;
    

    
    return 0;
}
