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


long long pow(long long num,long long degree,long long mod=-1)
{
    if(degree==0) return 1;
    if(degree==1) return num;
        long long ans=pow(num,degree/2,mod);
    if(degree&1)
    {
        if(mod>0) return (ans*ans*num)%mod;
        else return ans*ans*num;
    }
        if(mod>0)    return (ans*ans)%mod;
        return ans*ans;
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
void solve(ll tc);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
        solve(0);
    
    
    return 0;
}
void solve(ll tc)
{
    ll n;cin>>n;
    ll ans=0,mod=998244353;
    vector<ll> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }

    Sore(vec);
    vector<map<ll,ll>> mp(n+5);
    ans=accumulate(all(vec),0);
    
    for(ll i=0;i<n;i++)
    {
        ll balls=vec[i];
        
        for(ll k=n-1;k>=0;k--)
        {
            for(auto &[l,m]:mp[k])
            {
                ll cnt=0;
                ll rem=0;
                if(l>balls)
                {
                    cnt=balls;
                    rem=l-balls;
              
                    
                    
                    mp[k+1][rem]+=m;
                    ans=(ans+((l*m)%mod))%mod;
                    
                }
                else 
                {
                    cnt=(l+balls)/2;
                    if((l+balls)%2)
                    {
                        rem=1;
                        ans++;
                    }
                    mp[k+1][rem]+=m;
                    ll kk=(((l+balls)/2)*m)%mod;
                    ans=(ans+kk)%mod;
                    
                    
                }
                    ans=(ans+(((cnt*m)%mod)*(pow(2,n-i-1,mod)))%mod)%mod;
                    ll kk=(cnt*m)%mod;
                    ans=(ans-kk+mod)%mod;
                
            }

        }
        mp[0][balls]++;

    

    }



    cout<<ans%mod<<"\n";
    


}

