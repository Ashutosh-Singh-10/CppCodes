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



void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> gr(n+1);
    loop(i,0,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    ll start,end;
    cin>>start>>end;
    if(start==end)
    {
        cout<<0<<"\n";
        return ;
    }
    vector<ll> dist(n+1,LONG_LONG_MAX);
    dist[start]=0;
    vector<ll> vis(n+1,0);
    vector<set<ll>> st(n+1);
    _pqr<pair<ll,ll>> qu;

    dist[start]=0;
    qu.push({0,start});


    ll ans=LONG_LONG_MAX;
    while(qu.size())
    {
        auto [b,a]=qu.top();
        qu.pop();

        if(a==end)
        {
            ans=min(ans,b);
            continue;;
        }

        if(vis[a]==1) continue;
        vis[a]=1;



        for(auto &i:gr[a])
        {
            ll len;
            // if(vis[i.first]==1) continue;  
            if(st[a].count(i.second))
            {
                len=dist[a];

            }
            else len=dist[a]+1;
            
            if(len<dist[i.first]) 
            {
                st[i.first].clear();
                st[i.first].insert(i.second);
                dist[i.first]=len;
                qu.push({dist[i.first],i.first});
                vis[i.first]=0;

            }
            else if(len==dist[i.first])
            {
                st[i.first].insert(i.second);
                
                qu.push({dist[i.first],i.first});
                vis[i.first]=0;
            }
        }
        

    }
    cout<<ans<<"\n";
    // cout<<"HII";
    // cout<<endl;



    

    


}
