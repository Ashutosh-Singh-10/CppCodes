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


bool comp(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b)
{
    return b.second.second>a.second.second;
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
    ll n;cin>>n;ll k;cin>>k;
    vector<ll> a,b;
    loop(i,0,n)
    {
        ll t;cin>>t;a.push_back(t);
    }
    loop(i,0,n)
    {
        ll t;cin>>t;b.push_back(t);
    }
    vector<pair<ll,pair<ll,ll>>>vec;
    ll x=0,y=0,ans=0;
    loop(i,0,n)
    {
        if(a[i]<b[i])
        {
            
            vec.push_back({b[i]-a[i],{a[i],b[i]}});
        }
    }
    So(vec);
    sort(vec.begin(),vec.end(),comp);
    // for(auto &[a,b]:vec)
    // {
    //     cout<<a<<" "<<b.first<<" "<<b.second<<endl;
        
    // }
    
    loop(i,1,vec.size())
    {
        vec[i].second.first+=vec[i-1].second.first;
        vec[i].second.second+=vec[i-1].second.second;
    }

   
    loop(i,k,vec.size())
    {
        ans=max(ans,vec[i-k].second.second-vec[i].second.first);
    }
    cout<<ans<<"\n";
    // cout<<endl;
    


}
