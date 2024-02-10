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
    ll n,temp;
    cin>>n;
    ll mn=LONG_LONG_MAX;
    vector<ll> vec;
    loop(i,0,n)
    {
        cin>>temp;
        mn=min(temp,mn);
        vec.pb(temp);
    }
    ll prev=vec[0];
 bool flag=1;
    for(auto &i:vec)
    {
        if(i<prev)
        { 
            flag=0;
            break;

        }
        prev=i;
    }
    if(flag==1)
    {
        cout<<0<<endl;
        return ;
    }



        flag=1;prev=vec[0];
    for(auto &i:vec)
    {
        if(i>prev)
        { 
            flag=0;
            break;

        }
        prev=i;
    }
    if(flag==1)
    {
        cout<<1<<endl;
        return ;
    }
    













    ll end=0;
    prev=vec[0];
    ll cnt=0;
    while(end<n)
    {
            if(vec[end]>=prev)
            {
                cnt++;
                
            }
            else cnt=1;
            prev=vec[end];
            end++;

    }
    flag=1;


    for(ll i=0;i<n-cnt;i++)
    {
        if(vec[i]<prev) 
        {
            flag=0;
            break;
        }
        prev=vec[i];
    }


    ll ans=LONG_LONG_MAX;
    if(flag==1)
    {
        ans=min(cnt,n-cnt+2);
 
    }














     end=n-1;
    prev=vec[end];
    cnt=0;
    while(end>=0)
    {
            if(vec[end]>=prev)
            {
                cnt++;
                
            }
            else cnt=1;
            prev=vec[end];
            end--;

    }
    flag=1;




  for(ll i=n-1;i>=cnt;i--)
    {
        if(vec[i]<prev) 
        {
            flag=0;
            break;
        }
        prev=vec[i];
    }


    if(flag==1)
    {
        ans=min(cnt+1,ans);
        ans=min(ans,n-cnt+1);
 
    }
    if(ans!=LONG_LONG_MAX)
    {
        cout<<ans<<endl;
        return ;
    }
    cout<<-1<<endl;



  







}

