#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(p) p.begin(),p.end()
#define pb(p) push_back(p);
int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
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

void solve(int );
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve( t);
    }
    return 0;
}

// ll binary_search(vector<ll> & vec,ll element)
//     {
//         if(element<=vec[0]) return 0;
//         ll start=1,end=vec.size()-1,mid;
//         while(start<=end)
//         {
//             mid=(start+end)/2;
//             if(vec[mid]>=element && vec[mid-1]<element)
//             {
//                 return mid;
//             }
//             else if(vec[mid]>=element)
//             {
//                 end=mid-1;
//             }
//             else start=mid+1;
//         }
//         return mid;
//     }
//     void lastel(vector<ll>& nums,vector<ll> &vec) {

        
//         if (nums.size()==0) return ;
//         vec.push_back(nums[0]);
//         // vector<int> vec={nums[0]};.
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]>vec[vec.size()-1])
//             {
//                 vec.push_back(nums[i]);
                
//             }
//             else {
//                 vec[binary_search(vec,nums[i])]=nums[i];
//             }

//         }
//         return ;

//     }


void solve(int t)
{
    ll m,n;
    cin>>m;
    cin>>n;
ll temp=0;
vector<ll> a,b,ans,lis;
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        a.push_back(temp);

    }
    for(ll i=0;i<n;i++)
    {
        cin>>temp;
        b.push_back(temp);
    }
    Sore(b);
    ll idx=0;
    for(auto &i:a)
    {
        while(idx<b.size() && b[idx]>i)
        {
            cout<<b[idx]<<" ";
            idx++;
        }
        cout<<i<<" ";

    }
    while(idx<b.size())
    {
        cout<<b[idx]<<"  ";
        idx++;
    }
    cout<<"\n";
//     lastel(a,lis);
//     Sore(b);
//     ll cnt=0;
//     ll index=0;
//     for(ll i=0;i<m;i++)
//     {
//         if(index<lis.size() && lis[index]==a[i])
//         {
//             while(cnt<b.size() && a[i]<=b[cnt] )
//             {
//                 ans.push_back(b[cnt]);
//                 cnt++;

//             }
//             index++;

//         }
//         ans.push_back(a[i]);

//     }
//     while(cnt<b.size())
//     {
//         ans.push_back(b[cnt]);
//         cnt++;
//     }

//     for(auto &i:ans)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;

// if(t==731)
// {
//     for(auto &i:a) cout<<i<<"  ";
//     cout<<endl;
//     for(auto &i:b) cout<<i<<"  ";
//     cout<<endl;
// }
    


}


