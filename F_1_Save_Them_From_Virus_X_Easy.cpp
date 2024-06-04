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
    vector<vector<ll>> dir={{1,0},{0,1},{-1,0},{0,-1}};



void solve(ll tc);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
        solve(0);
    
    
    return 0;
}
bool isValid(ll a,ll b,ll n)
{
    return a<n && a>=0 && b<2 && b>=0;
}
ll dfs(vector<vector<ll>> &vec,vector<vector<ll>> vis,queue<pair<ll,ll>> qu)
{
    ll ans=0;
    while(qu.size())
    {
        auto [a,b]=qu.front();
        qu.pop();
            ans++;
        for(auto i:dir)
        {
            if(isValid(a+i[0],b+i[1],vec.size()) && vis[a+i[0]][b+i[1]]==0 && vec[a+i[0]][b+i[1]]!=1)
            {
                qu.push({a+i[0],b+i[1]});
                vis[a+i[0]][b+i[1]]=1;
            }
        }
        
    }
    return (vec.size()*2)-ans;

}
void fun(vector<vector<ll>> &vec,ll idx, ll &ans,ll k,vector<vector<ll>> &vis,queue<pair<ll,ll>> &qu)
{
    if(idx==vec.size() )
    {
        if(k==0)
        {

            ll temp=dfs(vec,vis,qu);
            ans=max(temp,ans);
        }
        return ;
    }
    fun(vec,idx+1,ans,k,vis,qu);

    if(vec[idx][0]!=-1 && k>0)
    {
        vec[idx][0]=1;
        fun(vec,idx+1,ans,k-1,vis,qu);
        vec[idx][0]=0;
    }
    if(vec[idx][1]!=-1 && k>0)
    {
        vec[idx][1]=1;
        fun(vec,idx+1,ans,k-1,vis,qu);
        vec[idx][1]=0;
    }
    if(vec[idx][1]!=-1 && vec[idx][0]!=-1 && k>1)
    {
        vec[idx][1]=1;
        vec[idx][0]=1;
        fun(vec,idx+1,ans,k-2,vis,qu);
        vec[idx][1]=0;
        vec[idx][0]=0;
    }


}
void solve(ll tc)
{
    ll n,m,k;cin>>n>>m>>k;
    vector<vector<ll>> vec(n,vector<ll> (2,0));
    vector<vector<ll>> vir(n,vector<ll>(2,0));
    queue<pair<ll,ll>> qu;
    loop(i,0,m)
    {
        ll a,b;cin>>b>>a;
        a--;b--;
        vec[a][b]=-1;
        qu.push({a,b});
        vir[a][b]=1;
        
    }
    ll ans=0;
    fun(vec,0,ans,k,vir,qu);
    cout<<ans<<"\n";


}
