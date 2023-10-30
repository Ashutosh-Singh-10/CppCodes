#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left=NULL;
    struct Node *right=NULL;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
struct  info
{
    Node *node ;
    int max_element;
    int min_element;
    int height;
    int isbst;
};
info largest_bst(Node * root)
{
    info left;
    info right;
    if(root==NULL)
    {
        left.node=NULL;     left.max_element=INT_MIN;    left.min_element=INT_MAX;  left.isbst=1; left.height=0;
     return left;   
    }
    
    left=largest_bst(root->left);
    right=largest_bst(root->right);

        if(left.isbst==1 && right.isbst==1)
        {
            cout<<"HII";
            if(root->data >left.max_element && root->data < right.min_element)
            {
                cout<<"hello"<<endl;
                left.node=root;
                left.height=max(left.height,right.height)+1;
                left.max_element=max(max(left.max_element,right.max_element),root->data);
                left.min_element=min(min(left.min_element,right.min_element),root->data);
                return left;
            }

        }
        left.isbst=0;
        right.isbst=0;
       if(left.height >right.height)
       {
        return left;
       }
       return right;

}


int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->left->left = new Node(5);
    root->left->left->left = new Node(3);
    root->left->left->left->left = new Node(1);
    root->left->right = new Node(15);
    root->right = new Node(30);
    root->right->left = new Node(25);
    root->right->right = new Node(35);
    info answer=largest_bst(root);
    // cout<<answer.max<<endl<<answer.min<<endl<<answer.height<<endl<<answer.isbst;
    cout<<answer.height;

    return 0;
}
