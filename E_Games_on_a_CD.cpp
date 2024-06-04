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
    #ifndef ONLINE_JUDGE
    #include "debug.h"
    #else
    #define dbg(x...)
    #endif


ll m1=1e9+7;
ll m2=1e9+9;
void solve(ll tc);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve(0);
    return 0;
}
long long pow(long long num,long long degree,long long mod=-1)
{
    if(degree==0) return 1;
    if(degree==1) return num;
        long long ans=pow(num,degree/2,mod);
    if(degree&1)
    {
     return ((ans*ans)%mod*num)%mod;
    }
            return (ans*ans)%mod;
} 
long long Inv(long long num,long long degree,long long mod=-1)
{
    return pow(num,degree-2,mod);
}
long double  powerInverse(long long num,long long degree,long long mod=-1)
{
    long double ans=1/(double long)pow(num,degree,mod);
    return ans;
}

    // if(INFINITY==powerInverse(2,10000))cout<<"HII";
    // cout<<powerInverse(2,10000);
pair<ll,ll> hashit(string &tmp)
{
    ll a=0,b=0;
     loop(i,0,tmp.length())
    {
        a=(a*a)%m1;
        a=(a+tmp[i])%m1;
        b=(b*b)%m2;
        b=(b+tmp[i])%m2;
    }
    return {a,b};

}
pair<ll,ll> rangeHash(vector<pair<ll,ll>>&vec,ll start,ll end)
{
    if(start==0)
    {
        return vec[end];
    }
    start--;
    auto x=vec[start];
    auto y=vec[end];
    auto a=(y.first*pow(Inv(x.first,m1,m1),start-1))%m1;    
    auto b=(y.second*pow(Inv(x.second,m2,m2),start-1))%m2;    
    return {a,b};
}
void solve(ll tc)
{
    ll n;cin>>n;
    ll k;cin>>k;
    ll sz=n*k;
    string s;cin>>s;
    string tmp=s+s;
    vector<pair<ll,ll>> vec;
    ll a=0,b=0;
    loop(i,0,2*sz)
    {
        a=(a*a)%m1;
        a=(a+tmp[i])%m1;
        b=(b*b)%m2;
        b=(b+tmp[i])%m2;
        vec.push_back({a,b});
    }
    

    
    ll ds;cin>>ds;
    map<pair<ll,ll>,ll> mp;
    loop(i,0,ds)
    {
        string t;cin>>t;
        mp[hashit(t)]=i;
    }
    for(int i=0;i<n;i++)
    {
        dbg(rangeHash(vec,i,i));
    }
    ll curr=0;
    ll rem=10*k*k;
    while(rem)
    {
        if(curr>=sz)
        {
            curr=curr-sz;
        }
        vector<ll> ans;
        while(ans.size()<n)
        {
            auto hs=rangeHash(vec,curr,curr+k-1);
            cout<<curr<<"->"<<hs.first<<"  ";
            if(mp.count(hs)==0)break;
            ans.push_back(mp[hs]);
            curr+=k;
            if(curr>=sz) curr-=sz;
        }
        dbg(ans.size());
        if(ans.size()==n)
        {
            cout<<"YES"<<endl;
            for(auto &i:ans)
            {
                cout<<i<<" ";
            }
            return ;
        }
        ans.clear();
        curr++;
        rem--;
    }




    cout<<"NO";




    



    


    
}
