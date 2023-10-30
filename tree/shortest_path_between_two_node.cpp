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

int shortest_path(binary_tree * root,int a ,int b)
{
    if(root==0)
    {
        return 0;
    }
    int left=shortest_path(root->left,a,b);
    if(left<0)
    {
        return left;
    }
    int right=shortest_path(root->right,a,b);
    if(right<0)
    {
        return right;
    }   
    if(root->data==a || root->data==b)
    {
        if(right>0)
        {
            return -right;
        }
        if(left>0)
        {
            return -left;
        }
        return 1;
    }
    if(right>0 && left>0)
    {
        return -(left+right);
    }
    else if(right>0)
    {
        return right+1;
    }
    else if(left>0)
    {
        return left+1;
    }
    return 0;
    
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
    cout<<shortest_path(root,8,6);
return 0;
}