    #include <bits/stdc++.h>
    using namespace std;
//     using std::cout;
//     using std::cin;
//     #ifndef ONLINE_JUDGE
//     #include "debug.h"
//     #else
//     #define dbg(x...)
//     #endif


//     #define endl '\n'    
    #define ll long long
    #define loop(i,a,b) for(long long i=a;i<b;i++)
//     #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
//     #define all(p) p.begin(),p.end()
//     #define pb(p) push_back(p);
//     long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
//     template<class T> using _pq = priority_queue<T>;
//     template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
//     template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
//     template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}



// void solve(ll tc);
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     ll t;
//     cin>>t;
//     loop(i,0,t)
//     {
//         solve(i);
//     }
    
//     return 0;
// }
// void solve(ll tc)
// {
//     ll n;cin>>n;
// }

int fun(vector<int> &a,int diff,int k)
{
    int n=a.size();
    int ans=0;
    for(int i=0;i<n/2;i++)
    {
        if(abs(a[i]-a[n-i-1])!=diff)
        {
            int x=max(a[i],a[n-i-1]);
            int y=min(a[i],a[n-i-1]);
            if(x-1>=diff)
            {
                ans++;
            }
            else if(k-y>=diff)
            {
                ans++;
            }
            else 
            {
                ans+=2;
            }
            
        }
        

    }
    return ans;
}
int solve(int n, vector<int> a,int k)
{
    map<int,int>mp,tp;
    int ans=n;
    for(int i=0;i<n/2;i++)
    {
        mp[abs(a[i]-a[n-1-i])]++;
    }
    for(auto &i:mp)
    {
        if(tp.count(i.second))
        {
            tp[i.second]=min(i.first,tp[i.second]);

        }
        else 
        {
            tp[i.second]=i.first;
        }
    }
    for(auto &i:tp)
    {
        ans=min(ans,fun(a,i.second,k));

    }
    return ans;
}
int main()
{
    int n;cin>>n;
    vector<int> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }
    int k;cin>>k;
    cout<<solve(n,vec,k);
    return 0;
}



int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // (gcd(a[i],k))%k = K * m /(gcd(b[j],k)%k
    // gcd(a[i],k)= multiples of k/gcd(b[j],k)
    // other_part=k/gcd(b[j],k) --> multiples of other_part
    vector<int> dp(1e5 + 1, 0);
    for (auto x : a)
    {
        dp[__gcd(x, k) % k]++;
    }
    for (int i = 1; i <= 1e5; i++)
    {
        for (int j = i + i; j <= 1e5; j += i)
        {
            dp[i] += dp[j];
        }
    }
    int ans = 0;
    for (auto x : b)
    {
        int other = __gcd(x, k) % k;
        if (k == 0)
        {
            ans += n;
            continue;
        }
        else
        {
            other = k / other;
            ans += dp[other];
        }
    }
    cout << ans << endl;