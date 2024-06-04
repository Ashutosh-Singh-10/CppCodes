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


ll mod=998244353;
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

    ll m,n;cin>>m>>n;
    vector<ll> vec;
    map<ll,vector<ll> >mp;
    ll sz=2<<(m-1);
    loop(i,0,m)
    {
        ll t;cin>>t;
        t--;
        vec.push_back(t);
        mp[t].push_back(i);
    }

    
    vector<vector<ll> > dp(sz,vector<ll>(2,0));
    for(int i=0;i<m;i++)
    {
            ll el=1ll<<i;
            ll tmp=sz-1;
            tmp=tmp|(1ll<<i);
            tmp=tmp^(1ll<<i);
            if(vec[i]==i)
            {
                tmp=sz-1;
            }
      
        dp[tmp][0]+=1;


    }


    for(int p=1;p<n;p++)    
    {
        loop(i,0,sz)
        {
            if(dp[i][(p+1)%2]==0)
            {
                continue;
            }
            
            for(int j=0;j<m;j++)
            {
                if((i&(1ll<<j))!=0)
                {
                    ll tmp=i;
                    tmp=tmp^(1<<j);
                    for(auto &k:mp[j])
                    {
                        tmp=tmp|(1ll<<k);
                    }



                    dp[tmp][(p)%2]=(dp[tmp][(p)%2]+dp[i][(p+1)%2])%mod;


                }
            }
            dp[i][(p+1)%2]=0;


        }
        // for(auto &i:dp)
        // {
        //     cout<<i[(p+1)%2]<<" ";
        //     i[(p+1)%2]=0;
            
        // }
        // cout<<endl;


        
    }
    ll ans=0;
    for(auto &i:dp)
    {
        ans=(ans+i[(n-1)%2])%mod;
        // cout<<i[(n-1)%2]<<" ";
    }

    cout<<ans;
    return ;

}
