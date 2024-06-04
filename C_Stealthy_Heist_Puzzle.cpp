//     #include <bits/stdc++.h>
//     using namespace std;
//     using std::cout;
//     using std::cin;
//     #define endl '\n'    
//     #define ll long long
//     #define loop(i,a,b) for(long long i=a;i<b;i++)
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
    
//         solve(0);
    
    
//     return 0;
// }
// void solve(ll tc)
// {
//     ll n;cin>>n;ll k;cin>>k;
//     vector<ll> vec;
//     loop(i,0,n)
//     {
//         ll t;cin>>t;
//         vec.push_back(t);
//     }
//     ll cnt=0;
//     int i=0;
//     ll ans=0;
//     while(vec[i]!=k)
//     {
//         cnt++;
//         if(vec[i]<k)
//         {
//             ans+=cnt;
//             cnt=0;
//         }
//         i++;
//     }
//     i=n-1;
//     cnt=0;
//     while(vec[i]!=k)
//     {
//         cnt++;
//         if(vec[i]<k)
//         {
//             ans+=cnt;
//             cnt=0;
                
//         }
//         i--;
//     }
//     cout<<ans<<"\n";

// }

    #include <bits/stdc++.h>
    using namespace std;
   
  int LIS(vector<int>& nums) {
        set<int> st;
        for(auto &i:nums)
        {
            auto it=st.lower_bound(i);
            if(it!=st.end()) st.erase(it);
            st.insert(i);
        }
        return st.size();
    }
void solve(int start,int end,vector<int> &vec,int &ans)
{
    reverse(vec.begin()+start,vec.begin()+end);
    ans=max(ans,LIS(vec));
    reverse(vec.begin()+start,vec.begin()+end);


}


int main()
{
    
    int n;
    cin>>n;
    vector<int> vec;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int t=0;
        cin>>t;
        vec.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            solve(i,j,vec,ans);
        }
    }
    cout<<ans;
 

   
    
    return 0;
}


