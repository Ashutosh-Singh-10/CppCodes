
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
#include<bits/stdc++.h>
using namespace std;


class BinaryLifting{
public:
int n, l;
vector<vector<int>> adj;
int timer=0;
vector<int> tin, tout;
vector<vector<int>> up;
BinaryLifting(int root,vector<vector<int>> vec) {
    adj=vec;
    n=vec.size();
    tin.resize(n);tout.resize(n);
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1,-1));
    dfs(root, root);
}
BinaryLifting(int root,vector<int> parent) {
    n=parent.size();
    adj.resize(n);
    for(int i=0;i<n;i++)
    {
        if(parent[i]!=-1)
        adj[parent[i]].push_back(i);

    }
    
    tin.resize(n);tout.resize(n);
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1,-1));
    dfs(root, -1);
}

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        if(up[v][i-1]!=-1)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}



int getKthAncestor(int node, int k) {
        if(k>=n) return -1;
        int len = (int)log2(k); // Calculate the maximum exponent of 2 in k

        for (int i = 0; i <= len; ++i) {
            if (k & (1 << i)) { // If the i-th bit of k is set
                node = up[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }

};
int search(ll v,ll p,vector<vector<int>> &vec,vector<ll> & cnt,vector<ll> &ans)
{
    
    int tot=1;
    for(auto &i:vec[v])
    {
        if(i!=p)
        {
            tot+=search(i,v,vec,cnt,ans);
            
        }
    }
    
    ans[v]=tot;
    // if(v!=0 && v!=vec.size()-1)
    // {
    //     tot++;
    // }
    tot+=cnt[v];
    return tot;

}
void solve()
{
    ll n;cin>>n;
    vector<vector<int>> vec(n);
    loop(i,0,n-1)
    {
        ll a,b;cin>>a>>b;
        a--;b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    vector<ll> count(n,0);
    vector<ll> ans(n,0);
    BinaryLifting *bf=new BinaryLifting(0,vec);
    loop(i,1,n)
    {
        auto lc=bf->lca(i,i-1);
        count[lc]-=2;
        // count[i-1]++;
        // count[i]++;
    }
    search(0,-1,vec,count,ans);
    for(auto &i:ans) cout<<i<<" ";
    cout<<endl;
    for(auto &i:count) cout<<i<<" ";
    cout<<endl;
    cout<<endl;
    

}