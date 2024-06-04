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




class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        ll mod=1e9+7;
        ll mx=*max_element(all(nums));
        ll mn=*min_element(all(nums));
        ll tot=0;
        for(auto &i:nums) tot+=mx-i;


        multiset<ll> st;
        for(auto &i:nums)
        {
            st.insert(i);
        }
        ll flag=0;
        if(tot%2)
        {
            flag=1;
            auto x=*st.begin();
            st.erase(st.begin());
            st.insert(x+1);
        }
        ll coup=0;
        while(st.begin()!=st.rbegin() && cost<ans)
        {
            auto it=*st.begin();
            st.erase(st.begin());
            auto it2=*st.begin();
            st.erase(st.begin());
            if(st.rbegin==it2) break;


            ll toadd=max(*st.rbegin()-it2,1);
            st.insert(it1+toadd);
            st.insert(it2+toadd);
            coup+=toadd;
            if(*st.rbegin()>mx)
            {
                tot+=(st.rbegin()-mx)*n;
            }
            cost=(coup*cost2)%mod+((tot-coup*2)*cost1)%mod;
            ans=min(cost,ans);
            

        }

        return ans;


    
    }
};














