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
ll mod=998244353;
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

// bool check(vector<ll> &vec,unordered_map<ll,ll>&mp,int start,int end,int curr)
// {
//     unordered_set<int> vis;

//     queue<ll> qu;
// }
ll tellme(vector<ll> &vec,ll start,ll end,unordered_map<ll,ll> mp)
{

// cout<<"HII";
    // end--;
ll a=start,b=end;
    unordered_set<ll> st;
    ll mn ;
    ll out=0,flag;
    loop(i,start,end)
    {
        st.insert(vec[i]);
        mn=end;
        flag=1;
        loop(j,i+1,end)
        {
            if(vec[i]==vec[j])
            {
                mn=j;
            }
            st.insert(vec[j]);
                // cout<<" Game over!!"<<st.size()<<"   "<<j<<"  "<<i<<"  "<<end<<endl;
            if(st.size()*2==j-i+1)
            {
                out+=st.size();
                i=j;
                flag=0;
            }
        }
        // if(flag==1)
        // {
        //     end=mn;
        // }
        st.clear();
    }

    ll ans=b-a+1-(2*out);
    
// cout<<"THe initial"<<ans<<"out =>"<<out<<endl;
    // ans=pow(2,ans);

    
    return ans;
        
            
            

    

}
void solve()
{   
    ll n,temp;
    cin>>n;
    vector<ll> vec;
    loop(i,0,2*n)
    {
        cin>>temp;
        vec.push_back(temp);
    }
    unordered_map<ll,ll> mp;
    ll start=0,ans=1,tot=0;
    loop(i,0,2*n)
    {
        if(mp.count(vec[i])==0)
        mp[vec[i]]=i;

        // cout<<"size check"<<mp.size()<<"  "<<i-start+1<<endl;
        if(mp.size()*2==i-start+1)
        {
            ll z=tellme(vec,start,i,mp);
            ans=(ans*z)%mod;
            // cout<<z<<endl;
            start=i+1;
            tot++;
            mp.clear();
        }

    }
    cout<<tot<<" "<<ans<<endl;
    return ;

  
}

