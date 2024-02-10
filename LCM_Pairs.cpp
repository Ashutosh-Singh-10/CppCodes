#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve();
int main()
{
    solve();
    return 0;
  
}
void solve()
{
    ll n,temp;
    cin>>n;
    map<ll,ll>mp;
    ll ans=0;
    ll mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        mp[temp]++;
        mx=max(mx,temp);
     
    }
    vector<ll> vec(mx+1,0);
    for(auto &i:mp)
    {
        ans+=vec[i.first];
        ll x=i.first;
        ll y=x;
        while(x<=mx)
        {
            vec[x]+=i.second;
            x+=y;
        }
        // cout<<ans<<" ";
    }
    // cout<<endl;
// for(auto &i:mp)
// {
//     cout<<i.first<<" "<<i.second<<endl;
// }
    // for(auto &i:vec)
    // {
    //     cout<<i<<"  ";
    // }
    cout<<ans<<endl;

    

}

