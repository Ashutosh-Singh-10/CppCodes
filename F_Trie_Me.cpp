    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
    #define endl '\n'    
    #define ll long long
    #define loop(i,a,b) for(long long i=a;i<b;i++)
    #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
    #define all(p) p.begin(),p.end()
    #define pb(p) push_back(p);
    long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
    template<class T> using _pq = priority_queue<T>;
    template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
    template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
    template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}


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


void solve(ll tc);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    loop(i,0,t)
    {
        solve(i);
    }
    
    return 0;
}
void solve(ll tc)
{
    ll n;cin>>n;
}
