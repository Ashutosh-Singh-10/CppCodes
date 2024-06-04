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
void solve(ll tc)
{
    ll n;cin>>n;
    vector<pair<ll,ll>> vec(n);
    map<ll,set<pair<ll,ll>>> mp;
    loop(i,0,n)
    {
        ll a;
        cin>>a;
        vec[i].second=a;
    }
    loop(i,0,n)
    {
        ll a;
        cin>>a;
        vec[i].first=a;
    }
    loop(i,0,n)
    {
        auto [a,b]=vec[i];
        mp[b].insert({a,i});
    }
    vector<pair<ll,ll>> ans;
    loop(i,0,n)
    {
        auto [a,b]=vec[i];
        auto it=mp[b].begin();
        if(it->second==i)
        {
            mp[b].erase(it);
        }
        else
        {
            ll x=it->first;
            ll y=it->second;
            ans.push_back({i,it->second});
            mp[b].erase(mp[b].lower_bound({a,-1}));
            vec[i].first=x;
            vec[y].first=a;

            mp[b].erase(it);
            mp[b].insert({a,y});




        }
        if(i>0 && vec[i].first<vec[i-1].first)
        {
            // cout<<i<<endl;
            // for(auto &i:vec) cout<<i.first<<"->"<<i.second<<"    ";
            cout<<-1<<"\n";
            return ;
        }
    

    }
    cout<<ans.size()<<'\n';
    for(auto &i:ans)
    {
        cout<<i.first<<" "<<i.second<<"\n";
    }

}
