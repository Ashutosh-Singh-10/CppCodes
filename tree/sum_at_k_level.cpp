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

int sum_at_k_level(int k,binary_tree* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(k==1)
    {
        return root->data;
    }
    k--;
    return sum_at_k_level(k,root->left)+sum_at_k_level(k,root->right);
    


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
    cout<<sum_at_k_level(3,root);


    return 0;

}