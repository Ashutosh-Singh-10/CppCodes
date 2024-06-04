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



void solve(ll tc);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
        solve(0);
    
    
    return 0;
}

bool valid(ll a,ll mn,ll mx,ll s)
{

if(mn==mx)
{
    ll start=mn;
    if(mx==0)
    {
        cout<<-1;
        return;
    }
    
    
    while(start<=r)
    {
        if(start>=l)
        {
            k--;

        }
        if(k==0) 
        {
            cout<<start<<" ";
            return ;
        }
        start*=10;
        start+=mn;

    }

}

    ll pr=0;
    ll x=0,y=0;
    set<ll> st={2,3,5,7};
    while(a)
    {
        ll dig=a%10;
        if(dig==mx) x=1;
        if(dig==mn) y=1;
        if(st.count(dig))
        {
            pr+=dig;
        }
        else pr-=dig;
        a/=10;
    }
    if(abs(pr)<=s && x && y) return 1;
    return 0;
    
    

}
void solve(ll tc)
{
    ll l,r,k,s,mn,mx;
    cin>>l>>r>>k>>s>>mn>>mx;

    ll ans=0;
    for(ll i=l;i<=r;i++)
    {
        if(valid(i,mn,mx,s))
        {
            k--;
            if(k==0)
            {
                cout<<i;
                return;
            }
        }

    }
    cout<<-1<<endl;


}




































// #include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// // #ifndef ONLINE_JUDGE
// // #include "debug.h"
// // #else
// // #define dbg(x...)
// // #endif
// #define int long long
// #define endl '\n'
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
// /*
// You are given a range on the number line [L,R], where L and R are integers. You need to find the k

// th number within this range such that:

//     The minimum digit of the number is mn

// .
// The maximum digit of the number is mx
// .
// The absolute difference between the sum of prime digits and the sum of non-prime digits of the number is less than or equal to S

//     .

// Input

// The input consists of a single line containing six space-separated integers L
// , R, k, S, mn, and mx, representing the range [L,R], the k

// th number to find, the maximum difference allowed between the sum of prime digits and the sum of non-prime digits, the minimum digit, and the maximum digit respectively.

// Constraints:

//     1≤L≤R≤1018

// 0≤S≤105
// 1≤k≤R−L+1

// Output

// Output the k
// th number satisfying the conditions described above. If there is no such number, output −1.
// */
// int dp[20][2][2][2][9 * 18 * 4 + 5][2];
// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int L, R, k, S, mn, mx;
//     cin >> L >> R >> k >> S >> mn >> mx;
//     if (mn > mx)
//     {
//         assert(false);
//     }
//     int offset = 9 * 18 * 2;

//     auto get = [&](int x)
//     {
//         // dp[idx][tight][bool_mx][bool_mn][diff(prime-nonprime)][zero]
//         memset(dp, -1, sizeof dp);
//         string s = to_string(x);
//         function<int(int, int, int, int, int, int)> solve = [&](int idx, int tight, int bool_mx, int bool_mn, int diff, int nn_zero) -> int
//         {
//             assert(diff >= 0);
//             if (idx == s.size())
//             {
//                 if (abs(offset - diff) <= S and bool_mx and bool_mn and nn_zero)
//                     return 1LL;
//                 return 0LL;
//             }
//             int &ans = dp[idx][tight][bool_mx][bool_mn][diff + offset][nn_zero];
//             if (ans != -1)
//                 return ans;
//             ans = 0;
//             int limit = tight ? s[idx] - '0' : 9;
//             for (int i = mn; i <= min(mx, limit); i++)
//             {
//                 int new_diff = diff;
//                 if (i == 2 or i == 3 or i == 5 or i == 7)
//                     new_diff += i;
//                 else
//                     new_diff -= i;
//                 int new_mx = bool_mx | (i == mx);
//                 int new_mn = bool_mn | (i == mn);
//                 ans += solve(idx + 1, tight & (i == limit), new_mx, new_mn, new_diff, nn_zero | i);
//             }

//             return ans;
//         };
//         return solve(0, 1, 0, 0, offset, 0);
//     };
//     int left = get(L - 1);
//     auto check = [&](int num)
//     {
//         return get(num) - left >= k;
//     };
//     if (check(R) - check(L - 1) < k)
//     {
//         cout << -1 << endl;
//         return 0;
//     }
//     int low = L, high = R, ans = -1;
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (check(mid))
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     assert(ans != -1);
//     cout << ans << endl;
// }
