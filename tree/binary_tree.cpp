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
int main()
{
    binary_tree * root=new binary_tree(1);
    root->left=new binary_tree(0);
    root->right=new binary_tree(2);
    root->left->left=  new binary_tree(3);
    root->left->right= new binary_tree(4);
    root->right->left= new binary_tree(5);
    root->right->right=new binary_tree(6);
    binary_tree_traversal(root);


    return 0;
    //       1
    //   0      2
    // 3   4  5   6

    // 1 0 3 4 2 5 6

    // 3 0 4 1 5 2 6



}