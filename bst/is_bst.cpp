#include <bits/stdc++.h>
using namespace std;
struct Node{
        int data;
    struct Node *left;
    struct Node *right;

    Node (int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

int is_bst(Node *root,int x,bool side,int min,int max)
{
    if(root==NULL)
    {
        return 1;
    }
if(!side)
{
    if(root->data>x || root->data<min || root->data>max)
    {
        return 0;
    }
}
else if(root->data<x || root->data<min || root->data>max)
 {      
    
     return  0;
 }
 if(side==0 && x>max) max=x;
 if(side==1 && x>min) min=x;

if(!is_bst(root->left,root->data,0,min,max))
{
    return 0;
}
return is_bst(root->right,root->data,1,min,max);
}


int main()
{
    int a=INT_MIN;
    Node * root=new Node(20);
    root->left=new Node(10);
    root->left->left=new Node(5);
    root->left->left->left=new Node(3);
    root->left->left->left->left=new Node(1);
    root->left->right=new Node(15);
    root->right=new Node(30);
    root->right->left=new Node(25);
    root->right->right=new Node(35);
    cout<<is_bst(root,INT_MAX,0,INT_MIN,INT_MAX);
    return 0;
}