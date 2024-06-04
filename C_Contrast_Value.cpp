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
    ll n;cin>>n;
    vector<ll> vec,ans;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
        
    }
    ll x=count(all(vec),vec[0]);
    if(x==n) 
    {
        cout<<1<<endl;
        return ;
    }
    
    ll dir=0;
    if(vec[0]==vec[1]) dir=0;
    else if(vec[0]>vec[1]) dir=-1;
    else dir=1;

    ll cnt=0;
    loop(i,1,n-1)
    {
        if(vec[i]>vec[i+1] && dir==1) cnt++;
        else if(vec[i]<vec[i+1] && dir==-1) cnt++;

        if(vec[i]>vec[i+1]) dir=-1;
        else if(vec[i]<vec[i+1]) dir=1;
    }
    
    cout<<cnt+2<<endl;
    
}
