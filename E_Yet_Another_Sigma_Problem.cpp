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
    
        solve(0);
    
    
    return 0;
}
ll m1=1e9+7,m2=1e9+9;
void solve(ll tc)
{
    ll n;cin>>n;
    map<pair<ll,ll>,ll> mp;
    ll ans=0;
    loop(k,0,n)
    {
        string s;cin>>s;

        ll h1=0;
        ll h2=0;
        for(auto &i:s)
        {
            h1=(h1*h1)%m1;
            h2=(h2*h2)%m2;
            h1=(h1+i)%m1;
            h2=(h2+i)%m2;
            if(mp.count({h1,h2}))
            {
                ans+=mp[{h1,h2}];
            }
            mp[{h1,h2}]++;

        }

    }
    cout<<ans;


}
