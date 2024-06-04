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
    ll n,k,a,b;cin>>n>>k>>a>>b;
    a--;b--;
    vector<ll> pos,vec;
    loop(i,0,n)
    {
        ll t; cin>>t;
        pos.push_back(t);
    }
    loop(i,0,n)
    {
        ll t; cin>>t;
        vec.push_back(t);
    }
    ll x=0,y=0,cur=0;
    for(int i=0;i<=min(n,k);i++)
    {
        cur+=vec[a];
        x=max(x,cur+((k-i-1)*vec[a]));
        a=pos[a]-1;
        

    }
    cur=0;
    for(int i=0;i<=min(n,k);i++)
    {
        cur+=vec[b];
        y=max(y,cur+((k-i-1)*vec[b]));
        b=pos[b]-1;
        
    }
    if(x==y)
    {
        cout<<"Draw";
    }
    else if(x>y)
    {
        cout<<"Bodya";
    }
    else cout<<"Sasha";
    cout<<endl;
    
    
}



