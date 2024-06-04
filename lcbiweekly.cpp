    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
    #define endl '\n'    
    #define ll long long
    #define loop(i,a,b) for(long long i=a;i<b;i++)
    #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
    #define all(p) p.begin(),p.end()
    #define pb(p) push_back(p);
    long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
    template<class T> using _pq = priority_queue<T>;
    template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
    template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
    template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}


vector<vector<ll>> vec;
void rec(vector<int> & coins,ll i ,ll lcm,ll cnt)
{
    rec(coins,i+1,lcm,cnt);
    lcm=(coins[i]*lcm)/__gcd(lcm,(ll)coins[i]);
    vec[cnt+1].push_back(lcm);
    rec(coins,i+1,lcm,cnt+1);
}
bool solve(ll  k,ll req)
{
    ll ans=0;
    for(int i=1;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            if(i%2)
            {
                ans+=k/vec[i][j];

            }
            else
            {
                ans-=k/vec[i][j];

            }
        }
    }
    if(ans>=req) return 1;
    return 0;

}
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        vec.resize(coins.size()+1);
        rec(coins,0,1,0);
        ll low=1,high=1e9,ans=1e9;;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            if(solve(mid,k))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};