#include <bits/stdc++.h>
using namespace std;
struct Node
{   int data;
    struct Node * left;
    struct Node * right;
    Node(int x){
            data=x;
            left=NULL;
            right=NULL;
    }
};
void Node_traversal(Node *root)
{
   if(root==NULL)
   return;
   cout<<root->data<<"   ";
   Node_traversal(root->left);

   Node_traversal(root->right);
   return;
}
void shifting_node(Node* root,Node* insert_root,int side)
{
    if(side==1)
    {
        root->right=insert_root;
        return;
    }
    root->left=insert_root;
    return ;

}
void delete_the_element(Node * root,Node * target,int side)
{
    if(target->right ==NULL && target->left==NULL)
    {
        if(side==1)
        {
            root->right=NULL;
        }
        else root->left=NULL;
        delete target;
        return;
    }
    else if(target->right==NULL)
    {
        shifting_node(root,target->left,side);
        delete target;
        return ;
    }
    else if(target->left==NULL)
    {
        shifting_node(root,target->right,side);
        delete target;
        return ;
    }
    else{

        shifting_node(root,target->right,side);
        Node * target_right=target->right;
        Node * temp=target->left;
        target->left=target_right->left;
        target->right=target_right->right;
        target_right->right=target;

        target_right->left=temp;
        delete_the_element(target_right,target,1);
        return ;

    }
    return ;
}
void finding_the_element(Node * root,int k)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->right)
    {
        if(root->right->data==k)
        {
            delete_the_element(root,root->right,1);
            return ;
        }
        finding_the_element(root->right,k);
    }
    if(root->left)
    {
        if(root->left->data==k)
        {
            delete_the_element(root,root->left,0);
            return ;
        }
        finding_the_element(root->left,k);
    }

    return ;
}

int main()
{ Node * root=new Node(20);
    root->left=new Node(10);
    root->left->left=new Node(5);
    root->left->left->left=new Node(3);
    root->left->left->left->left=new Node(1);
    root->left->right=new Node(15);
    root->right=new Node(30);
    root->right->left=new Node(25);
    root->right->right=new Node(35);
    root->left->right->left=new Node(12);
    // root->left->right->right=new Node(17);
    // root->left->right->right->left=new Node(16);
    finding_the_element(root,10);
Node_traversal(root);
cout<<endl<<endl<<endl;

    // Node_traversal(root);
    cout<<root->left->data<<endl;
    cout<<root->left->left->data<<endl;
    cout<<root->left->right->data<<endl;

    return 0 ;
}

