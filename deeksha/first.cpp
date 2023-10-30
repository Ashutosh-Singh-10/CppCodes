#include <bits/stdc++.h>
using namespace std;
void algo(vector<vector<pair<int,int>>> &graph,int  curr,vector<int> &mp,vector<int>&w,int val)
{
    if(val<mp[curr])
    {
        mp[curr]=val;
        for(auto &i:graph[curr])
        {
            algo(graph,i.first,mp,w,i.second);
        }
    }
    else
    {
        return ;
    }
    return;
    


}
int main()
{
    int n,a,b,c,temp,d;
    cin>>n;
    cin>>d;
    vector<vector
    <pair<int,int>>
    > vec(n);
    vector<int> mp(n,INT_MAX);
    vector<int> w;
    priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        w.push_back(temp);
        pq.push({temp,i});
    }
    for(int i=0;i<d;i++)
    {
        cin>>a;
        cin>>b;
        cin>>c;
        cout<<"HII";
        vec[a-1].push_back({b-1,c});
        vec[b-1].push_back({a-1,c});
        
    }
    while(pq.size())
    {
        temp=pq.top().second;
        algo(vec,temp,mp,w,pq.top().first);
        pq.pop();
    }
    cout<<"NOO";
    int ans=0;
    for(auto &i:mp)
    {
        cout<<i<<"  ";
        ans+=i;
    }
    cout<<ans;
    return 0;






}





// #include <bits/stdc++.h>
// using namespace std;
// int prize(vector<int> & arr)
// {
//     int a=arr.size();
//     if(a==0) return 0;
//     if(a==1) return arr[0];
//     vector<int> dp(a,0);
//     dp[0]=arr[0];
//     dp[1]=max(arr[0],arr[1]);
//     for(int i=2;i<a;++i)
//     {
//         dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
//     }
//     return dp[a-1];
// }
//     int main()
//     {
//         int n,temp;
//         cin>>n;
//         vector<int> nxt,prev;
//         for(int i=0;i<n;i++)
//         {
//             cin>>temp;
//             nxt.push_back(temp);
//             prev.push_back(temp);
//         }
// cout<<prize(nxt);
//         // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>  >pq;
//         // for(int i=0;i<n;i++)
//         // {
//         //     pq.push({nxt[i],i});
//         // }
//         // int curr=0,in;
//         // int ans=0;
//         // while(pq.size())
//         // {
//         //     curr=pq.top().first;
//         //     in=pq.top().second;
//         //     pq.pop();
//         //     if(in)
//         //     {
//         //         curr*=prev[in-1];
//         //         prev[in]=prev[in-1];
//         //     }
//         //     if(in<n-1)
//         //     {
//         //         curr*=nxt[in+1];
//         //         nxt[curr]=nxt[in+1];
//         //     }
//         //     ans+=curr;
//         // }
//         // cout<<ans;
//         return 0;
        
  
        

//     }