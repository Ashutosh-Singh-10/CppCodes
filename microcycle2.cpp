#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(p) p.begin(),p.end()
#define endl '\n'
  
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
void join(vector<ll> & vec,ll x,ll y)
{
    vector<ll> a,b;
    while(vec[x]!=x)
    {
        a.push_back(x);
        x=vec[x];
    }
    while(vec[y]!=y)
    {
        b.push_back(y);
        y=vec[y];
    }
        for(auto &i:a)
        {
            vec[i]=y;
            


        }
        for(auto &i:b)
        {
            vec[i]=y;


        }
        vec[x]=y;
}
ll parent(vector<ll> & vec,ll x)
{
    while(vec[x]!=x)
    {
        x=vec[x];
    }
    return x;
}

bool path(vector<vector<pair<ll,ll>>> &gr,ll cur,ll prev,ll end,ll tot,vector<ll> &cy)
{
    if(cy[cur]==1) return 0;
    if(cur==end)
    {
        cout<<tot<<endl;
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

bool path(vector<vector<pair<ll,ll>>> &gr,ll cur,ll prev,ll end,vector<ll> &cy,ll tot)
{
    if(cy[cur]==1) return 0;
    if(cur==end)
    {
        cout<<tot<<endl;
        cout<<end+1<<" ";
        return 1 ;
    }
    cy[cur]=1;
    for(auto &i:gr[cur])
    {
        if(i.first!=prev)
        {
            if(path(gr,i.first,cur,end,cy,tot+1))
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

        ll u,v,w;
        multimap<ll,pair<ll,ll>> mp;
            vector<vector<pair<ll,ll>>> gr(n);

    for(int i=0;i<tot;i++)
    {

    cin>>u>>v>>w;
        u--;
        v--;
        // mp[w]={u,v};
        mp.insert({w,{u,v}});

        
             gr[u].push_back({v,w});
        gr[v].push_back({u,w});
   

    }
    auto it=mp.end();
    vector<ll> dsu;
    loop(i,0,n)
    {
        dsu.push_back(i);
    }
    ll start=0,end=0;
    w=1e7;
    while(1)
    {
        it--;
        if(parent(dsu,it->second.first)==parent(dsu,it->second.second))
        {
            w=min(w,it->first);
            start=it->second.first;
            end=it->second.second;
        }
        join(dsu,it->second.second,it->second.first);
        // for(auto &i:dsu) cout<<i<<" ";cout<<endl;

        if(it==mp.begin()) break;
    }
    cout<<w<<" ";;
    vector<ll> visited(n,0);
    path(gr,start,end,end,visited,1);
    cout<<endl;
  
        

  
}

    