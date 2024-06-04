    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
        #ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
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
    ll n,m,k;cin>>n>>m>>k;
    map<ll,pair<ll,ll>> mp;
    loop(i,0,k)
    {
        ll a,b;cin>>a>>b;
        a--;b--;
        if(mp.count(b))
        {
            if(mp[b].first<a)
            {
                mp[b]={a,i};
            }
            
        }
        else mp[b]={a,i};
    }
    ll cmx=-1;
    set<ll> ans;
    // loop(i,0,m)
    // {
    //     if(mp.count(i))
    //     {
    //         bb=max(mp[i].first+1,bb);
    //     }
    //     alice+=n-bb;


    // }
    ll bb=0;
    ll alice=0;
    ll al=0;
    // dbg(mp);
    for(auto   &[a,b]:mp)
    {
        

        // if(b.first>bb)
        alice+=(a-al)*(n-bb);

            bb=max(b.first+1,bb);
            al=a;
        // dbg(b.first);
        // dbg(alice);
    }
    // dbg("    ");
    // cout<<alice<<"->";
    alice+=(m-al)*(n-bb);

    
    for(auto &[a,b]:mp)
    {
        auto c=b.first;
        auto d=b.second;
        if(c>=cmx)
        {
            ll x=c-cmx;
            // ll y=m-a.first;

            // auto it2=mp.upper_bound(a.first);
            // if(it2!=mp.end())
            // {
            //     y=min(y,it2->first-a.first);
            // }
            // ll tmp=x*y;
            if(x>0)
            {
                ans.insert(d);
            }
        }
        cmx=max(cmx,c);
    }

    cout<<alice<<"\n";
    loop(i,0,k)
    {
        if(ans.count(i))
        {
            cout<<"1 ";
        }
        else cout<<"0 ";
    }
    cout<<"\n";


}
