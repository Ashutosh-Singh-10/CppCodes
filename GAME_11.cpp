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
void solve(ll tc)
{
    ll n,m;cin>>n>>m;
    vector<ll> a,b;
    loop(i,0,n)
    {
        ll t;cin>>t;
        a.push_back(t);
    }
    loop(i,0,m)
    {
        ll t;cin>>t;
        b.push_back(t);
    }
    if(a.size()<4 || b.size()<4 || a.size()+b.size()<11)
    {
        cout<<-1<<endl ;return ;
    }
    So(a);
    So(b);
    ll ans=0;
    loop(i,0,4)
    {
        ans+=a.back();
        ans+=b.back();
        a.pop_back();
        b.pop_back();
    }
    for(auto  &i:a)
    {
        b.push_back(i);
    }
    So(b);
    loop(i,0,3)
    {
        ans+=b.back();
        b.pop_back();
    }
    cout<<ans<<endl;
    return ;
}
