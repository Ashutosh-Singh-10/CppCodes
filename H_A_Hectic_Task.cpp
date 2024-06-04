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
    ll mod =1e9+7;


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
long long pow(long long num,long long degree,long long mod=-1)
{
    if(degree==0) return 1;
    if(degree==1) return num;
        long long ans=pow(num,degree/2,mod);
    if(degree&1)
    {
         return (((ans*ans)%mod)*num)%mod;
    }
            return (ans*ans)%mod;
        
} 
long long Inv(long long num,long long degree,long long mod=-1)
{
    return pow(num,degree-2,mod);
}


ll fact(ll n)
{
    if(n==0) return 1;
    return (fact(n-1)*n)%mod;

}
ll fun(map<ll,ll> &mp,ll ex,ll total)
{
    total-=mp[ex];
    if(total==0) return 0;
    ll ans=fact(total);
    for(auto &[a,b]:mp)
    {
        if(a!=ex)
        {
            if(b)
            ans=(ans*Inv(fact(b),mod,mod))%mod;
        }
    }
    return ans;

    

}
void solve(ll tc)
{
    ll n;cin>>n;string s; cin>>s;
    map<ll,ll> mp;
    for(char ch='a';ch<='z';ch++)
    {
        mp[ch]=0;
    }
    for(auto &i:s)
    {
        mp[i]++;
    }
    ll ans=0;
    for(char ch='a';ch<='z';ch++)
    {
        ll temp=max((ll)1,fun(mp,ch,n));
        ans=(ans+temp)%mod;
        
    }
    cout<<ans<<"\n";





}
