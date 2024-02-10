#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
#define longloop(i,a,b) for(long long i=a;i<b;i++)
#define roop(i,a,b) for(int i=a-1;i>=b;i--)
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
void solve()
{   
    ll k,a,b;
    cin>>k;
    vector<pair<ll,ll>> vec;
    int m=0,n=0,p=0,o=0;
    loop(i,0,k)
    {
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(all(vec));
    int flag=1;
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i].second<vec[i-1].second);
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"YES"<<endl;
        return ;
    }
    flag=1;
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i].second>vec[i-1].second);
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"YES"<<endl;
        return ;
    }
    flag=1;

   loop(i,0,n)
   {
    vec[i]={vec[i].second,vec[i].first};
   }

sort(all(vec));





flag=1;
   for(int i=1;i<vec.size();i++)
    {
        if(vec[i].second<vec[i-1].second);
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"YES"<<endl;
        return ;
    }
    flag=1;
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i].second>vec[i-1].second);
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"YES"<<endl;
        return ;
    }
    ll amn=LONG_LONG_MAX;
    ll bmn=LONG_LONG_MAX;
    ll amx=LONG_LONG_MIN;
    ll bmx=LONG_LONG_MIN;
    loop(i,0,k)
    {
        if(amn>vec[i].first)
        {
            amn=vec[i].first;
        }
        if(amx<vec[i].first)
        {
            amx=vec[i].first;
        }
        if(bmn>vec[i].second)
        {
            bmn=vec[i].second;
        }
        if(bmx<vec[i].second)
        {
            bmx=vec[i].second;
        }
    }
    // cout<<"##->"<<amn<<"  "<<amx<<"  "<<bmn<<" "<<bmx<<endl;
    if(amn>=0 || amx<=0 || bmn>=0 || bmx<=0)
    {
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;
   
  
}

