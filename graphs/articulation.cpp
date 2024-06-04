#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll algo(vector<vector<ll>> & graph,vector<ll> &vis,vector<ll> &index,ll curr,ll prevll &in,vector<ll> & ans)
{
   

}
int main()
{
    ll n;cin>>n;
    vector<ll> index(n,0);
    vector<ll> vis(n,0);
    vector<ll> ans;
    vector<vector<ll>> gr(n);

    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);


    }
 
    ll cnt=0;
    ll p=0;
    vis[p]=1;
    ll in=1;
    for(ll i=0;i<gr[p].size();i++)
    {

        if(vis[gr[p][i]]==0)
        {
            cnt++;
            algo(gr,vis,index,gr[p][i],in,ans,p);


        }
        
    }
    cout<<endl; 
    for(auto &i:vis)
    {
        cout<<i<<"  ";
    }cout<<endl;
    cout<<"The cnt is "<<cnt<<endl;
    if(cnt>1)
    {
        ans.push_back(p);
    }
    for(auto &i:ans)
    {
        cout<<i<<"  ";
    }
    cout<<"HII";
    




    return 0;
}