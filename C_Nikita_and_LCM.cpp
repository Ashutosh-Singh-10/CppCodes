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
void factor(vector<map<ll,ll>>&vec,ll x)
{
   
   ll i=2;
   while(i*i<=x)
   {
        while(x%i==0)
        {
            x/=i;
            vec.back()[i]++;
            
        }
        i++;
        
    
   }
   if(x>1)
   {
        vec.back()[x]++;
   }
}
ll check(vector<ll> &arr,ll n)
{
    ll cnt=0;
    ll lcm=1;
    for(auto&i:arr)
    {
        if(n%i==0)
        {
            cnt++;
            lcm=(i*lcm)/__gcd(i,lcm);
        }
    }

    if(lcm!=n) return 0;
    return cnt;
    
}
void solve(ll tc)
{
    ll n;cin>>n;
    vector<ll> arr;
    vector<map<ll,ll>> vec;
    set<ll> st;
    loop(i,0,n)
    {
        ll t;cin>>t;
        st.insert(t);
        arr.push_back(t);
    }
    So(arr);
    if(arr.back()==1 || st.size()==1)
    {
        cout<<0<<endl;
        return ;
    }

    for(auto &i:arr)
    {
        vec.push_back({});
        factor(vec,i);
    }
    map<ll,ll> mp;
    for(ll i=0;i<n-1;i++)
    {
        for(auto &j:vec[i])
        {
            mp[j.first]=max(j.second,mp[j.first]);
        }

    }
    for(auto &i:mp)
    {
        if(i.second>vec.back()[i.first])
        {
            cout<<n<<endl;
            return ;
        }
    }
    ll mx=arr.back();
    ll ans=0;
    ll i=2;
    
    while(i*i<=mx)
    {
        if(st.count(i)==0 && mx%i==0 )
        {
            ll temp=check(arr,i);
            ans=max(ans,temp);
        }
        if(st.count(mx/i)==0 && mx%i==0)
        {

             ll temp=check(arr,mx/i);
            ans=max(ans,temp);
        }
        
        i++;
    }
  
    cout<<ans<<endl;
}
