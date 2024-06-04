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
    ll n,m;cin>>n>>m;
    vector<ll>a,b;
    loop(i,0,n+m+1)
    {
        ll t;cin>>t;
        a.push_back(t);
    }
    loop(i,0,n+m+1)
    {
        ll t;cin>>t;
        b.push_back(t);
    }
    
     ll sum=0;
     ll c=0,d=0;
     ll frc=0;
     set<ll> st;
     loop(i,0,m+n)
     {
        if(a[i]>b[i])
        {
            if(c==n)
            {
                st.insert(i);
                frc=-1;
                d++;
                sum+=b[i];
            }
            else 
            {
                sum+=a[i];
                c++;
            }
        }
        else 
        {
            if(d==m)
            {
                st.insert(i);
                frc=1;
                c++;
                sum+=a[i];
            }
            else 
            {
                sum+=b[i];
                d++;
            }

        }


     }
     
     if(frc==0)
     {
        loop(i,0,n+m)
        {
            if(a[i]>b[i])
            {
                cout<<sum+a.back()-a[i];
            }
            else 
            {
                cout<<sum+b.back()-b[i];
            }
            cout<<" ";

        }
        cout<<sum;
        cout<<endl;
        return ;
     }

    ll ans;
        auto it=*st.begin();
     loop(i,0,n+m)
     {
        ans=sum;
        if(a[i]>b[i] )
        {
            
            if(frc==-1)
            {
                if(i<it)
                {
                    ans-=a[i];
                    ans+=a[it];
                    ans-=b[it];
                    ans+=b.back();

                }
                else 
                {
                    ans-=b[i];
                    ans+=b.back();

                }
            }
            else 
            {
                    ans-=a[i];
                    ans+=a.back();
            }
            

        }
        else 
        {
            if(frc==1)
            {
                if(i<it)
                {
                    ans-=b[i];
                    ans+=b[it];
                    ans-=a[it];
                    ans+=a.back();

                }
                else 
                {
                    ans-=a[i];
                    ans+=a.back();

                }
            }
            else 
            {
                    ans-=b[i];
                    ans+=b.back();
            }
            
            
        }
        cout<<ans<<" ";

     }


     
     cout<<sum<<endl;



}
