    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
    #define endl '\n'    
    #define ll unsigned long long
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
    ll k,q,n;cin>>n>>k>>q;
    vector<ll> time={0};
    vector<ll> dst={0};
    map<ll,ll> mp;
    mp[0]=0;
    loop(i,0,k)
    {
        ll t;cin>>t;
        dst.push_back(t);
        mp[t]=i+1;
    }
    loop(i,0,k)
    {
        ll t;cin>>t;
        time.push_back(t);
    }
    loop(i,0,q)
    {
        ll t;cin>>t;
        if(t==n)
        {
            cout<<time.back()<<" ";
            continue;
        }
        auto it=mp.upper_bound(t);
        ll idx=it->second;
        ll ans=time[idx-1];
        ll tmp=(t-dst[idx-1])*(time[idx]-time[idx-1]);
        ans+=(long double)tmp/(long double)((dst[idx]-dst[idx-1]));
        cout<<ans<<" ";

    }
    cout<<endl;


}
