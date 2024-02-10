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
   
        solve();
    
    return 0;
}


bool possible(vector<int> &leads,vector<int> &tp,int x,int n)
{

    vector<int> reserve(n,0);
    for(int i=0;i<tp.size()-1;i++)
    {
        int val=1;
        if(reserve[tp[i]]>x)
        {
            val+=reserve[i]-x;
        }
        reserve[leads[tp[i]]]+=val;
        
        
    }
    if(reserve[0]>x) return 0;
    return 1;
    
}
void solve()
{

    int n,temp;
    cin>>n;
    vector<int> cnt(n);
    vector<int> vec;
    vec.push_back(-1);
    loop(i,0,n-1)
    {
        cin>>temp;
        vec.push_back(temp-1);
        cnt[temp-1]++;
    }
    for(auto &i:cnt) cout<<i<<" ";
    cout<<endl;
    // vector<int> vec;
    queue<int> qu;
    loop(i,0,n)
    {
        if(cnt[i]==0)
        {
            qu.push(i);
        }
    }
    cout<<"HII";
    vector<int> tp;
    while(qu.size())
    {
        tp.push_back(qu.front());
        cnt[vec[qu.front()]]--;
        if(cnt[vec[qu.front()]]==0)
        {
            qu.push(vec[qu.front()]);
        }
        qu.pop();
    }
    for(auto &i:tp)
    {
        cout<<i<<" ";
    }
    return ;

}

