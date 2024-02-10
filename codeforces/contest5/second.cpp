#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
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

void solve();
    void sieveOfEratosthenes(ll N,vector<ll> & ans)
    {

        bool prime[N+1];
        memset(prime, true, sizeof(prime));
     
        for (ll p=2; p*p<=N; p++)
        {
            if (prime[p] == true)
            {
                for (ll i=p*2; i<=N; i += p)
                    prime[i] = false;
            }
        }
     
        for (ll p=2; p<=N; p++)
           if (prime[p])
              ans.push_back(p);
        
        return ;
    }
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
void tryit(vector<ll> &vec,ll &ans,ll gap)
{
    // cout<<"&&&&&&"<<gap<<endl;
    ll temp=0,sm=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    for(auto &i:vec)
    {
        sm+=i;
        temp++;
        if(temp==gap)
        {
            temp=0;
            mn=min(mn,sm);
            mx=max(mx,sm);
            sm=0;
            // cout<<"))))))))))))))))))))))))))))))))";
        }
    }
    // cout<<"*************"<<mx<<"  "<<mn<<endl;
    // cout<<"&&&&&&"<<endl;
    ans=max(ans,mx-mn);
}
void solve()
{
    long long n,temp;
    cin>>n;
    vector<long long> vec;
    for(ll i=0;i<n;i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }
    vector<long long> primes;
    // primes.push_back(1);
    // sieveOfEratosthenes(n,primes);
    long long ans=0;
    
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            tryit(vec,ans,i);
            // cout<<i<<" ###";
        }
    }
    // cout<<"@@@@@@@@@@";
    cout<<ans<<endl;



}

