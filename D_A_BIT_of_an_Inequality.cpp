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

ll fun(vector<ll> &vec,ll t)
{
    ll x=(ll)1<<t;
    ll ans=0;
    ll odd=0;
    ll even=0;
    ll cnt=0;
    for(auto  &i:vec)
    {
        if(x&i)
        {
            cnt++;
        }
        if(cnt%2) odd++;else even++;
    }
    ll a=0,b=0;
    ll c=0;
    for(auto &i:vec)
    {
        if(((x&i)!=0) && (x>(x^i)))
        {
            if(c%2)
            ans+=even*a;
            else ans+=odd*b;
        }
        
        if(x&i)    c++;
        if(c%2)
        { a++;odd--;}
        else{even--;b++;} 
    }
    return ans;
}
void solve(ll tc)
{

    ll n;cin>>n;
    vector<ll> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }
    ll ans=0;
    for(ll i=32;i>=0;i--)
    {
        ans+=fun(vec,i);
    }
    cout<<ans<<"\n";
}
