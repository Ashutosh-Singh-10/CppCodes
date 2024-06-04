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
    if(r==0) return 1;
    ll ans=fact[n];
    ans=(ans*Inv(fact[r])%mod);
    ans=(ans*Inv(fact[n-r])%mod);
    return ans;
}
ll fun(vector<ll> &vec,ll &n,ll &k,vector<ll> &fact,ll &un,ll &m)
{
    ll ans=ncr(fact,m-un,k-un);
    
    for(int i=0;i<n;i+=k)
    {
        unordered_map<ll,ll>mp;
        
        ll cnt=0;
        for(int j=i;j<min(n,i+k);j++)
        {
        
            cnt++;
            if(vec[j]!=0 && mp.count(vec[j])) {
                return 0;}
            mp[vec[j]]++;

        }
        if(cnt!=k)
        {
           ll zero=mp[0];
           ans=(ans*fact[mp[0]])%mod;
           ans=(ans*ncr(fact,k-cnt+zero,zero))%mod;


        }
        else 
        {
        ans=(ans*fact[mp[0]])%mod;
        }
    }
 
    return ans;





}
void solve(ll tc)
{
    ll m,n;cin>>n>>m;

    vector<ll> fact={1};
    vector<ll> vec;
    set<ll>st;
    loop(i,0,n)
    {
        ll t;cin>>t;
        if(t!=0)
        st.insert(t);
        vec.push_back(t);
    }
    ll curr=1;
    loop(i,1,m+1)
    {
        curr=(curr*i)%mod;
        fact.push_back(curr);
    }


    ll mn=st.size();
    ll ans=0;
    
    for(ll i=max((ll)1,mn);i<=(m,n);i++)
    {
       
        
        ans=(ans+fun(vec,n,i,fact,mn,m))%mod;
    }
    cout<<ans<<"\n";
}
