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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> vec;
    loop(i,0,n)
    {
        ll t;
        cin>>t;
        vec.push_back(t);
    }
    map<ll,ll> b,c;
    loop(i,0,m)
    {
        ll t;cin>>t;
        b[t]++;
    }
    ll cnt=0,ans=0;
    loop(i,0,m)
    {
        c[vec[i]]++;
        if(b.count(vec[i]) && c[vec[i]]<=b[vec[i]])
        {cnt++;}        
    }
    if(cnt>=k) ans++;
    loop(i,m,n)
    {
        c[vec[i]]++;
        if(b.count(vec[i]) && c[vec[i]]<=b[vec[i]])
        {cnt++;}        
        c[vec[i-m]]--;
        if(b.count(vec[i-m]) && c[vec[i-m]]<b[vec[i-m]])
        {cnt--;}        
        if(cnt>=k) ans++;
        

    }
    cout<<ans<<"\n";




    // multiset<ll> st;
    // multimap<ll,ll> bt;
    // loop(i,0,m)
    // {
    //     ll t;
    //     cin>>t;
    //     st.insert(t);
    // }
    // roop(i,m,0)
    // {
    //     if(st.count(vec[i]))
    //     {

    //         bt.insert({vec[i],i});
    //         st.erase(st.lower_bound(vec[i]));
    //     }
        
    // }
    // ll ans=0;
    // if(bt.size()>=k) ans++;
    // loop(i,m,n)
    // {
    //     if(bt.count(vec[i-m])) 
    //     {
    //         auto it=bt.lower_bound(vec[i-m]);
    //         if(it->second==i-m)
    //         {

    //         st.insert(vec[i-m]);
    //         bt.erase(it);
    //         }
           
    //     }
    //     if(st.count(vec[i]))
    //     {
    //         st.erase(st.lower_bound(vec[i]));
    //         bt.insert({vec[i],i});
    //     }   
    //     else if(bt.count(vec[i]))
    //     {
    //         bt.erase(bt.lower_bound(vec[i]));
    //         bt.insert({vec[i],i});
    //     }

    //     if(bt.size()>=k) ans++;    
        
    // }
    // cout<<ans<<"\n";


}