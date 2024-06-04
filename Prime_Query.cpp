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
    ll n;cin>>n;
    vector<ll> vec,a,b;
    a.push_back(0);
    b.push_back(0);
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
        if(t==1)
        {
            a.push_back(a.back()+1);
        }
        else a.push_back(a.back());
        if(t==2)
            b.push_back(b.back()+1);
        else b.push_back(b.back());

    }

    ll m;cin>>m;
    loop(i,0,m)
    {
        ll l,r,k;cin>>l>>r>>k;

        ll x=a[r]-a[l-1];
        ll y=b[r]-b[l-1];
        ll temp=max(x,y);
        y=min(x,y);
        x=temp;

        ll d=r-l+1;

        ll todo=min(x-y,d-x-y);

        y+=min(todo,k);
        k-=min(todo,k);

        todo=d-x-y;
        ll left=min(todo,k);
        x+=(left+1)/2;
        y+=left/2;
        k-=left;

        temp=max(x,y);
        y=min(x,y);
        x=temp;

        if(x+y==d && x-k<=y+k)
        {
            x=d/2;
            y=(d+1)/2;
        }
        else if(x+y==d)
        {
            x-=k;
            y+=k;
        }
   
        cout<<x*y<<endl;


        



    }




}
