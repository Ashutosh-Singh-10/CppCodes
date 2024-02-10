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
    int t=0;
    cin>>t;
    while(t--)
    {
        solve();
    }


return 0;

}

int algo(string &s,int n)
{
    int cnt=0;
    int a=0,b=0;
    int wa=0,wb=0;
    char lst='C';
    while(cnt<s.size())
    {
        
        if(s[cnt]=='A')
        {
            a++;
        }
        else b++;
       if(n==a || n==b)
       {
            if(a>b)
            {
                wa++;
                lst='A';

            }
            else 
            {
                wb++;
                lst='B';
            }
            a=0;b=0;

       }
       
        cnt++;
    }
    if(b || a) return -1;
    if(wa-wb ==1 && lst=='A') return 1;
    if(wb-wa==1 && lst=='B') return 2;
    return -1;
}

void solve()
{

int n;cin>>n;
string s;
cin>>s;
cout<<s[s.size()-1]<<endl   ;
// int val=0;
// int wa=0;int wb=0;
//     // cout<<"#########";
// for(int i=1;i<=s.length();i++)
// {
//     val=algo(s,i);
//     if(val==1) wa++;
//     else if(val==2) wb++;
//     // if(wa && wb)
//     // {
//     //     cout<<"?"<<endl;return ;
//     // }
// }

// if(wa && wb==0) cout<<"A";
// else if(wb && wa==0) cout<<"B";
// else cout<<"?";
// cout<<endl;
// // cout<<"&&&&&&"<<wa<<"  "<<wb<<endl;
// // cout<<endl;
// return ;




}

