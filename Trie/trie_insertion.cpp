#include <bits/stdc++.h>
using namespace std;
class Trie{
    public:
    Trie * child[26];
    bool isEnd;
    Trie()
    {
        isEnd=0;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};
void insertion(string s,int index,Trie * root)
{
    if(root==NULL)
    {

        cout<<"HII";
        return ;
    }
    if(s.size()==index)
    {
           root->isEnd=1;
           return ;
    }
    if(root->child[s[index]-'a']==NULL)
    {
        Trie * temp=new Trie();
        root->child[s[index]-'a']=temp;
    }
    
 
    insertion(s,index+1,root->child[s[index]-'a']);
    return ;
}
void traversal(Trie * root,string word)
{
    if(root==NULL) return ;
    string str;
    if(root->isEnd==1)
    {
        cout<<word<<endl;
    }
    for(int i=0;i<26;i++)
    {
        if(root->child[i]!=NULL)
        {
            str=word;
            str+='a'+i;
            traversal(root->child[i],str);
        }
    }
}

int main()
{
    float x=22;
    x/=7;
    double y=22;
    y/=7;
    cout<<x<<endl;
    
    cout<<y;

    // Trie * root=new Trie();

    // string arr[5]={"ashu","ashutosh","zack","batman","superman"};
    // for(int i=0;i<5;i++)
    // {
    //     insertion(arr[i],0,root);
    // }


    // cout<<"Half done ";
    // for(int i=0;i<26;i++)
    // {
    //     cout<<root->child[i];
    // }
    // traversal(root,"");

    return 0;
}

