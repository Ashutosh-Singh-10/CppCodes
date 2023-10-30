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
void binary_tree_traversal(Node *root)
{
   if(root==NULL)
   return;
   cout<<root->data<<endl;
   binary_tree_traversal(root->left);
   
   binary_tree_traversal(root->right);
   return;

    
}
void placing_the_value (Node * root,int data)
{
    if(data < root->data )
    {

        if(root->left==NULL)
        {
            root->left=new Node(data);
            return;
        }
        placing_the_value(root->left,data);
        return ;
    }
    if(root->right==NULL)
        {
            root->right=new Node(data);
            return;
        }
        placing_the_value(root->right,data);
        return ;
}
void build_bst(Node * root,int *arr,int n)
{
    root->data=arr[0];


       for(int i=1;i<n;i++)
    {      
       
        placing_the_value(root,arr[i]);
    }
return ;
}


int main()
{
    int arr[]={3,1,2,8,9,7};
 
    Node * root=new Node(2);
    build_bst(root,arr,sizeof(arr)/sizeof(int));


    binary_tree_traversal(root);
    return 0;
}