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

template<typename T1> void printIt(T1 t1){cout<<t1<<"\n";}
template<typename T1, typename... T2>
void printIt(T1 t1,T2... t2) {cout<<t1<<" , "; printIt(t2...);}
// getbits setbits countbits ispoweroftwo  shiftbits iota

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include<iostream>
// Set
//Can use pair of integer where .second can be index of array where .first was originally present
template <class T> using Ordered_set = tree<T, null_type, 
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// Syntax
// Ordered_set <pair<int,int> > a; or Ordered_set<int> a;

// Multiset
// Not recommended Can have unwanted behaviour 
// template <class T> using multi_ordered_set = tree<T, null_type,
// less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}

void solve()
{
    ll n;cin>>n;
    string s; cin>>s;

    Ordered_set<ll> right,left;
    ll dis=0;
    loop(i,0,n)
    {
        if(s[i]=='<')
        {
            dis+=i+1;
            right.insert(dis);
        }
    }
    roop(i,n,0)
    {
        if(s[i]=='>')
        {
            dis+=n-i;
            left.insert(dis);
            
        }

    }
    // for(auto &i:left) cout<<i<<" ";cout<<endl;
    // for(auto &i:right) cout<<i<<" ";cout<<endl;
    ll lcnt=0;
    vector<ll> ans;
    loop(i,0,n)
    {
        
        if(s[i]=='<')
        {
            if(lcnt<=right.size())
            {
                if(left.size()==0) 
                {
                    ans.push_back(i+1); 
                    continue;
                }

                if(lcnt<=right.size())
                {
                    ll val= 




                }
                else 
                {

                }





                


            }
            else 
            {
             
            }


        }
        else 
        {


        }
    }
    // for(auto &i:ans) cout<<i<<" ";
    cout<<endl;



}



