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

ll mod=998244353;

void solve(ll tc);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
        solve(0);
    
    
    return 0;
}
ll dcount(ll a)
{
    ll cnt=0;
    while(a){cnt++;a/=10;}return cnt;
}
void solve(ll tc)
{
    ll n;cin>>n;
    map<ll,ll>mp;
    vector<ll> vec;
    loop(i,1,10)
    {
        mp[i]=0;
    }
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }
    ll ans=0;
    ll idx=0;
    reverse(all(vec));
    for(auto &el:vec)
    {
        ll temp=(el*(n-idx-1))%mod;
        ans=(ans+temp)%mod;
        ll x=dcount(el);
        
        for(auto &[a,b]:mp)
        {
            el=(el*10)%mod;
            ll temp=(el*b)%mod;

            ans=(ans+temp)%mod;
            

        }
        mp[x]++;

        idx++;
    }
    cout<<ans;
}
