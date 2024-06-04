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
ll points(ll r)
{
    ll x=1,y=r+1;
    ll ans=0;
    ll rq=r*r;

    while(x<r )
    {
        while( ((y-1ll)*(y-1ll)) +( (x)*(x)) >=rq)y--;
        
        ans+=max(0ll,y-1);

        x++;
    }
    return ans;

}
void solve(ll tc)
{
    ll r;cin>>r;

    ll ans=points(r+1)-points(r);
    ans*=4;
    ans+=4;
    cout<<ans;

    cout<<endl;
}
