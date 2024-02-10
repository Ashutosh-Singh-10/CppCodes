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

void solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
ll findDist(vector<vector<ll>> &gr,ll curr,ll prev,ll target,ll distance)
{
    if(curr==target)
    {
        return distance;
    }
    for(auto &i:gr[curr])
    {
        if(i!=prev)
        {

            ll x=findDist(gr,i,curr,target,distance+1);
            if(x!=-1) return x;

        }
    }
    return -1;

}
void solve()
{

    ll n,temp;
    cin>>n; 
    vector<ll> abc;
    cin>>temp;
    abc.push_back(temp);
    cin>>temp;
    abc.push_back(temp);
    cin>>temp;
    abc.push_back(temp);


    vector<pair<ll,ll>> dist(3);
    vector<vector<ll>> gr(n+1);
    ll x,y;
    for(int i=0;i<n-1;i++)
    {
        cin>>x;
        cin>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
// cout<<"abc";
//     for(auto &i:abc)
//     {
//         cout<<i<<" ";
//     }

//     cout<<endl;
//     for(auto &i:gr)
//     {
//         for(auto &j:i)
//         {
//             cout<<j<<" ";
            
//         }
//         cout<<endl;
//     }
//     cout<<endl;
//     cout<<"graphcomp"<<endl;
    dist[0].first=findDist(gr,abc[0],-1,abc[1],0);
    dist[0].second=findDist(gr,abc[0],-1,abc[2],0);

    dist[1].first=findDist(gr,abc[1],-1,abc[2],0);
    dist[1].second=findDist(gr,abc[1],-1,abc[0],0);

    dist[2].first=findDist(gr,abc[2],-1,abc[0],0);
    dist[2].second=findDist(gr,abc[2],-1,abc[1],0);
    ll a=dist[0].first+dist[0].second;
    ll b=dist[1].first+dist[1].second;
    ll c=dist[2].first+dist[2].second;
    // cout<<"abcccc";
    // cout<<a<<"  "<<b<<"  "<<c<<endl;
    if(dist[0].second==1) 
    {
        cout<<'A'<<endl;
        return ;
    }
    // if(dist[1].second==1) 
    // {
    //     cout<<'B'<<endl;
    //     return ;
    // }
    if(a==b && b==c)
    {
        cout<<"DRAW"<<endl;
        return ;
    }
    if(a<b && a<c)
    {
        cout<<'A'<<endl;
        return ;
    }
    if(b<a && b<c)
    {
        cout<<'B'<<endl;
        return ;
    }
    if(c<a && c<b)
    {
        cout<<'C'<<endl;
        return ;
    }
    if(a==b)
    {
        cout<<'B'<<endl;
        return ;
    }
    if(c==b)
    {
        cout<<'C'<<endl;
        return ;
    }
    cout<<'A'<<endl;
    return ;
    // cout<<"HII";
    // cout<<endl;
    


// 3
// 3
// 1 2 3
// 2 1
// 3 1
// 3
// 2 3 1
// 2 1
// 3 1
// 3
// 3 1 2
// 2 1
// 3 1
}

