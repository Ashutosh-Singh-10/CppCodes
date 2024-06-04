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
bool check( vector<ll> &vec,map<ll,ll> &mp)
{
    auto it=mp.begin();
    loop(i,1,vec.size())
    {
        while(it!=mp.end() && it->second!=vec[i])
        {
            it++;
        }
        if(it==mp.end())
        {
            return 0;
        }

    }
    return 1;

}
void solve()
{   
    ll n,k,t;
    cin>>n>>k;
    vector<vector<ll>> vec(k);
    map<ll,ll> np;
    loop(i,0,k)
    {
        loop(j,0,n)
        {
            cin>>t;
            vec[i].push_back(t);
            np[t]++;
        }
    }
    ll mxi=np.begin()->second;
    for(auto  &i:np)
    {
        if(i.second!=mxi) {
            cout<<"NO"<<endl;
            return;
        }
    }


    if(k==1)
    {
    cout<<"YES"<<endl;
return;
    } 
        
    map<ll,ll> mp,tp;
    ll el=vec[0][0];
    ll mx=-1;
    loop(i,0,k)
    {
        loop(j,1,n)
        {
            if(el==vec[i][j])
            {
                if(mx<j)
                {
                mx=max(mx,(ll)j);
                if(j!=1)
                {
                    tp[vec[i][j-1]]++;;
                }
                else tp[-1]++;

                }
            }
        }
    }
    if(mx==-1) {
        cout<<"NO"<<endl;
        return ;
    }

ll a=0;
ll b=-1;
for(auto &i:tp)
{
    if(i.second>a)
    {
        a=i.second;
        b=i.first;
    }
}
if(b==-1)
{
    mp[-1]=el;
}
    loop(i,1,n)
    {
        mp[(ll)i*2]=(ll)vec[0][i];
        if(vec[0][i]==b)
        {
            mp[i*2+1]=el;
        }
    }
    mp[(mx*2)-1]=el;
    for(ll i=0;i<k;i++)
    {
        
            if(check(vec[i],mp)==0)
            {
                cout<<"NO"<<endl;
                return;
            }
        

    }
    cout<<"YES"<<endl;
    return ;
 
    
    

  
}

    