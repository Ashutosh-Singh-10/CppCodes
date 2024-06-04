
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
ll check(vector<ll> &vec,ll index)
{
    ll prev=-1;
    vector<ll> gc;
    loop(i,0,vec.size())
    {
        if(i==index)
        { 
            continue;
        }
        if(prev==-1)
        {
            prev=vec[i];
        }
        else
        {
            
            gc.push_back(__gcd(prev,vec[i]));
            prev=vec[i];
        }

    }
    if(is_sorted(all(gc))) return 1;
    return 0;

}
void solve(ll tc)
{
    ll n;cin>>n;
    vector<ll> vec,gc;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }

    multiset<ll> l,r;
    loop(i,1,n)
    {
        auto g=__gcd(vec[i],vec[i-1]);
        gc.push_back(g);        
    }
    if(is_sorted(all(gc)))
    {
        cout<<"YES\n";return ;
    }

    loop(i,0,n-2)
    {
        if(gc[i]>gc[i+1])
        {
            if(check(vec,i) || check(vec,i+1) || check(vec,i+2) )
            {
                cout<<"YES"<<endl;
                return ;
            }
            cout<<"NO"<<endl;
            return ;
            

        }

    }
}
