    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
    #ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
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
void transform(vector<vector<ll>> &a,vector<vector<ll>>& c,ll n,ll m)
{
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            c[j][i]=a[i][j];
            
        }
    }
    
}
void solve(ll tc)
{
    ll n;cin>>n;
    ll m;cin>>m;
    vector<vector<ll>> a,b;
    loop(i,0,n)
    {
        a.push_back({});
        loop(j,0,m)
        {
            ll t;cin>>t;
            a[i].push_back(t);
        }
    }
    auto el=a[0][0];
    ll x,y;
    loop(i,0,n)
    {
        b.push_back({});
        loop(j,0,m)
        {
            ll t;cin>>t;
            b[i].push_back(t);
            if(el==t)
            {
                x=i,y=j;
            }

        }
    }
    loop(i,0,m) swap(b[x][i],b[0][i]);
    loop(i,0,n) swap(b[i][y],b[i][0]);
    auto it=a.begin();
    it++;
    sort(it,a.end());
    it=b.begin();
    it++;
    sort(it,b.end());

    vector<vector<ll>> c(m,vector<ll>(n,0)),d(m,vector<ll>(n,0));
    transform(a,c,n,m);
    transform(b,d,n,m);

     it=c.begin();
    it++;
    sort(it,c.end());
    it=d.begin();
    it++;
    sort(it,d.end());
    // dbg(a);
    // dbg(b);
    // dbg(endl);
    // dbg(c);
    // dbg(d);
    // dbg(endl);
    // dbg(endl);
    loop(i,0,m)
    {
        loop(j,0,n)
        {
            if(c[i][j]!=d[i][j])
            {

                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return ;
}



