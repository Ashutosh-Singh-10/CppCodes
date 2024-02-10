        #include <bits/stdc++.h>
        using namespace std;
        using std::cout;
        using std::cin;
        using std::endl;    
        #define ll long long
        #define Endl endl
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

// getbits setbits countbits ispoweroftwo  shiftbits
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
bool cost(vector<ll> &vec,ll val)
{
    ll n=vec.size();
    vector<ll> tec(n,0);
    ll i=0,sum=0;
    multiset<ll> mst;

    while(i<n && sum<=val)
    {
        tec[i]=vec[i];
        sum+=vec[i];
        mst.insert(tec[i]);
        i++;
    }
    ll start=0;
    
    for(i;i<n;i++)
    {
       
       
        ll mn=tec[i-1]-vec[i-1];
        while(sum>val && start<i)
        {
            sum-=vec[start];
            mn=*mst.begin();
            auto it=mst.find(tec[start]);
            mst.erase(it);
            start++;
        }
        sum+=vec[i];
        tec[i]=mn+vec[i];
        mst.insert(tec[i]);
    }


    sum=0;

    roop(i,n,0)
    {
        sum+=vec[i];
        if(tec[i]<=val) return 1;
        if(sum>val)
        {

         return 0;
        }
    }
    return 0;







}
void solve()
{   
    ll n,t;
    cin>>n;
    vector<ll> vec;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        vec.push_back(t);
    }
    ll high=1E18;
    ll low=*min_element(all(vec));
    ll ans=high;
    while(high>=low)
    {
        ll mid=low+(high-low)/2;
        if(cost(vec,mid))
        {
            // cout<<mid<<" ";
            high=mid-1;
            ans=min(ans,mid);

        }
        else low=mid+1;
    }
    // cout<<"kya hua yaar";
    cout<<ans<<endl;        


  
}

    