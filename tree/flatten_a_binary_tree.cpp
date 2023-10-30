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

binary_tree * flat_the_tree(binary_tree * root)
{
         if(root==NULL)
    {
        return NULL;
    }
    binary_tree* left=flat_the_tree(root->left);
    binary_tree* right=flat_the_tree(root->right);
    if(left==NULL  && right==NULL)
    {
        return root;
    }
  if(left==NULL)
  {
    
    return right;
  }
  if( right==NULL) 
  {
      root->right=root->left;
    root->left=NULL;
    return left ;
  } 
  left->right=root->right;
   root->right=root->left;
   root->left =NULL;
   return right;


}


int main()
{

        binary_tree * root=new binary_tree(1);
    root->left=new binary_tree(2);
    root->left->left=new binary_tree(4);
    root->left->left->left=new binary_tree(8);
    root->left->left->left->left=new binary_tree(9);
    root->left->right=new binary_tree(5);
    root->right=new binary_tree(3);
    root->right->left=new binary_tree(6);
    root->right->right=new binary_tree(7);
    flat_the_tree(root);
    binary_tree_traversal(root);

    return 0;
}