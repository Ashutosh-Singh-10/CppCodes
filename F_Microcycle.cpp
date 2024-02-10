#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(p) p.begin(),p.end()
// #define endl '\n'
  
void solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
// 3644

ll dfs(vector<vector<pair<ll,ll>>> &gr, vector<ll> &visited,  vector<ll> &cy,ll cur,ll prev,ll & start,ll &end,ll &mn,ll curmin,ll idx,ll w)
{
    if(cy[cur])
    {
           if(w<mn)
        {
            mn=w;
            start=cur;
            end=prev;
        }
        return cy[cur];

    }
    if(visited[cur]) return LONG_LONG_MAX; 
    visited[cur]=1;
    cy[cur]=idx;
    ll mmm=LONG_LONG_MAX;
    for(auto &i:gr[cur])
    {
        if(i.first!=prev)
        {
            mmm =min(mmm,dfs(gr,visited,cy,i.first,cur, start ,end,mn,curmin,idx+1,i.second));
            
        }
        
    }
    if(mmm<cy[cur])
    {
        if(w<mn)
        {
            mn=w;
            start=cur;
            end=prev;
        }

    }   
    cy[cur]=0;
    return mmm;
    

}

bool path(vector<vector<pair<ll,ll>>> &gr,ll cur,ll prev,ll end,ll tot,vector<ll> &cy)
{
    if(cy[cur]==1) return 0;
    if(cur==end)
    {
        cout<<tot<<"\n";
        cout<<end+1<<" ";
        return 1 ;
    }
    cy[cur]=1;
    for(auto &i:gr[cur])
    {
        if(i.first!=prev)
        {
            if(path(gr,i.first,cur,end,tot+1,cy))
            {
                cout<<cur+1<<" ";
                return 1;
            }
        }
    }
return 0;
}
void solve()
{   
    int n,tot;

    cin>>n;
        cin>>tot;

        vector<vector<pair<ll,ll>>> gr(n);
        ll u,v,w;
    for(int i=0;i<tot;i++)
    {

    cin>>u>>v>>w;
        u--;
        v--;
        gr[u].push_back({v,w});
        gr[v].push_back({u,w});
  
    }


    vector<ll> visited(n+5,0);
    vector<ll> cy(n+5,0);
    ll mn=1e6;
    ll sz=0;
    ll start=0,end=0;

    ll curmin=mn;
    loop(i,0,n)
    {

        if(visited[i]==0)
        {
         
            dfs(gr,visited,cy,i,-1,start,end,mn,curmin,1,-1);
         visited[i]=1;
        }
        

    }

    cout<<mn<<" ";
    // vector<ll> cy(n,0);
    // if(start==end) cout<<"noooo";
    path(gr,start,end,end,1,cy);
    cout<<"\n";


        

  
}

    