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
   
        solve(7);
    
    
    return 0;
}

void solve(ll tc)
{

    
    cout<<s<<endl;

    ll m;cin>>m;

    vector<ll> p,n;
    vector<pair<ll,ll>> lst;
    loop(i,0,m)
    {
        ll a,b;cin>>a>>b;
        a--;b--;
        p.push_back(a);
        n.push_back(b);
    }
    vector<ll> vis(m,0);    
    
    loop(i,0,m)
    {

        if(vis[i]) continue;
        ll l=i;
        
        while(p[l]!=-1)
        {
            vis[l]=1;
            l=p[l];
        }
        ll r=i;
        while(n[r]!=-1)
        {
            vis[r]=1;
            r=n[r];
        }
        vis[r]=1;
        vis[l]=1;

        lst.push_back({l,r});
    }
    // for(auto &i:lst) cout<<i.first<<" "<<i.second<<endl;
    for(int i=0;i<lst.size()-1;i++)
    {
        n[lst[i].second]=lst[i+1].first;
        p[lst[i+1].first]=lst[i].second;
    }
    loop(i,0,m)
    {
        cout<<1+p[i]<<" "<<1+n[i]<<endl;
    }

    
}



