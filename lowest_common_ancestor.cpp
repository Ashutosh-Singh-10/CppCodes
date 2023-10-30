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

binary_tree * LCA(binary_tree * node ,int a,int b)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->data==a || node->data==b)
    {
        return node;
    }
    
    binary_tree * left=LCA(node->left,a,b);
    binary_tree * right=LCA(node->right,a,b);
    if(left !=NULL && right!=NULL)
    {
        return node;
    }
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;

    }
    return NULL;
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
    cout<<LCA(root,5,8)->data;
    return 0;
}