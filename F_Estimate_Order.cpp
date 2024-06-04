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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
        solve(0);
    
    
    return 0;
}

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
        ll p=min(x,y);
        for(auto &i:a)    vec[i]=p;
        for(auto &i:b)    vec[i]=p;
        vec[x]=p;
        vec[y]=p;
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

void solve(ll tc)
{
    ll n,m;cin>>m;
    DSU *ds=new DSU(n);
    vector<vector<ll>> vec;
    loop(i,0,m)
    {
        ll a,b,c; cin>>a>>b>>c;
        a--;b--;
        vec.push_back({a,b,c});
        ds->join(a,b);
    }

    ll cl=ds->clusters();
    

    vector<map<ll,ll>> bits(cl);
    for(auto   &i:vec)
    {
        ll a=vec[0],b=vec[1],c=vec[2];
        auto it=bits[ds->parent(vec[1])];
        if(it.count(a))

    }
    
    


    
    
    
}
