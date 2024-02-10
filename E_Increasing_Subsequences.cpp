//         #include <bits/stdc++.h>
//         using namespace std;
//         using std::cout;
//         using std::cin;
//         using std::endl;    
//         #define ll long long
        
//         #define loop(i,a,b) for(int i=a;i<b;i++)
//         #define longloop(i,a,b) for(long long i=a;i<b;i++)
//         #define roop(i,a,b) for(int i=a-1;i>=b;i--)
//         #define all(p) p.begin(),p.end()
//         #define pb(p) push_back(p);
//         int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
//         template<class T> using _pq = priority_queue<T>;
//         template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
//         template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
//         template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}

//         template<class T> void vec_out(vector<T> &p,int ty=0){
//         if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
//         else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}

//         template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
//         template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;} 

//         template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
//         template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
//         template<class T> T vec_sum(vector<T> &a){assert(!a.empty());T ans=a[0]-a[0];for(auto &x:a) ans+=x;return ans;}

//         template<class T>  void matcout(vector<vector<T>> &a){for(auto &i:a){ for(auto &j:i){cout<<j<<"  ";}cout<<"\n";}cout<<"\n";}

//         template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
//         template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}

// void solve();
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }
// ll give(ll i)
// {
// }
// ll pos()
// void solve()

// {   
//     ll n;
//     cin>>n;
    
//     ll cnt=0;
//     ll cur=200;
//     ll ex=0;
//     vector<ll> vec;
//     ll cmx=LONG_LONG_MIN;
//     // loop(i,max((ll)0,n-199),n+1)
//     // {
//     //     ll el=give(i);
//     //     if(el<cmx)
//     //     {
//     //         ans=i;
//     //     }

//     // }
   
   
    

  
// }

    

    #include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
// #include "debug.h"
#else
#define dbg(x...)
#endif
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    auto solve = [&](int tc)
    {
        int n;
        cin >> n;
        n--;
        int org = n;
        vector<int> ans = {0};
        vector<int> dp(205, 0);
        // auto calc = [&]()
        // {
        //     int ans = 0;
        //     for (int i = 0; i < dp.size(); i++)
        //     {
        //         ans += dp[i];
        //     }
        //     assert(ans == org);
        // };
        while (n > 0)
        {
            int sz = ans.size();
            int pref = 1, val = sz;
            for (int i = 0; i < sz; i++)
            {
                if (pref + dp[i] > n)
                {
                    break;
                }
                val = i + 1;
                pref += dp[i];
            }
            n -= pref;
            ans.push_back(val);
            dp[sz] = pref;
        }



        assert(ans.size() <= 200);
        cout << ans.size() - 1 << '\n';
        for (int i = 1; i < ans.size(); i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    };
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }
}


