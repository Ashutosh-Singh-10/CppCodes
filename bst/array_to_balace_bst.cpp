#include <bits/stdc++.h>
using namespace std;

struct Node
{
    public:
    int data;
    struct Node *left=NULL;
    struct Node *right=NULL;

Node()
{
    left=NULL;
    right=NULL;

}
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node *root)
{
   if(root==NULL)
   return;
   cout<<root->data<<"      ";
   preorder(root->left);
   
   preorder(root->right);
   return;
}

int building_bst(Node *  root,int arr[],int start,int end)
{
    if(start>end )
    {
        root=NULL;  
        return 0;
    }
    int k=(start+end)/2;
    // cout<<k<<"   ";
    // cout<<arr[k];    
    root->data=arr[k];
    
    root->left=new Node();
    root->right=new Node();
   if(! building_bst(root->left,arr,start,k-1)) root->left=NULL;
    if(!building_bst(root->right,arr,k+1,end)) root->right=NULL;
 
    return 1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    Node *root=new Node(3);
    building_bst(root,arr,0,6);
    // cout<<root->data;
    preorder(root);


}