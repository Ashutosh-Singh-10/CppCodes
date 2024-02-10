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
ll pos(ll a,ll dis)
{
    for(ll i=a;i>=0;i--)
    {
        if(dis>0)
        {
            dis-=i;
        }
        else dis+=i;
    }
    if(dis==0) return 1;
    return 0;
}
void solve()
{
    ll a,b;
    cin>>a>>b;
    
    ll dis=abs(a-b);
    ll start=0,end=2*dis;

ll ans= LONG_LONG_MAX;
    while(start<=end)
    {
        ll mid=start+(end-start)/2;
        if(pos(mid,dis))
        {
            end=mid-1;
            ans=min(ans,mid);
        }
        else start=mid+1;

    }
    cout<<ans<<endl;
}
// ll getme(ll mid,ll dis)
// {
//     ll num=(mid*(mid+1))/2;
//     // ll
//     ll ans=mid;
//     if(num<=dis)
//      {
//      ans+=abs(dis-num)*2;
//      return ans;

//      }
//      else 
//      {
//         ll ex=num-dis;
//         ex-=mid/2;
//         ans+=ex*2;

//      }


//     return ans;
// }
// void solve()
// {   
//     ll n;
//     // cin>>n;
//     ll a,b;
//     cin>>a>>b;
//     ll dis=abs(a-b);
//     ll end=dis;
//     ll start=0;
//     ll ans=LONG_LONG_MAX;
//     // cout<<ans<<endl;
//     while(start<=end)
//     {
//         ll mid=start+(end-start)/2;
//         ll el=getme(mid,dis);
//         // cout<<mid<<" "<<el<<"    ";
//         ans=min(ans,el);
//         if((mid*(mid+1))/2>dis)
//         {
//             end=mid-1;

//         }
//         else start=mid+1;


//     }
//     // cout<<endl;
//     cout<<ans<<endl;
//     // cout<<endl;
//     // cout<<endl;

  
// }

    