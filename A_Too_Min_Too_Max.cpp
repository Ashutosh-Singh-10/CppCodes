// //         #include <bits/stdc++.h>
// //         using namespace std;
// //         using std::cout;
// //         using std::cin;
// //         #define endl '\n'    
// //         #define ll long long
// //         #define loop(i,a,b) for(long long i=a;i<b;i++)
// //         #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
// //         #define all(p) p.begin(),p.end()
// //         #define pb(p) push_back(p);
// //         long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
// //         template<class T> using _pq = priority_queue<T>;
// //         template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
// //         template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
// //         template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}

// //         template<class T> void vec_out(vector<T> &p,int ty=0){
// //         if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
// //         else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}

// //         template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
// //         template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;} 

// //         template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
// //         template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
// //         template<class T> T vec_sum(vector<T> &a){assert(!a.empty());T ans=a[0]-a[0];for(auto &x:a) ans+=x;return ans;}

// //         template<class T>  void matcout(vector<vector<T>> &a){for(auto &i:a){ for(auto &j:i){cout<<j<<"  ";}cout<<"\n";}cout<<"\n";}

// //         template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
// //         template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}

// // template<typename T1> void printIt(T1 t1){cout<<t1<<"\n";}
// // template<typename T1, typename... T2>
// // void printIt(T1 t1,T2... t2) {cout<<t1<<" , "; printIt(t2...);}
// // // getbits setbits countbits ispoweroftwo  shiftbits iota



// // void solve();
// // int main()
// // {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0); cout.tie(0);
// //     ll t;
// //     cin>>t;
// //     while(t--)
// //     {
// //         solve();
// //     }
    
// //     return 0;
// // }

// // void solve()
// // {
// //     ll n;cin>>n;
// //     multiset<ll> st;
// //     loop(i,0,n)
// //     {
// //         ll t;
// //         cin>>t;
// //         st.insert(t);

// //     }

// // ll a=*st.begin();
// // auto it=st.begin();
// // it++;
// // ll b=*it;
// // it=st.end();
// // it--;
// // ll x=*it;
// // it--;
// // ll y=*it;
// // ll ans=abs(x-a) + abs(x-b);
// // ans+=abs(y-a)+abs(y-b);
// // cout<<ans<<"\n";







    
// // }

//         #include <bits/stdc++.h>
//         using namespace std;
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
//     vector<vector<int>> query;
//     set<int> st;
//     vector<int> anss;
//     for(auto &i:query)
//     {
//         if(i[0]==0)
//         {
//             st.insert(i[1]);

//         }
//         else 
//         {
//             if(st.count(i[1]))
//             {
//                 anss.push_back(1);
//                 st.erase(i[1]);

//             }
//             else anss.push_back(0);
//         }
//     }
//     return anss;
// }


#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> cat,vector<int> price)
{
    map<long long,long long> mp;
    
    multiset<int> st;
    for(int i=0;i<cat.size();i++)
    {
        if(mp.count(cat[i]))
        {
            mp[cat[i]]=min(mp[cat[i]],(long long)price[i]);
        }
        else mp[cat[i]]=price[i];
    }
    for(auto &i:mp) st.insert(i.second);
    

    long long ans=0;
    long long cnt=0;  
    for(auto &i:st)
    {
        cnt++;
        ans+=cnt*i;
    }
    for(int i=0;i<cat.size();i++)
    {
        if( mp.count(cat[i]) && mp[cat[i]]==price[i] )
        {
            mp.erase(cat[i]);

        }
        else 
        {
            ans+=(longprice[i]*cnt;
        }

    }
    return ans;

    

}

int main()
{
    vector<int> a={1,2,3,4,5,6,7,8,9};
    vector<int> low={1,2,90};
    vector<int> high={4,7,100};
    cout<<solve(
        {3,1,2,3},
        {2,1,4,4}
    );

 
return 0;
}
