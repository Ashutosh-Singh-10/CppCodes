//     #include <bits/stdc++.h>
//     using namespace std;
//     using std::cout;
//     using std::cin;
//     #define endl '\n'    
//     #define ll unsigned long long
//     #define loop(i,a,b) for(ll i=a;i<b;i++)
//     #define roop(i,a,b) for(ll i=a-1;i>=b;i--)
//     #define all(p) p.begin(),p.end()
//     #define pb(p) push_back(p);
//     template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
//     template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}



// void solve();
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
   
//         solve();
    
    
//     return 0;
// }
// void solve()
// {
//     ll n;cin>>n;
//     multimap<ll,ll> mp;
//     vector<ll> vec;
//     ll mx=1e8;
//     loop(i,0,n)
//     {
//         ll t;cin>>t;
//         vec.push_back(t);
//     }
//     So(vec);
//     ll sum=accumulate(all(vec),0ll);
//     ll ans=sum*n;
//     loop(i,0,n)
//     {
//         auto it=mp.upper_bound(mx-vec[i]);
//         if(it!=mp.end())
//         {
//             auto x=it->second;
//             ans-=(mx*(i-x));
//         }
//         mp[vec[i]]=i;

//     }
//     cout<<ans;

    
// }





    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
    #define endl '\n'    
    #define ll unsigned long long
    #define loop(i,a,b) for(ll i=a;i<b;i++)
    #define roop(i,a,b) for(ll i=a-1;i>=b;i--)
    #define all(p) p.begin(),p.end()
    #define pb(p) push_back(p);
    template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
    template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}



void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
        solve();
    
    
    return 0;
}
void solve()
{
    ll n;cin>>n;multimap<ll,ll> mp;
    vector<ll> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }
    ll mx=1e8;
    So(vec);
    ll curr=0;
    vector<ll> pre;
    pre.push_back(0);
    loop(i,0,n)
    {
        curr+=vec[i];
        pre.push_back(curr);
    }
    ll tot=0;
    mp.insert({vec[0],0});
    // mp[vec[0]]=0;
    loop(i,1,n)
    {
        auto it=mp.lower_bound(mx-vec[i]);

        if(it==mp.end())
        {
            tot+=pre[i]+((i)*vec[i]);
        // mp[vec[i]]=i;
        mp.insert({vec[i],i});
            continue;
        }
        mp.insert({vec[i],i});
        // mp[vec[i]]=i;
        auto idx=it->second;

        ll ans=pre[idx]+(vec[i]*(idx-1));

        ll curr=pre[i+1]-pre[idx];
        ll diff=i-idx;
        ans+=curr+(vec[i]*(diff))-(mx*diff);
        tot+=ans;
    }

        cout<<tot<<" ";
    
}
