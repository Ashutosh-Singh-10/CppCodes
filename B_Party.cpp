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
    ll n,m,a,b;
    cin>>n>>m;
    vector<ll> vec;
    vector<unordered_set<ll> > gr(n);

    loop(i,0,n)
    {
        cin>>a;
        
        vec.push_back(a);

    }
    loop(i,0,m)
    {
        cin>>a>>b;
        gr[a-1].insert(b-1);
        gr[b-1].insert(a-1);
    }
    if(m%2==0)
    {
        cout<<0<<endl;
        return ;
    }
    vector<ll> ev,od;
unordered_set<ll> ods;
    loop(i,0,n)
    {
        if(gr[i].size()%2==0)
        {
            ev.push_back(i);
        ods.insert(i);
        }
        else 
        {

        od.push_back(i);
        }
    }
    ll mxi=LONG_LONG_MAX;
    for(auto &i:od)
    {
        mxi=min(vec[i],mxi);
    }
    for(auto &i:ev)
    {
        for(auto &j:gr[i])
        {
            if(ods.count(j))
            {
                mxi=min(mxi,vec[i]+vec[j]);
            }
        }

    }
    

    cout<<mxi<<endl;




  
}

    