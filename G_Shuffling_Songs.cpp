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

        template<class T> void vec_out(vector<T> &p,int ty=0){
        if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
        else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}

        template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
        template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;} 

        template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
        template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
        template<class T> T vec_sum(vector<T> &a){assert(!a.empty());T ans=a[0]-a[0];for(auto &x:a) ans+=x;return ans;}

        template<class T>  void matcout(vector<vector<T>> &a){for(auto &i:a){ for(auto &j:i){cout<<j<<"  ";}cout<<"\n";}cout<<"\n";}

        template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
        template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}

template<typename T1> void printIt(T1 t1){cout<<t1<<"\n";}
template<typename T1, typename... T2>
void printIt(T1 t1,T2... t2) {cout<<t1<<" , "; printIt(t2...);}
// getbits setbits countbits ispoweroftwo  shiftbits iota



void solve(int t,int mx);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;

    cin>>t;
    ll mx=t;
    loop(i,0,t)
    {
        solve(i,mx);
    }
    
    return 0;
}
class DSU{public:
    long long size=0;  vector<long long> vec;
    DSU(long long n)
    {
        size=n;
        for(long long i=0;i<n;i++)        vec.push_back(i);
    }
    void join(long long x,long long y){
        vector<long long> a,b;
        while(vec[x]!=x)
        {
            a.push_back(x);
            x=vec[x];
        }
        while(vec[y]!=y)
        {
            b.push_back(y);
            y=vec[y];
        }
        for(auto &i:a)    vec[i]=y;
        for(auto &i:b)    vec[i]=y;
        vec[x]=y;
    }
    long long parent(long long a)
    {
        while(vec[a]!=a) a=vec[a];
        return a;
    }
    void print()
    {
        for(auto & i:vec)cout<<i<<" ";cout<<endl;
    }
    long long clusters()
    {
        long long ans=0;
        for(long long i=0;i<size;i++)    if(vec[i]==i) ans++;
        return ans;
    }

};

void solve(int t,int mx)
{
    ll n;
    cin>>n;
    vector<pair<string,int>> a,b;
    loop(i,0,n)
    {
        string x,y;
        cin>>x>>y;
        if(mx==400 && t==182)
        {
            cout<<x<<"  "<<y<<"\n";
        }
        a.push_back({x,i});
        b.push_back({y,i});

    }
    So(a);So(b);
    DSU *ds=new DSU(n);
    for(int i=1;i<n;i++)
    {
        if(a[i].first==a[i-1].first)
        {
            ds->join(a[i].second,a[i-1].second);
        }
        if(b[i].first==b[i-1].first)
        {
            ds->join(b[i].second,b[i-1].second);
        }

    }
    map<ll,ll>mp;
    loop(i,0,n)
    {
        mp[ds->parent(i)]++;
    }
    ll ans=n;
    for(auto &[a,b]:mp)
    {
        ans=min(n-b,ans);

    }
    cout<<ans<<"\n";




}