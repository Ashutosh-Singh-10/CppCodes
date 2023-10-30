#include <bits/stdc++.h>
using namespace std;

class queue_list
{
    public:
    struct linked_list{
        int data;
        linked_list * next=NULL;
        linked_list(int x)
        {
         data=x;
        }

    };
    linked_list *start=NULL;
    linked_list *end;
    void add(int x)
    {
        if(start==NULL) 
        {
            start=new linked_list(x);
            end=start;
            return ;
        }
        linked_list * temp=new linked_list(x);
        end->next=temp;
        end=temp;
        
    }
    void show()
    {
        linked_list * temp=start;
        while(temp!=NULL)
        {
            cout<<temp->data<<"   ";
            temp=temp->next;

        }
    }
    int pop()
    {
        if(start==NULL) return -1;
        linked_list* temp=start;
        start=start->next;
        return temp->data;
    }


};
int main()
{

    class queue_list my_queue;
    my_queue.add(5);
    my_queue.add(10);
    my_queue.add(7);
    my_queue.add(13);
    my_queue.show();
    cout<<endl;
    cout<<my_queue.pop();

    return 0;
}