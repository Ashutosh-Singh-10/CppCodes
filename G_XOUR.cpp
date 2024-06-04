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
    ll n;cin>>n;
    map<ll,vector<ll>>mp;
    vector<ll> vec,ans;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
        ll x=t;
        x>>=2;
        mp[x].push_back(t);
    }
    for(auto &i:mp)
    {
        Sore(i.second);
    }
    for(auto &i:vec)
    {
        ll x=i;x>>=2;
        // cout<<x<<" ";
        if(mp[x].size())
        {
            cout<<mp[x].back()<<" ";
            mp[x].pop_back();
        }
    }
  
    cout<<endl;
    

    


}
