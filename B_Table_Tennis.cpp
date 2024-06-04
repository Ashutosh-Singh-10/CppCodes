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

long long power(long long num,long long degree,long long mod=-1)
{
    if(degree==0) return 1;
    if(degree==1) return num;
        long long ans=power(num,degree/2,mod);
    if(degree&1)
    {
        if(mod>0) return (ans*ans*num)%mod;
        else return ans*ans*num;
    }
        if(mod>0)    return (ans*ans)%mod;
        return ans*ans;
} 
long double  powerInverse(long long num,long long degree,long long mod=-1)
{
    long double ans=1/(double long)power(num,degree,mod);
    return ans;
}

    // if(INFINITY==powerInverse(2,10000))cout<<"HII";
    // cout<<powerInverse(2,10000);
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
    ll n,m,mod=1000000007;
    cin>>n>>m;
    vector<ll> crush(n+1,0);
    loop(i,0,m)
    {
        ll t;cin>>t;
        crush[t-1]=1;
        // crush.push_back(t);
    }
    // vector<vector<vector<ll>>> vec(n+1,vector<vector<ll>>(3,vector<ll>(3,0)));
    vector<vector<ll>> vec(n+1,vector<ll>(3,0));
    vec[0][0]=1;
    loop(i,1,n+1)
    {
        if(i>0 && crush[i-1]==1)
        {
            vec[i][0]=vec[i-1][0];
            vec[i][1]=vec[i-1][1];
            vec[i][2]=0;


        }
        else
        {
            vec[i][0]=(vec[i-1][1]+vec[i-1][2])%mod;
            vec[i][1]=(vec[i-1][0]+vec[i-1][2])%mod;
            vec[i][2]=(vec[i-1][1]+vec[i-1][0])%mod;

        }
        

    }
    ll ans=0;
    for(auto &i:vec[n])
    {
        ans=(ans+i)%mod;

    }
    // ll t=power(2,n,mod);
    // ll u=power(t,mod-2,mod);
    // ans=(ans*u)%mod;
    cout<<ans<<"\n";
  



}