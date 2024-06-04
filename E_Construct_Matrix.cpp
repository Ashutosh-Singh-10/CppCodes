// // #include <bits/stdc++.h>
// // using namespace std;
// // using std::cout;
// // using std::cin;
// // using std::endl;
// // #define ll long long
// // #define loop(i,a,b) for(int i=a;i<b;i++)
// // #define longloop(i,a,b) for(long long i=a;i<b;i++)
// // #define roop(i,a,b) for(int i=a-1;i>=b;i--)
// // #define all(p) p.begin(),p.end()
// // #define pb(p) push_back(p);
// // int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
// // template<class T> using _pq = priority_queue<T>;
// // template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
// // template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
// // template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}

// // template<class T> void vec_out(vector<T> &p,int ty=0){
// // if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
// // else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}

// // template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
// // template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;} 

// // template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
// // template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
// // template<class T> T vec_sum(vector<T> &a){assert(!a.empty());T ans=a[0]-a[0];for(auto &x:a) ans+=x;return ans;}

// // template<class T>  void matcout(vector<vector<T>> &a){for(auto &i:a){ for(auto &j:i){cout<<j<<"  ";}cout<<"\n";}cout<<"\n";}

// // template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
// // template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}

// // void solve();
// // int main()
// // {
// //     int t;
// //     cin>>t;
// //     while(t--)
// //     {
// //         solve();
// //     }
// //     return 0;
// // }
// // void solve()
// // {   
// //     // cout<<"HII";
// //     ll n,k;
// //     cin>>n;
// //     cin>>k;

// //     if(k%n!=0)
// //     {
// //         cout<<"No"<<endl;
// //         return ;
// //     }
  
// //     cout<<"Yes"<<endl;
// //     int mot=k/n;



// //     loop(i,0,n)
// //     {
// //         int ult=n-i-mot;
// //         loop(j,0,n)
// //         {
            
// //             if(j>=i)
// //             {
// //                 if((j-i)<mot)
// //                 {
// //                     cout<<1;
// //                 }
// //                 else cout<<0;

// //             }
// //             else 
// //             {
                
// //                 if(ult<0)
// //                 {
// //                     cout<<1;
// //                     ult++;
// //                 }
// //                 else
// //                 cout<<0;

// //             }
// //             cout<<" ";
// //         }
// //         cout<<endl;
// //     }

  
// // }

// //qwq
// //__builtin_popcountll
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define rep(i,a,b) for(ll i=a;i<=b;++i)
// #define per(i,a,b) for(ll i=a;i>=b;--i)
// #define endl '\n'
// const ll N=200005,mod=998244353,G=3,GI=(mod+1)/3;
// ll t,n,k,a[1005][1005];
// void car(ll x)
// {
    
//     if(k%4==0)
//                 {
//                     ll cnt=k/4;
//                     for(ll i=1;i<=n;i+=2)
//                     {
//                         if(cnt==0)break;
//                         for(ll j=1;j<=n;j+=2)
//                         {
//                             if(cnt==0)break;
//                             --cnt;
//                             a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=x;
//                         }
//                     }
//                     cout<<"Yes"<<endl;
//                     for(ll i=1;i<=n;++i)
//                         {
//                             for(ll j=1;j<=n;++j)cout<<a[i][j]<<" ";
//                             cout<<endl;
//                         }
//                 }
//                 else
//                 {
//                         ll cnt=(k-6)/4;
//                         for(ll i=1;i<=n;i+=2)
//                         {
//                             if(cnt==0)break;
//                             for(ll j=1;j<=n;j+=2)
//                             {
//                                 if(cnt==0)break;
//                                 --cnt;
//                                 a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=x;
//                             }
//                         }
//                         a[n][n]=a[n][n-2]=a[n-1][n]=a[n-1][n-1]=a[n-2][n-2]=a[n-2][n-1]=x;
//                         cout<<"Yes"<<endl;
//                         for(ll i=1;i<=n;++i)
//                         {
//                             for(ll j=1;j<=n;++j)cout<<a[i][j]<<" ";
//                             cout<<endl;
//                         }

//                 }
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin>>t;
//     while(t--)
//     {
//         cin>>n>>k;
//         for(ll i=1;i<=n;++i)for(ll j=1;j<=n;++j)a[i][j]=0;
//         if(k%2)cout<<"No"<<endl;
//         else
//         {
//             if(n==2)
//             {
//                 if(k==0)cout<<"Yes\n0 0\n0 0\n";
//                 else if(k==2)cout<<"Yes\n1 0\n0 1\n";
//                 else if(k==4)cout<<"Yes\n1 1\n1 1\n";
//             }
//             else
//             {
//                 if(k==2||k==n*n-2)
//                 {
//                     cout<<"No"<<endl;
//                     continue;
//                 }
//                 if(k<=n*n/2)
//                 {
//                     car(1);
//                 }
//                 else
//                 {
//                     k=n*n-k;
//                     for(ll i=1;i<=n;++i)for(ll j=1;j<=n;++j)a[i][j]=1;
//                     car(0);
//                 }

//             }
//         }

//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
// #include "coding.h"
#else
#define dbg(x...)
#endif
#define nl "\n"
#define ll long long int
void __solve_testcase(int test_case)
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << "Yes" << nl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << 0 << " ";
            }
            cout << nl;
        }
        return;
    }
    if ((k & 1) || k==2 || k==(n*n)-2)
    {
        cout << "No" << nl;
        return;
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    if (k % n == 0)
    {
        cout << "Yes" << nl;
        int x = k / n;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (x--)
            {
                a[i][j] = 1;
                j = (j + 1) % n;
            }
            x = k / n;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << a[i][n - 1] << nl;
        }
        return;
    }
    int kk = k;
    if (k % 4 == 0)
    {
        cout << "Yes" << nl;
        // int i = 0, j = 0;
        // place 2 1s in each row starting from 0,0
        int i = 0, j = 0;
        while (k)
        {
            a[i][j] = 1;
            a[i][j + 1] = 1;
            i += 1;
            if (i >= n)
            {
                i = 0;
                j += 2;
            }
            k -= 2;
        }
        // dbg(a);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << a[i][n - 1] << nl;
        }
    }
    else
    {
        cout << "No" << nl;
        return;
    }
    k = kk;
    set<int> row;
    for (int i = 0; i < n; i++)
    {
        int xr = 0;
        for (int j = 0; j < n; j++)
        {
            xr ^= a[i][j];
        }
        row.insert(xr);
    }
    assert(row.size() == 1);
    set<int> col;
    for (int i = 0; i < n; i++)
    {
        int xc = 0;
        for (int j = 0; j < n; j++)
        {
            xc ^= a[j][i];
        }
        col.insert(xc);
    }
    assert(col.size() == 1);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
    }
    assert(sum == k);
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int no_of_testcase = 1;
    cin >> no_of_testcase;
    for (int testcase = 1; testcase <= no_of_testcase; testcase++)
    {
        __solve_testcase(testcase);
    }
    return 0;
}