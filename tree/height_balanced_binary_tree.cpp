#include <bits/stdc++.h>
using namespace std;

struct binary_tree
{   int data;
    struct binary_tree * left;
    struct binary_tree * right;
    binary_tree(int x){ 
            data=x;
            left=NULL;
            right=NULL;
    }
};
void binary_tree_traversal(binary_tree *root)
{
   if(root==NULL)
   return;
   cout<<root->data;
   binary_tree_traversal(root->left);
   
   binary_tree_traversal(root->right);
   return;
}

int check_balancing_of_binary_tree(binary_tree* root)
{ 

    if(root==NULL)
    {
        return 0;
    }
    int left=check_balancing_of_binary_tree(root->left);
    int right=check_balancing_of_binary_tree(root->right);
    int diff=left-right;
    if(left==-1 || right==-1 || !(diff<1 && diff>-1))
    {
        return -1;
    }
    else return 1+max(right,left);



}


int main()
{



       binary_tree * root=new binary_tree(1);
    root->left=new binary_tree(2);
    root->left->left=new binary_tree(4);
    // root->left->left->left=new binary_tree(8);
    // root->left->left->left->left=new binary_tree(9);
    root->left->right=new binary_tree(5);
    root->right=new binary_tree(3);
    root->right->left=new binary_tree(6);
    root->right->right=new binary_tree(7);
    cout<<check_balancing_of_binary_tree(root);

    
    return 0;
}