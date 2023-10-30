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

int show_top_left_view(binary_tree * root,int level,int min_level)
{

    if(root==NULL)
    {
        return 0;
    }
    int left=show_top_left_view(root->left,level-1,min_level);
    if(level<min_level)
    {
        cout<<root->data<<"   ";
    }
    if(left<min_level)
    {
        min_level=left;
    }
    show_top_left_view(root->right,level+1,min_level);
    return level;
}
int show_top_right_view(binary_tree * root,int level,int min_level)
{

    if(root==NULL)
    {
        return 0;
    }
    // cout<<"data"<<root->data<<"     ";
    if(level>min_level)
    {
        cout<<root->data<<"   ";
        min_level=level;
    }
    
  
    int right=show_top_right_view(root->right,level+1,min_level);
    
      if(right>min_level)
    {
        min_level=right;
    }
    show_top_right_view(root->left,level-1,min_level);
    return level;
}

void show_top_view(binary_tree * root)
{
        show_top_left_view(root,0,0);
        cout<<root->data<<"  ";
    show_top_right_view(root,0,0);
    return;



}


int main()
{
                    //             1
                    // 2                      3
                    //                 4               5
                    //                         6
     binary_tree * root=new binary_tree(1);
    root->left=new binary_tree(2);
    // root->left->left=new binary_tree(4);
    // root->left->left->left=new binary_tree(8);
    // root->left->left->left->left=new binary_tree(9);
    // root->left->right=new binary_tree(5);
    
    root->right=new binary_tree(3);
    root->right->left=new binary_tree(4);
    root->right->right=new binary_tree(5);
    root->right->right->left=new binary_tree(6);
    show_top_view(root);
    


    return 0;
    
}

// struct Node
// {
//     int data;
//     Node * left;
//     Node * right;
// };


// int show_top_left_view(Node * root,int level,int min_level,vector<int> arr)
// {

//     if(root==NULL)
//     {
//         return 0;
//     }
//     int left=show_top_left_view(root->left,level-1,min_level,arr);
//     if(level<min_level)
//     {
//          arr.push_back(root->data);
//     }
//     if(left<min_level)
//     {
//         min_level=left;
//     }
//     show_top_left_view(root->right,level+1,min_level,arr);
//     return level;
// }
// int show_top_right_view(Node * root,int level,int min_level,vector<int> arr)
// {

//     if(root==NULL)
//     {
//         return 0;
//     }
//     int right=show_top_right_view(root->right,level+1,min_level,arr);
//     if(level>min_level)
//     {
//         arr.push_back(root->data);
//     }
//     if(right>min_level)
//     {
//         min_level=right;
//     }
//     show_top_right_view(root->left,level-1,min_level,arr);
//     return level;
// }

//     //Function to return a list of nodes visible from the top view 
//     //from left to right in Binary Tree.
//     vector<int> topView(Node *root)
//     {
//         vector<int> arr;
//               show_top_left_view(root,0,0,arr);
//         arr.push_back(root->data);
//     show_top_right_view(root,0,0,arr);
//     return arr;
        
//     }

// int main()
// {
//     Node * root;
//     root->data=1;
//     root->left=new Node;
//     root->left->data=2;
//     root->right->data=3;
//     vector<int> arr;
//     arr=topView(root);
//     for(auto i =arr.begin(); i!=arr.end();i++)
//     {
//         cout<<i;
//     }
//     return 0;
// }

