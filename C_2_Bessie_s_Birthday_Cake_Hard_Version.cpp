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
ll geo(ll v,ll count,ll &y,map<ll,ll> &tp)
{
    if(y==0) return 0;

    ll req=(v-2)/2;
    ll tot=count*req;

    if(y>=tot)
    {
        y-=tot;
        
        return count*(v-1);
    }
    ll ans=(y/req)*(v-1);
    count-=y/req;
    y%=req;
    
    tp[v-1]++;
    
    return ans;

}
ll atm(ll v,ll count,ll &y)
{
     if(y==0) return 0;

    ll req=(v-2)/2;
    ll tot=count*req;

    if(y>=tot)
    {
        y-=tot;
        return count*(v-3);
    }
    ll ans=(y/req)*(v-3);
    y%=req;
    ans+=(y*2);
    y=0;
    
    return ans;
    

}
void solve()
{
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> vec;
    loop(i,0,x)
    {
        ll t;
        cin>>t;
        vec.push_back(t);
    }
    So(vec);

    map<ll,ll> mp;
    loop(i,1,x)
    {
        mp[vec[i]-vec[i-1]]++;
    }
    mp[vec[0]-vec[x-1]+n]++;
    ll ans=x-2;
    ans+=mp[2];


    map<ll,ll> tp;
    for(auto & [a,b]:mp)
    {
        if(a%2==0 && a>2)
        {

           ans+=geo(a,b,y,tp);
        }
    }
    // for(auto &i:tp)
    // {
    //     mp[i.first]+=i.second;
    // }

    // cout<<"ans ===>"<<ans<<" "<<y<<")";
    // for(auto [a,b]:mp) cout<<a<<" "<<b<<"--->";cout<<endl;
        
    // for(auto &[a,b]:mp)
    // {
    //     if(a%2==1 && a>2)
    //     {
    //         ans+=atm(a,b,y);
    //     }
    // }

    // for(auto [a,b]:mp) cout<<a<<" "<<b<<"--->";cout<<endl;
    ans+=y*2;
    ans=min(ans,n-2);
    cout<<ans<<"\n";
    






}