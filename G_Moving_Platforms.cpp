        #include <bits/stdc++.h>
        using namespace std;
        using std::cout;
        using std::cin;
        using std::endl;    
        #define ll long long
        #define loop(i,a,b) for(int i=a;i<b;i++)
        #define longloop(i,a,b) for(long long i=a;i<b;i++)
        #define roop(i,a,b) for(int i=a-1;i>=b;i--)
        #define all(p) p.begin(),p.end()
        #define pb(p) push_back(p);
        int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
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

// getbits setbits countbits ispoweroftwo  shiftbits iota
void solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

ll extendedEuclidean(ll a, ll b, ll x, ll y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extendedEuclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

void solve()
{   
    ll n,ed,H,t;
    cin>>n>>ed>>H;
    vector<ll> init,move;
    loop(i,0,n)
    {
        cin>>t;
        init.push_back(t);
    }
    loop(i,0,n)
    {
        cin>>t;
        move.push_back(t);

    }
    vector<vector<ll>>vec;
    loop(i,0,ed)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    _pqr<pair<ll,ll>> pq;
    vector<ll> vis(n,0);
    pq.push({0,0});
    while(pq.size())
    {
        auto tm=pq.top().first;
        auto in=pq.top().second;
        if(in==n-1)
        {
            cout<<tm<<endl;
            return;

        }
        pq.pop();
        if(vis[in]==1) continue;;
        vis[in]=1;
        for(auto &nx:vec[in])
        {
            if(vis[nx]==0)
            {
                
                
                ll c1=(init[in]+tm*move[in])%H;
                ll nx=(init[nx]+tm*move[nx])%H;
                ll dix=c1-nx;
            ll z=
                pq.insert({z+tm,nx});



            }
        }


    }


    cout<<-1<<endl;


    
  
}

    