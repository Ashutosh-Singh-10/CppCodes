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



int solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
        return solve();
    
    
    return 0;
}
void fun(map<ll,char> &mp,map<ll,char>& relax,ll low,ll high,ll start,string &s)
{
    low--;
    high--;
    start--;

    for(ll i=low;i<high;i++)
    {
            
        auto it=mp.lower_bound(i);
        if(it==mp.end()) 
        {

            for(auto &i:mp) 
            {
                cout<<i.first<<" ";
            }
                cout<<endl;
        return ;
        }
        // if(it->first>=high) return ;


        // if(i-low+start>=s.length())return ;
        
        relax[it->first]=s[i-low+start];
        i=it->first;
        
        mp.erase(it);

    }
            for(auto &i:mp) 
            {
                cout<<i.first<<" ";
            }
                cout<<endl;

}
int solve()
{
    ll n,m,t;
    cin>>n>>m>>t;
    string s;cin>>s;
    vector<string> vec;
    loop(i,0,m)
    {
        string str;
        cin>>str;
        vec.push_back(str);
    }
    vector<vector<ll>> op;
    loop(i,0,t)
    {
        ll in,x,l,y;
        cin>>in>>x>>l>>y;
        op.push_back({in,x,l,y});

    }
    map<ll,char> mp,relax;
    
    loop(i,0,n)
    {
        mp[i]=s[i];
    }
    roop(i,t,0)
    {
        fun(mp,relax,op[i][3],op[i][3]+op[i][2],  op[i][1]  ,vec[op[i][0]-1]);

    }
    for(auto &i:mp)
    {
        relax[i.first]=i.second;
    }
    string ans;
    for(auto &i:relax)
    {
        ans+=i.second;
    }
    if(ans.length()!=s.length()) return -1;
    cout<<ans<<"\n";
    return 0;

    

}