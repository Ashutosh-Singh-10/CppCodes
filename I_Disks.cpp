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
   
        solve();
    
    
    return 0;
}
 
void dfs(vector<vector<ll>> &gr,ll cur,ll prev, ll &tot,ll parity,vector<ll> &visited)
{
    if(visited[cur]>0)
    {
        if((visited[cur]%2)  !=   (parity%2))
        {
            tot=LONG_LONG_MAX/2;
            return ;
        }
        return ;
 
    }
    visited[cur]=parity;
    if(parity%2)
    {
        tot++;
    }
    else tot--;
    for(auto &i:gr[cur])
    {
        dfs(gr,i,cur,tot,parity+1,visited);
 
    }
 
}
void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> vec;
    loop(i,0,n)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        vec.push_back({a,b,c});
    }
    vector<vector<ll>> gr(n);
    loop(i,0,n)
    {
        loop(j,i+1,n)
        {
            ll dist=((vec[i][1]-vec[j][1])*(vec[i][1]-vec[j][1]))+
            
            ((vec[i][0]-vec[j][0])*(vec[i][0]-vec[j][0]));
            if( dist==(vec[i][2]+vec[j][2]) * (vec[i][2]+vec[j][2]))
            {
                gr[i].push_back(j);
                gr[j].push_back(i);
            }
        }
 
    }
 
    vector<ll> visited(n,0);
    vector<ll> visited2(n,0);
 
    loop(i,0,n)
    {
        if(visited[i]==0)
        {
            ll tot=0;
            dfs(gr,i,-1,tot,1,visited);
            if(tot<0)
            {
                cout<<"YES"<<"\n";
                return;
            }
            else tot=0;
            dfs(gr,i,-1,tot,2,visited2);
            if(tot<0)
            {
                cout<<"YES"<<"\n";
                return;
            }
        }
    }
    cout<<"NO"<<"\n";
    
 
 
 
}