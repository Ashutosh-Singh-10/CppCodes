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

void topthree(vector<ll> &vec,unordered_set<ll> &st)
{
    ll x,y,z,m,n,o;
    if(vec[0]>=vec[1] && vec[0]>=vec[2])
    {
            x=0;
            m=vec[0];
        if(vec[1]>vec[2])
        {
            y=1;
            z=2;
            n=vec[1];
            o=vec[2];
        }
        else 
        {
            y=2;
            z=1;
            n=vec[2];
            o=vec[1];
        }
    }
    else if(vec[1]>=vec[0] && vec[1]>=vec[2])
    {
        x=1;
        m=vec[1];
        if(vec[0]>vec[2])
        {
            y=0;
            z=2;
            n=vec[0];
            o=vec[2];
        }
        else 
        {
            y=2;
            z=0;
            n=vec[2];
            o=vec[0];
        }

    }
    else 
    {
        x=2;
        m=vec[2];


        if(vec[0]>vec[1])
        {
            y=0;
            z=1;
            n=vec[0];
            o=vec[1];
        }
        else 
        {
            y=1;
            z=0;
            n=vec[1];
            o=vec[0];
        }

    }

    loop(i,3,vec.size())
    {
        if(vec[i]>=m)
        {
            z=y;
            y=x;
            x=i;
            
            o=n;
            n=m;
            m=vec[i];
            
        }
        else if(vec[i]>=n)
        {
                  z=y;
            y=i;
            
            o=n;
            n=vec[i];

        }
        else if(vec[i]>=o)
        {
            z=i;
            
            o=vec[i];
        }
    }

    st.insert(x);
    st.insert(y);
    st.insert(z);
    // cout<<m<<" "<<n<<" "<<o<<endl;
    // cout<<"  "<<x<<" "<<y<<" "<<z<<endl;

}
void solve()
{   
    ll n,temp;
    cin>>n;
    vector<ll> a,b,c;
    loop(i,0,n)
    {cin>>temp;
    a.push_back(temp);
    }
    loop(i,0,n)
    {cin>>temp;
    b.push_back(temp);
    }
    loop(i,0,n)
    {cin>>temp;
    c.push_back(temp);
    }
    unordered_set<ll> st;
    topthree(a,st);
    topthree(b,st);
    topthree(c,st);
    vector<vector<ll>> vec;
    for(auto &i:st)
    {
        vec.push_back({a[i],b[i],c[i]});
        
    }
    ll ans=0;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec.size();j++)
        {
            for(int k=0;k<vec.size();k++)
            {
                if(i!=k  && i!=j && j!=k)
                {
                    ans=max(vec[i][0]+vec[j][1]+vec[k][2],ans);
                }
            }
        }
    }
    cout<<ans<<endl;

    


  
}

