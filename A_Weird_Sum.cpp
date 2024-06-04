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
   
        solve(0);
      
    return 0;
}
void solve(ll tc)
{
    ll n;cin>>n;ll m;cin>>m;
    map<ll,multiset<ll>> v,h;
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            ll t;cin>>t;
            v[t].insert(i);
            h[t].insert(j);


        }
    }
    ll ans=0;
    for(auto &[zz,sst]:v)
    {
        ll cnt=0;
        ll diff=0;
        ll prev=-1;
        for(auto &j:sst)
        {
            
            if(prev==-1)
            {
                prev=j;
                cnt++;
                continue;;
            }

            diff+=cnt*(j-prev);
            ans+=diff;
            cnt++;
            prev=j;
        }
    }
    for(auto &[zz,sst]:h)
    {
        ll cnt=0;
        ll diff=0;
        ll prev=-1;
        for(auto &j:sst)
        {
            
            if(prev==-1)
            {
                prev=j;
            cnt++;
                continue;;
            }
            diff+=cnt*(j-prev);
            ans+=diff;
            cnt++;
            prev=j;
        }
    }
    cout<<ans;
}
