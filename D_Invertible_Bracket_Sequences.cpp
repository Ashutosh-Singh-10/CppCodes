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
    string s;cin>>s;
    ll todel=0;
    ll cnt=0;
    ll ans=0;
     map<ll,ll> mp;
     for(auto &i:s)
     {
        if(i=='(')
        {
            cnt++;
        }
        else cnt--;
        if(cnt!=0)
        {
            
      
                if(todel>cnt)
                {
                 mp[cnt]=0;  
                    for(ll j=cnt;j<todel;j++)
                    {
                        mp[j]=0;
                    }
                    todel=cnt;
                }


                ans+=mp[cnt];

            
            mp[cnt]++;
        }
 

        todel=max(todel,(cnt+1ll)/2);
       
     }
     cout<<ans<<endl;
}
