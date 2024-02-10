#include <bits/stdc++.h>
using namespace std;
class Trie{
    public:
    Trie * child[26];
    bool isEnd;
    int cnt;
    Trie()
    {
        isEnd=0;
        cnt=0;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};
void insertion(Trie * root,string &s,int index=0)
{
    if(index==s.length())
    {
        root->isEnd=true;   
        return ;
    }
    if(root->child[s[index]-'a']==NULL)
    {
        root->cnt++;
        root->child[s[index]-'a']=new Trie();
    }
    insertion(root->child[s[index]-'a'],s,index+1);
    return ;  
}
void getAll(Trie * root,string s="")
{
    if(root->isEnd)
    {
        cout<<s<<endl;
    }
    for(int i=0;i<26;i++)
    {
        if(root->child[i]!=NULL)
        {
            char ch='a'+i;
            getAll(root->child[i],s+ch);
        }
    }

}
bool searchAword(Trie * root,string &s,int index=0)
{
    if(index==s.length())
    {
        if(root->isEnd) return 1;
        return 0 ;
    }
    if(root->child[s[index]-'a']==NULL)
    {
        return 0;
    }
    return searchAword(root->child[s[index]-'a'],s,index+1);

}
bool startWith(Trie * root,string &s,int index=0)
{
    if(index==s.length())
    {
        return 0 ;
    }
    if(root->child[s[index]-'a']==NULL)
    {
        return 0;
    }
    return searchAword(root->child[s[index]-'a'],s,index+1);

}

int main()
{
    Trie * root=new Trie();
    string word="hii";
    
    // cout<<"ooooO";
    insertion(root,word);
    // cout<<"ooooO";
    word="nooo";
    insertion(root,word);
    word="hello";
    insertion(root,word);
    word="hell";
    insertion(root,word);
    word="he";
    insertion(root,word);
    word="help";
    insertion(root,word);
    word="helly";
    insertion(root,word);
    // cout<<"JO";
    getAll(root);
    
    word="helly";
    cout<<searchAword(root,word)<<endl;
    word="hell";
    cout<<searchAword(root,word)<<endl;
    word="hel";;
    cout<<searchAword(root,word)<<endl;
    word="hello";;
    cout<<searchAword(root,word)<<endl;
    word="noo";;
    cout<<searchAword(root,word)<<endl;
    word="nooo";;
    cout<<searchAword(root,word)<<endl;
    word="n";;
    cout<<searchAword(root,word)<<endl;
    word="niibhai";;
    cout<<searchAword(root,word)<<endl;
    return 0;
}