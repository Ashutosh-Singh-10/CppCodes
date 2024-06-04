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



void solve(ll tc);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    loop(i,0,t)
    {
        solve(i);
    }
    
    return 0;
}
void solve(ll tc)
{
    ll k, n;cin>>n>>k;
    vector<ll> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }
    if(k==0)
    {
        ll ans=accumulate(all(vec),0LL);
        cout<<ans<<endl;
        return ;
    }
    if(k>=n-1)
    {
        ll mn=*min_element(all(vec));
        cout<<mn*n<<"\n";
        return ;

    }
    if(vec.size()==1)
    {
        cout<<vec[0]<<"\n";
        return ;
    }

    vector<vector<ll>>dp(n+1,vector<ll>(k+1,LONG_LONG_MAX/20));
    loop(i,0,k+1)
    {
        dp[0][i]=0;
    }

    loop(i,1,n+1)
    {

        
        ll start=i;
        ll mn=vec[i-1];
        for(ll j=0;j<=k && j+i<=n;j++)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]+vec[i-1]);
            mn=min(mn,vec[j+i-1]);
            

            for(ll p=0;p<=k;p++)
            {
                if(p+j<=k)
                {

                    dp[j+i][p+j]=min(   dp[i-1][p]+((j+1)*mn),    dp[j+i][p+j]);

                    

                }
                
            }
        }


    }
 
    ll sum=accumulate(vec.begin(),vec.end(),0LL);
    loop(i,0,k+1)
    {
        sum=min(sum,dp[n][i]);
    }
    cout<<sum<<"\n";
}
