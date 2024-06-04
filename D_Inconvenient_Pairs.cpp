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
void solve()
{   
    ll n,t;
    ll l,w,p;
    cin>>l>>w>>p;
    set<ll> ln;
    set<ll> wd;
    vector<pair<ll,ll>> ww,hh;

    loop(i,0,l)
    {
        cin>>t;
        ln.insert(t);
    }
    loop(i,0,w)
    {
        cin>>t;
        wd.insert(t);
    }
    loop(i,0,p)
    {
        ll a,b;
        cin>>a;
        cin>>b;
        if(ln.count(a)==0)
        {
            hh.push_back({a,b});
        }
        else if(wd.count(b)==0)
        {
            ww.push_back({b,a});
        }
    }
    for(auto &i:wd)
    {
        ww.push_back({i,-1});
    }
    for(auto &i:ln)
    {
        hh.push_back({i,-1});
    }
    So(hh);
    So(ww);

    ll ans=0;
    map<ll,ll> kt;
    ll cnt=0;
    for(auto &i:ww)
    {
        if(i.second+1)
        {
            kt[i.second]++;
            cnt++;
            ans+=max(cnt-kt[i.second],(ll)0);
        }
        else 
        {
            cnt=0;
            kt.clear();
        }
    }
    kt.clear();
     cnt=0;
    for(auto &i:hh)
    {
        if(i.second+1)
        {
            kt[i.second]++;
            cnt++;
            ans+=max(cnt-kt[i.second],(ll)0);
            
        }
        else 
        {
            cnt=0;
            kt.clear();
        }
    }

    cout<<ans<<"\n";


  
}

    