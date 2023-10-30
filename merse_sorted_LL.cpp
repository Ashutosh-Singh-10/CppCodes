#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void insert_at_last(node *&head, int y)
{
    node *n = new node(y);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    return;
}
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}
void insert_at_head(node *&head, int x)
{
    node *n = new node(x);
    n->next = head;
    head = n;
    return;
}
int size(node *&head)
{
    int count = 0;
    node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insert_node_at_end(node *&first, node *&second)
{
    node *temp = second;
    while (temp != NULL)
    {
        first->next = new node(temp->data);
        temp = temp->next;
    }
    return;
}
void insert_node(node *&temp, int data)
{
    node *n = new node(data);
    if (temp == NULL)
    {
        temp = n;
        return;
    }
    temp->next = n;
    return;
}
void merge_sorted(node *&first, node *&second, node *&ans)
{
    node* n=NULL;
    node *temp = NULL;
    ans = temp;
    node *first_node = first;
    node *second_node = second;
    while (1)
    {
        if (second_node == NULL)
        {
            cout<<"yes"<<endl;
            insert_node_at_end(temp, first);
            return;
        }
        else if (first_node == NULL)
        {
            cout<<"yes"<<endl;
            insert_node_at_end(temp, second);
            return;
        }
        cout<<"something has happens"<<endl;
        if (first_node->data > second_node->data)
        {
            n = new node(second_node->data);
            second_node = second_node->next;
        }
        else{
            n=new node(first_node->data);
            first=first->next;
        }
        cout<<n->data<<"    ";
        if (temp == NULL)
        {
            temp = n;
            ans=temp;
        }
        else
        {
            temp->next = n;
        }
    }
    cout<<"end";

}
int main()
{
    node* ans=NULL;
    node *first=NULL;
    insert_at_head(first,100);
    insert_at_head(first,13);
    insert_at_head(first,5);
    insert_at_head(first,3);
    insert_at_head(first,1);
    node *second=NULL;
    insert_at_last(second,2);
    insert_at_last(second,6);
    insert_at_last(second,9);
    insert_at_last(second,21);
    insert_at_last(second,88);
    display(first);
    merge_sorted(first,second,ans);
    display(ans);
    display(first);
    display(second);
    return 0;
}

