        #include <bits/stdc++.h>
        using namespace std;
//         using std::cout;
//         using std::cin;
//         #define endl '\n'    
//         #define ll long long
//         #define loop(i,a,b) for(long long i=a;i<b;i++)
//         #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
//         #define all(p) p.begin(),p.end()
//         #define pb(p) push_back(p);
//         long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
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

// template<typename T1> void printIt(T1 t1){cout<<t1<<"\n";}
// template<typename T1, typename... T2>
// void printIt(T1 t1,T2... t2) {cout<<t1<<" , "; printIt(t2...);}
// // getbits setbits countbits ispoweroftwo  shiftbits iota



// void solve();
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }
// void solve()
// {
//     ll n,k;cin>>n>>k;
//     vector<ll> vec;
//     loop(i,0,n)
//     {
//         ll t;cin>>t;
//         vec.push_back(t);
//     }
//     ll val=vec[k-1];
//     int flag=0;

//     for(int i=0;i<k-1;i++)
//     {
//         if(vec[i]>val)
//         {
//             flag=1;
//             break;
//         }
//     }
//     if(flag==0)
//     {
//         ll ans=k-1;
//         for(int i=k;i<n;i++)
//         {
//             if(val<vec[i])
//             {
//                 break;
//             }
//             ans++;
//         }
//         cout<<ans<<"\n";
//         return ;
//     }
    
    
// ll cnt=0;
// ll ans=0;
// ll ex=0;
// int i;
// for( i=0;i<k-1;i++)
// {
//     if(vec[i]<val)
//     {
//         cnt++;
//     }
//     else break;
// }
// ans=cnt-1;
// cnt=0;
// if(i<k-1)
// {
//     for(int j=i+1;j<k-1;j++)
//     {
//         if(vec[j]<val)
//         {
//             cnt++;
//         }
//         else break;
//     }

// }
// if(i!=0)
// {
//     cnt++;
// }
// ans=max(ans,cnt);
// cout<<ans<<"\n";
    
   
// }


// C++ program to print all prime factors 
#include <bits/stdc++.h>
using namespace std;

// A function to print all prime 
// factors of a given number n 
vector<int>  prime(int n) 
{   
    int i=2;
    vector<int> ans;
    while(i*i<=n)
    {
        if(n%i==0)
        {
            ans.push_back(i);
        }
        while(n%i==0)
        {
            n/=i;
        }
        i++;
    }
    if(n>1)
    {
        ans.push_back(n);

    }
    return ans;
} 
int fact(int n)
{
    if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int   solve(vector<int> &a)
{  
    long long mod=1e9+7;
    vector<long long> ret;
    long long ans=0;
    for(auto &i:a)
    {
        auto vec=prime(i);
        long long n=vec.size(); 
        vector<long long> bits(32,0);
        for(auto &j:vec)
        {
            for(long long bt=0;bt<20;bt++)
            {
                if(j & ((long long)1<<bt))
                {
                    bits[bt]++;
                }

            }
        }
        for(long long i=0;i<=20;i++)
        {
            long long j=1;            
            while(j<=bits[i])
            {
                ans=(ans+(nCr(n,j)*(1<<i))%mod)%mod;
                j+=2;
            }
            
        }
    }
    return ans;
}


int main()
{
    // vector<int> a={10,45};
    vector<int> a={3,7};
    // vector<int> b={2,5,7,3,2,7};

    cout<<nCr(40,20);
    // cout<<solve(a);
    return 0;
    
}