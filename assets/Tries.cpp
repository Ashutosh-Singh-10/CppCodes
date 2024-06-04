#include<bits/stdc++.h>
using namespace std;


// Function Available  :- 
// Insertion , 
// PrefixMatch , 
// Full string Matching, 
// Print all words, 
// Deletion 

char trieBase='a';
long long trieSize=26;
class Trie{public:
    vector<Trie *> child;
    long long isEnd,cnt;
    Trie()
    {
        isEnd=0;
        cnt=0;
        for(long long i=0;i<trieSize;i++) child.push_back(NULL);
    }
};
// insert a word to trie
void insertion(Trie * root,string &s,long long index=0)
{
    root->cnt++;
    if(index==s.length())
    {
        root->isEnd++;   
        return ;
    }
    if(root->child[s[index]-trieBase]==NULL)
    {
        root->child[s[index]-trieBase]=new Trie();
    }
    insertion(root->child[s[index]-trieBase],s,index+1);
}
// Delete string s one time if already present
long long trieDeletion(Trie * root,string &s,long long index=0)
{
    if(index==s.length())
    {
        long long occurence=1;
        // for deleting all occurence of s 
        // occurence=root->isEnd;
        // root->isEnd=0 ;
        // root->cnt-=occurence;
        // return occurence
        if(root->isEnd>0)
        {

        root->isEnd--;   
        root->cnt--;
        } 
        return 1;
    }
    if(root->child[s[index]-trieBase]==NULL)    return 0;
    long long occurence=trieDeletion(root->child[s[index]-trieBase],s,index+1);
    root->cnt-=occurence;
    return occurence;
}
// Use to print all word of Trie
void getAll(Trie * root,string s="")
{
    if(root->isEnd)    cout<<s<<endl;
    for(int i=0;i<26;i++)
    {
        if(root->child[i]!=NULL)
        {
            char ch=trieBase+i;  
            getAll(root->child[i],s+ch);
        }
    }
}
// function check how many words equal to s exist 
long long fullSearch(Trie * root,string &s,int index=0)
{   
    if(index==s.length())return root->isEnd;
    if(root->child[s[index]-trieBase]==NULL)return 0;
    return fullSearch(root->child[s[index]-trieBase],s,index+1);

}
// function check how many words contain s as their prefix
long long isPrefix(Trie * root,string &s, int index=0)
{

    if(index==s.length())    return root->cnt;
    if(root->child[s[index]-trieBase]==NULL) return 0;   
    return isPrefix(root->child[s[index]-trieBase],s,index+1);
}



int main()
{
    Trie * root=new Trie();
    string word="hii";
    insertion(root,word);
    word="nooo";
    insertion(root,word);
    word="hello";
    insertion(root,word);
    word="hell";
    insertion(root,word);
    insertion(root,word);
    word="he";
    insertion(root,word);
    word="help";
    insertion(root,word);
    word="helly";
    insertion(root,word);
    insertion(root,word);
    insertion(root,word);
    insertion(root,word);
   
    // cout<<"JO";
    getAll(root);
    
    word="hel";
    cout<<isPrefix(root,word)<<endl;
    word="helly";
    cout<<fullSearch(root,word)<<endl;
    trieDeletion(root,word);
    trieDeletion(root,word);
    trieDeletion(root,word);
    cout<<fullSearch(root,word)<<endl;
    word="hel";
    cout<<isPrefix(root,word)<<endl;

    // word="hellyy";
    // cout<<isPrefix(root,word)<<endl;
    
    // word="k";
    // cout<<isPrefix(root,word)<<endl;
    // word="helly";
    // cout<<fullSearch(root,word)<<endl;
    // word="hell";
    // cout<<fullSearch(root,word)<<endl;
    // word="hel";;
    // cout<<fullSearch(root,word)<<endl;
    // word="hello";;
    // cout<<fullSearch(root,word)<<endl;
    // word="noo";;
    // cout<<fullSearch(root,word)<<endl;
    // word="nooo";;
    // cout<<fullSearch(root,word)<<endl;
    // word="n";;
    // cout<<fullSearch(root,word)<<endl;
    // word="niibhai";;
    // cout<<fullSearch(root,word)<<endl;
    return 0;
}




