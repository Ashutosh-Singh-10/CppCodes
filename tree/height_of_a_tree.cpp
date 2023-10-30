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

int height_of_tree(binary_tree * root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height_of_tree(root->left),height_of_tree(root->right));

//                         1                                                            20
//             2                  3                                      10                      30

//         4       5           6    7                           5            15          25         35
//      8                                                   3               12       17 
// 9                                                     1                          16
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
    cout<<height_of_tree(root);


    return 0;

}