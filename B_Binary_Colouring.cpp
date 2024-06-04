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
ll isset(ll n,ll x)
{
    ll a=1;
    if(n&(a<<x))return 1;return 0;
}
void solve(ll tc)
{
    ll n;cin>>n;
    vector<ll> vec;
    ll flag=0;
    for(int i=0;i<32;i++)
    {

        if(isset(n,i))
        {
            if(flag==1)
            {
                if(vec.back()!=0)
                {
                    vec.pop_back();
                    vec.push_back(-1);
                    vec.push_back(0);

                    
                }
                else 
                {
                    vec.push_back(0);
                }

            }
            else 
            {
                vec.push_back(1);
            }
                flag=1;

        }
        else 
        {
            if(flag==1)
            {
                if(vec.back()==0)
                {

                vec.push_back(1);
                flag=1;
                }

                else 
                {
                    vec.push_back(0);
                    flag=0;
                }
            }
            else vec.push_back(0);
        }
    }
    cout<<32<<endl;
    for(auto &i:vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    


}
