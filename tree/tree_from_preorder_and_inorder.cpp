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

    //         1
    //     2       3
    // 4   5    6    7    
}

// binary_tree* building_tree(int preorder[],int inorder[],int index,int n,int start_ptr, int end_ptr){
//     if(index==n){
//         return NULL;
//     }
//     if(start_ptr>=n-1 || end_ptr<=0 || start_ptr>=end_ptr){
//         return NULL;
//     }
//     cout<<"before_binary_tree"<<endl;
//     binary_tree * root=new binary_tree(preorder[index]);
//     cout<<preorder[index];
//     int point;
//     for(int i=0;i<n;i++)
//     {
//         if(preorder[index]==inorder[i])
//         point=i;
//     }
//     root->left=building_tree(preorder,inorder,++index,n,start_ptr,point-1);
//     if(root->left==NULL)
//     index--;

//     root->right=building_tree(preorder,inorder,++index,n,++point,end_ptr);
//     if(root->right==NULL)
//     index--;
//     return root;
// }



binary_tree * building_tree(int preorder[],int inorder[], int *index,int n ,int start_ptr,int end_ptr){
    int point;
    if(start_ptr>end_ptr || *index>n )
    {
        cout<<"                         termination point"<<endl;
        return NULL;
    }
    for(int i=start_ptr;i<=end_ptr;i++)
    {
            cout<<"begins"<<"           "<<*index<<endl;
        if(preorder[*index]==inorder[i])
        {
            binary_tree *root=new binary_tree(inorder[i]);
            cout<<inorder[i];
            cout<<"         before ->"<<preorder[*index];
            *index+=1;
            cout<<"        after-> "<<preorder[*index];
            root->left=building_tree(preorder,inorder,index,n,start_ptr,i-1);
            root->right=building_tree(preorder,inorder,index,n,i+1,end_ptr);
            return root;
            
        }
    }
    return NULL;
}

int main()
{
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};
    int k=0;
    binary_tree *my_tree=building_tree(preorder,inorder,&k,7,0,6);
    binary_tree_traversal(my_tree);
    // cout<<"The tree is as follows:"<<endl;
    // cout<<my_tree->data;
    // cout<<my_tree->left->data;
    // cout<<my_tree->left->data;
    // cout<<"half is completed"<<endl;
    // cout<<my_tree->right->data;
    // // cout<<my_tree->right->left->data;
    // cout<<my_tree->right->data;
    // cout<<my_tree->right->right->data;





    return 0;
}