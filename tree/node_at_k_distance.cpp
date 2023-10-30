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
void find_the_element(binary_tree * root,int k)
{
    if(root==NULL) return ;
    if(k==0) 
    {
        cout<<root->data;
        return ;
    }
    k--;
    find_the_element(root->left,k);
    find_the_element(root->right,k);
    return ;
}
int node_at_k_distance(binary_tree * root,int k,int num)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==num)
    {
        find_the_element(root,k);
        return 1;
    }
    int distance=node_at_k_distance(root->left,k,num);
    if(distance==-1)
    {
        return -1;
    }
    else if(distance==k)
    {
        cout<<root->data;
        return -1;
    }
    else if(distance>0)
    {
        find_the_element(root->right,k-distance-1);
        return distance+1;
    }
    distance=node_at_k_distance(root->right,k,num);
        if(distance==-1)
    {
        return -1;
    }
    else if(distance==k)
    {
        cout<<root->data;
        return -1;
    }
    else if(distance>0)
    {
        find_the_element(root->left,k-distance-1);
        return distance+1;
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
    node_at_k_distance(root,4,5);
    return 0;
}