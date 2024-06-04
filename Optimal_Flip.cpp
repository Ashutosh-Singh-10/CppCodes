    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
    #define endl '\n'    
    #define ll long long
    #define int long long
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
int32_t main()
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
    ll n;cin>>n;
    vector<ll> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        if(t%2==0)
        vec.push_back(i);
    }
    ll ans=(n*(n+1))/2;;
    if(vec.size()==0)
    {
        ll a=n/2;
        ll b=n/2;
            ans-=a*(a+1)/2;
            ans-=b*(b+1)/2;
            cout<<ans<<endl;
        return ;
    }
    
    // ll temp;
    ll mxp=0;
    ll diff;
    ll m=vec.size();
    loop(i,1,m)
    {
        diff=vec[i]-vec[i-1]-1;
        ans-=(diff*(diff+1))/2;
        mxp=max(mxp,vec[i]-vec[i-1]-1);
    }
     diff=vec[0];
    ans-=(diff*(diff+1))/2;
    mxp=max(mxp,vec[0]);
     diff=n-(ll)1-vec[m-1];
    ans-=(diff*(diff+1))/2;
    mxp=max(mxp,n-(ll)1-vec[m-1]);

    ans+=mxp*(mxp+1)/2;

    ll a=(mxp-1)/2;
    ll b=mxp/2;
    ans-=(a*(a+1))/2;
    ans-=(b*(b+1))/2;
    cout<<ans<<"\n";




    
    
    
    
    
  




    




}
