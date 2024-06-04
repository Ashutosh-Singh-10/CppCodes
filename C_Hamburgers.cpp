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
    string str;cin>>str;
    ll b=0,s=0,c=0;
    for(auto &i:str)
    {
        if(i=='B') b++;
        else if(i=='S') s++;
        else c++;
    }
    ll mb,ms,mc;
    ll pb,ps,pc;
    cin>>mb>>ms>>mc;
    cin>>pb>>ps>>pc;
    ll rub=0;cin>>rub;
    ll low=0,high=1e13,mid;
    ll ans=0;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        ll flag=0;
        ll cost=0;
        ll rem=max(0ll,(mid*b)-mb);
        cost+=rem*pb;

        rem=max(0ll,(mid*c)-mc);
        cost+=rem*pc;
        
        rem=max(0ll,(mid*s)-ms);
        cost+=rem*ps;
        if(cost<=rub)
        {
            ans=max(ans,mid);
            low=mid+1;

        }
        else high=mid-1;

    }
    cout<<ans<<endl;




}
