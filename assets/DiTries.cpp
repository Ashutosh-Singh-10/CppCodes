#include<bits/stdc++.h>
using namespace std;


// Function Available  :- 
// Insertion , 
// PrefixMatch , 
// Full string Matching, 
// Print all words, 
// Deletion 
long long DiTrieBase=130;
long long TrieOperatingFunction(char a,char b)
{
 return a*DiTrieBase+b;
}
class DiTrie{public:
    map<long long,DiTrie*> child;
    long long isEnd,cnt;
    DiTrie()
    {
        isEnd=0;
        cnt=0;
    }
};
// insert a word to trie
void insertion(DiTrie* root,string &s,long long index=0)
{
    root->cnt++;
    if(index==s.length())
    {
        root->isEnd++;   
        return ;
    }
    long long childWeight=TrieOperatingFunction(s[index],s[s.length()-1-index]);
    if(root->child.count(childWeight)==0)
    {
        root->child[childWeight]=new DiTrie();
    }
    insertion(root->child[childWeight],s,index+1);
}
// Delete string s one time if already present
long long trieDeletion(DiTrie * root,string &s,long long index=0)
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
    long long childWeight=TrieOperatingFunction(s[index],s[s.length()-1-index]);
    if(root->child.count(childWeight)==0)    return 0;
    long long occurence=trieDeletion(root->child[childWeight],s,index+1);
    root->cnt-=occurence;
    return occurence;
}
// Use to print all word of Trie
void getAll(DiTrie* root,string s="")
{
    if(root->isEnd)    cout<<s<<endl;
    
    for(auto &i:root->child)
    {
        s.push_back(char(i.first/DiTrieBase));
        getAll(i.second,s);
        s.pop_back();
    }
    
}
// function check how many words equal to s exist 
long long fullSearch(DiTrie* root,string &s,int index=0)
{   
    if(index==s.length())return root->isEnd;
    long long childWeight=TrieOperatingFunction(s[index],s[s.length()-1-index]);
    if(root->child.count(childWeight)==0) return 0;
    return fullSearch(root->child[childWeight],s,index+1);
}
// function check how many words contain s as their prefix
long long isPrefix(DiTrie* root,string &s, int index=0)
{
    if(index==s.length())    return root->cnt;
    long long childWeight=TrieOperatingFunction(s[index],s[s.length()-1-index]);
    if(root->child.count(childWeight)==0) return 0;   
    return isPrefix(root->child[childWeight],s,index+1);
}



int main()
{
    DiTrie * root=new DiTrie();
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
    
    word="helly";
    cout<<fullSearch(root,word)<<endl;
    trieDeletion(root,word);
    cout<<fullSearch(root,word)<<endl;

    cout<<isPrefix(root,word)<<endl;
    word="hellyy";
    cout<<isPrefix(root,word)<<endl;
    
    word="k";
    cout<<isPrefix(root,word)<<endl;
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

