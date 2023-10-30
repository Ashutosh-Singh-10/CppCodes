#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node *root)
{
    if (root == NULL)
        return;
   cout << root->data << "      ";
    preorder(root->left);
 
    preorder(root->right);
    return;
}
vector<Node *> result(int start, int end)
{
    vector<Node *> answer;
    Node *root = new Node(7);
    if (start == end)
    {
        root->data=start;
        answer.push_back(root);
        return answer;
    }
    else if (start > end)
    {answer.push_back(NULL);
        return answer;
    }
    Node *left = new Node(1);
    Node *right = new Node(1);
    for (int i = start; i <= end; i++)
    {
        root->data=i;
        vector <Node *> left_arr = result(start, i - 1);
        vector <Node *> right_arr = result(i + 1, end);
        for (int j = 0; j < left_arr.size(); j++)
        {
            left = left_arr[j];
            for (int k = 0; k < right_arr.size(); k++)
            {
                right = right_arr[k];
                Node * new_node=new Node(i);
                new_node->left = left;
                new_node->right = right;
                answer.push_back(new_node);
            }
        }
    }
    return answer;
}

int main()
{

    Node *root = new Node(0);
    vector<Node *> answer = result(0, 3);
    // cout << answer.size();
    cout<<endl;
    for (int i = 0; i < answer.size(); i++)
    {
        // cout << "NO";
        preorder(answer[i]);
        cout << endl;
    }
    return 0;
}
