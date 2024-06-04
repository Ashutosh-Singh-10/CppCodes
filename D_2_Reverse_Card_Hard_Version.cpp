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
ll fun(ll b,ll t)
{
    ll i=1;
    ll ans=0;
    while(i*i<=t)
    {
        if(t%i==0)
        {
            // cout<<i<<" ";
            ll y=t/i;
            if(gcd(i,b)==(t/b)+y)
            {
        
                ans++;
            }
            if(gcd(y,b)==(t/b)+i)
            {
      
                ans++;
            }
        }
        i++;

    }
    return ans;

}
void allfac(ll x,vector<ll> &vec)
{
    vec.clear();
    ll i=1;
    while(i*i<x)
    {
        if(x%i==0)
        {
            vec.push_back(i);
            vec.push_back(x/i);
            
        }
        i++;
    }

    if(x%(i*i)==0) vec.push_back(i);
    So(vec);
}
void solve(ll tc)
{
    ll n,m;cin>>n>>m;
    // swap(m,n);
    ll ans=0;
     


   
    cout<<ans<<"\n";

}
