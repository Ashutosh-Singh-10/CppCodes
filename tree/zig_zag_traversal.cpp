#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left=NULL;
    Node* right=NULL;
    int data;
    Node(int x)
    {
        data=x;
    }   
};

void zig_zag_traversal(Node * root,stack<int>* result,int level)
{

}

int main()
{

    Node * root=new Node(20);
    root->left=new Node(10);
    root->left->left=new Node(5);
    root->left->left->left=new Node(3);
    root->left->left->left->left=new Node(1);
    root->left->right=new Node(15);
    root->right=new Node(30);
    root->right->left=new Node(25);
    root->right->right=new Node(35);
    root->left->right->left=new Node(12);
    stack<int> * result;

    return 0;
}