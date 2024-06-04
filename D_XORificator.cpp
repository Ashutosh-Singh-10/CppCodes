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



void solve(ll tc);

class DSU{public:
    long long size=0;  vector<long long> vec;
    DSU(long long n)
    {
        size=n;
        for(long long i=0;i<n;i++)        vec.push_back(i);
    }
    void join(long long x,long long y){
        vector<long long> a,b;
        while(vec[x]!=x)
        {
            a.push_back(x);
            x=vec[x];
        }
        while(vec[y]!=y)
        {
            b.push_back(y);
            y=vec[y];
        }
        for(auto &i:a)    vec[i]=y;
        for(auto &i:b)    vec[i]=y;
        vec[x]=y;
    }
    long long parent(long long a)
    {
        vector<long long> arr;
        while(vec[a]!=a)
        {

         a=vec[a];
         arr.push_back(a);
        }
        for(auto &i:arr)
        {
            vec[i]=a;

        }
        return a;
    }
    void print()
    {
        for(auto & i:vec)cout<<i<<" ";cout<<endl;
    }
    long long clusters()
    {
        set<long long> st;
        for(long long i=0;i<size;i++)    st.insert(parent(i));
        return st.size();
    }
    void printClusters()
    {
        map<long long,vector<long long>> mp;
        for(int i=0;i<size;i++)
        {
            mp[parent(i)].push_back(i);
        }
        for(auto &[a,b]:mp)
        {
            cout<<a<<"    ->    ";
            for(auto  &j:b)
            {
                cout<<j<<" ";
            }
            cout<<"\n";

        }
    }

};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    loop(i,0,t)
    {
        solve(i);
    }
    
    return 0;
}
void solve(ll tc)
{
    ll n;cin>>n;ll m;cin>>m;
    vector<string> vec(m);
    vector<ll> cnt;
    loop(i,0,n)
    {
        string s;cin>>s;
        loop(j,0,m)
        {
            vec[j].push_back(s[j]);

        }
        
    }
   
    loop(i,0,m)
    {
        ll tot=0;
        loop(j,0,n)
        {
            if(vec[i][j]=='1') tot++;
        }
        cnt.push_back(tot);
    }

    DSU *ds=new DSU(m);

    loop(i,0,n)
    {
        sort(all(vec),[&](string &a,string &b) {
            if(a[i]>=b[i]) return 1;
            return 0;
        });
        map<ll,ll> mp;
        ll j=0;
        for(j;j<m;j++)
        {
            if(vec[j][i]=='1')
            {
                break;
                
            }
            if(mp.count(cnt[j]))
            {
                ds->join(j,mp[cnt[j]]);
            }
            else mp[cnt[j]]=j;
        }
        mp.clear();
        for(j;j<m;j++)
        {
           
            if(mp.count(cnt[j]))
            {
                ds->join(j,mp[cnt[j]]);
            }
            else mp[cnt[j]]=j;
        }


    }
    map<ll,ll> mp;
    loop(i,0,m)
    {
        mp[ds->parent(i)]++;
    }
    ll mx=mp.rbegin()->first;
    ll ans=mp.rbegin()->second;
    cout<<ans<<endl;
    loop(i,0,n)
    {
        ll cnt=0;
        loop(j,0,m)
        {
            if(ds->parent(j)==mx)cnt++;
        }
        if(cnt==ans)
        {
            cout<<1;
        }
        else cout<<0;
    }
    cout<<endl;
    ds->printClusters();
    cout<<endl;

}
