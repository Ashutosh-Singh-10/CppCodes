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
long long pow(long long num,long long degree,long long mod=-1)
{
    if(degree==0) return 1;
    if(degree==1) return num;
        long long ans=pow(num,degree/2,mod);
    if(degree&1)
    {
         return (((ans*ans)%mod)*num)%mod;
        
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
void solve(ll tc)
{
    ll n;cin>>n;ll k;cin>>k;
    ll mod=1e9+7;
    loop(i,0,k)
    {
        ll a,b;cin>>a>>b;
        if(a==b) n--;
        else n-=2;
    }
    if(n<=1)
    {
        cout<<1<<"\n";
        return ;
    }
    ll ans=1;

    ll up=1;
    ll down=1;
    ll lst =1;
    for(ll i=2;i<=n;i+=2)
    {
        up=(((up*(n-i+2))%mod)*(n-i+1))%mod;
        lst=(lst*(i-1))%mod;
        
        down=(((down*(i-1))%mod)*(i))%mod;
    //  cout<<down<<" "<<up<<" )";

        ll per=(up*Inv(down,mod,mod))%mod;
        // cout<<per<<" ";

        ll temp=((ll)per*(ll)pow(2,i/2,mod))%mod;       
        temp=(temp*lst)%mod;
        ans=(ans+temp)%mod;

    }
    cout<<ans<<"\n";


}
