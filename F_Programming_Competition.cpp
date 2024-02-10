#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
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

ll rec(vector<vector<ll>> &vec,ll curr,ll &ans,vector<vector<ll>> &prs)
{
    
    if(vec[curr].size()==0) return 1;
    ll tot=0,mx=0;
    ll in=vec[curr][0];
    // for(auto &i:vec[curr])

    for(int i=0;i<vec[curr].size();i++)
    {
        ll next=vec[curr][i];
        ll x=rec(vec,next,ans,prs);
        tot+=x;
        if(mx<x)
        {
            in=next;
            mx=x;
        }
    

    }
    ll rem=tot-mx;
    prs[curr]={mx,rem,in};
    return tot+1;


}
void algo(vector<vector<ll>> &prs,ll curr,ll &ans,ll av)
{
    if(prs[curr].size()==0) 
    {
        if(av==0 )
     ans++;
        return ;
    }
    
    if(av==0 )
    {
        ans++;
    }
    else av--;
    ll mx=prs[curr][0];
    ll tot=av+prs[curr][1];
    ll nxt=prs[curr][2];
    // cout<<curr<<"   "<<tot<<"  "<<mx<<endl;
    if(mx<=tot)
    {
        if((mx+tot)%2)
        {
            ans++;
        }
        return ;
    }

    algo(prs,nxt,ans,tot);
    
    
    
    


 
}
void solve()
{   
    ll n,temp;
    cin>> n;
    vector<vector<ll>> vec(n);
    loop(i,0,n-1)
    {
        cin>>temp;
        vec[temp-1].push_back(i+1);

    }
    // cout<<"HII";
    ll ans=0;
    vector<vector<ll>> prs(n);
    rec(vec,0,ans,prs);


// for(auto &i:prs)
// {
//     if(i.size())
//     cout<<i[0]<<"  "<<i[1]<<"  "<<i[2]<<endl;
//     else cout<<"NULL"<<endl;;
// }

    algo(prs,0,ans,0);

// cout<<n-ans<<endl;
cout<<(n-ans)/2<<endl;
    // ll last=0;
    // if(last<(n-ans)/2)
    // {
    //     last=(n-ans)/2;
    // }
    // cout<<last<<endl;
    // cout<<(n-ans)/2<<endl;
  
}

