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
    string s;cin>>s;
    ll h=0,t=0;
    for(auto &i:s)
    {
        if(i=='H') h++;
        else t++;
    }
    int cnt=0;
    for(int i=0;i<t;i++)
    {
        if(s[i]=='T') cnt++;
    }
    ll ans=t-cnt;
    for(int i=t;i<n;i++)
    {
        if(s[i]=='T') cnt++;
        if(s[i-t]=='T') cnt--;
        ans=min(ans,t-cnt);
    }
     cnt=0;
    for(int i=0;i<h;i++)
    {
        if(s[i]=='H') cnt++;
    }
    ans=min(ans,h-cnt);
    for(int i=h;i<n;i++)
    {
        if(s[i]=='H') cnt++;
        if(s[i-h]=='H') cnt--;
        ans=min(ans,h-cnt);
    }
    cout<<ans;
}
