// //     #include <bits/stdc++.h>
// //     using namespace std;
// //     using std::cout;
// //     using std::cin;
// //     #define endl '\n'    
// //     #define ll long long
// //     #define loop(i,a,b) for(long long i=a;i<b;i++)
// //     #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
// //     #define all(p) p.begin(),p.end()
// //     #define pb(p) push_back(p);
// //     long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
// //     template<class T> using _pq = priority_queue<T>;
// //     template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
// //     template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
// //     template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}

// // int check(vector<int> &a,vector<int> &b)
// // {
// //     for(int i=0;i<a.size();i++)
// //     {
// //         if(a[i]>b[i]) return 1;
// //         if(a[i]<b[i]) return 0;
// //     }
// //     return 0;

// // }
// // void back(vector<int> &curr,vector<int> &ans,int idx,set<int> &st,vector<int>  &nums,int cost)
// // {
// //     if(st.size()==nums.size())
// //     {
// //         if(ans.size()==0)
// //         {
// //             ans=curr;
// //         }
// //      else    if(check(ans,curr))
// //         {
// //             ans=curr;
// //         }
// //         return ;
// //     }
// //     if(curr.size()==0)
// //     {
// //         for(int i=0;i<nums.size();i++)
// //         {
// //             curr.push_back(i);
// //             back(curr,ans,st,nums,0);
// //             curr.pop_back();
// //         }
// //     }
// //     else{

// //         for(int i=0;i<nums.size();i++)
// //         {
// //             if(st.count(i)==0)
// //             {
// //                 st.insert(i);
// //             cost+=abs(curr.back()-nums[i])
// //             curr.push_back(i);
// //             back(curr,ans,st,nums,cost);
// //             st.erase(i);
// //             curr.pop_back();

// //             }
// //         }

// //     }
// // }
// // class Solution {
// // public:
// //     vector<int> findPermutation(vector<int>& nums) {
// //         set<int> st;
// //         vector<int> curr,ans;

// //         back(curr,ans,st,nums,0);
// //         return ans;

        
        
// //     }
// // };

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int x=5; 
//     int y=(++x)+(++x)+(++x)+(++x)+(++x);
//     cout<<y<<" ";
//     cout<<x;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
    Tree * par=NULL;
    int val=0;
};
int main()
{
    int k,n;
    cin>>k>>n;
    int ans=0;
    if(n==-1)
    {
        cout<<-1;return 0;
    }

    int rt;cin>>rt;
    Tree *root=new Tree();
    int cnt=1;
    vector<Tree*> lfs;
    queue<Tree*> qu;
    qu.push(root);
    for(int i=1;i<=n;i++)
    {
            int tmp=0;
        for(int j=0;j<cnt;j++)
        {
            int x,y;
            cin>>x;cin>>y;
            if(x==-1 && y==-1)
            {
                if(qu.size())
                lfs.push_back(qu.front());
            }
            if(x!=-1)
            {
                Tree * tr=new Tree();
                tr->val=i;
                if(qu.size());
                tr->par=qu.front();
                qu.push(tr);
                tmp++;
                
            }
            if(y!=-1)
            {
                Tree * tr=new Tree();
                tr->val=i;
                if(qu.size())
                tr->par=qu.front();
                qu.push(tr);
                tmp++;
                
            }
            if(qu.size())
            qu.pop();


        }
            cnt=tmp;
        

    }
    while(qu.size())
    {
        lfs.push_back(qu.front());
        qu.pop();
    }
    for(int i=0;i<lfs.size();i++)
    {
        for(int j=i+1;j<lfs.size();j++)
        {
            
            auto a=lfs[i];
            auto b=lfs[j];
            int tot=0;
            while(a!=NULL && a->val>b->val)
            {
                tot++;
                a=a->par;
            }
            while(b!=NULL && a->val<b->val)
            {
                tot++;
                b=b->par;
            }
            if(a==NULL || b==NULL) continue;
            while(a!=b)
            {
                a=a->par;
                b=b->par;
                tot+=2;
                if(tot>k) break;
                if(a==b)
                {
                    ans++;
                    break;
                }

            }




        }
    }
    cout<<ans<<endl;




    return 0 ;
    
}