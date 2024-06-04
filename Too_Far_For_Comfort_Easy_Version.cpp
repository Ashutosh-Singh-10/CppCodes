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
    ll t;
    cin>>t;
    loop(i,0,t)
    {
        solve(i);
    }
    
    return 0;
}
long long pow(long long num,long long degree)
{
    if(degree==0) return 1;
    if(degree==1) return num;
        long long ans=pow(num,degree/2);
    if(degree&1)
    {
         return (((ans*ans)%mod)*num)%mod;
    }
            return (ans*ans)%mod;
} 
long long Inv(long long num)
{
    return pow(num,mod-2);
}


    // if(INFINITY==powerInverse(2,10000))cout<<"HII";
    // cout<<powerInverse(2,10000);
ll ncr(vector<ll> &fact,ll n,ll r)
{
    ll ans=fact[n];
    ans=(ans*Inv(fact[r])%mod);
    ans=(ans*Inv(fact[n-r])%mod);
    return ans;
}
void solve(ll tc)
{
    ll n,m;cin>>n>>m;
    vector<ll> fact={1};
    ll curr=1;
    loop(i,1,max(n,m)+1)
    {
        curr=(curr*i)%mod;
        fact.push_back(curr);
    }
    ll ans=0;
    // for(auto  &i:fact) cout<<i<<" ";
    loop(i,1,min(m,n)+1)
    {
        ll full=n/i;
        ll half=n%i;
        curr=pow(fact[i],full)%mod;
        curr=(curr*ncr(fact,m,i))%mod;
        ll temp=(ncr(fact,i,half)*fact[half])%mod;

        curr=(curr*temp)%mod;
        ans=(ans+curr)%mod;

    }
    cout<<ans<<endl;

}
