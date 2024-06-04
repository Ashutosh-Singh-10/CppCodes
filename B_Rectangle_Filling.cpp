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
    ll m,n;cin>>n>>m;
    vector<string> vec;
    loop(i,0,n)
    {
        string str;cin>>str;
        vec.push_back(str);
    }
    ll a=0,b=0,c=0,d=0;
    loop(i,0,n)
    {
        if(vec[i][0]=='W') a=1;
    }
    loop(i,0,n)
    {
        if(vec[i][m-1]=='W') b=1;
    }
    loop(i,0,m)
    {
        if(vec[0][i]=='W') c=1;
    }
    loop(i,0,m)
    {
        if(vec[n-1][i]=='W') d=1;
    }
    if(a+b+c+d==4)
    {
        cout<<"YES"<<endl;
        return;
    }
    a=0,b=0,c=0,d=0;
    loop(i,0,n)
    {
        if(vec[i][0]=='B') a=1;
    }
    loop(i,0,n)
    {
        if(vec[i][m-1]=='B') b=1;
    }
    loop(i,0,m)
    {
        if(vec[0][i]=='B') c=1;
    }
    loop(i,0,m)
    {
        if(vec[n-1][i]=='B') d=1;
    }
    if(a+b+c+d==4)
    {
        cout<<"YES"<<endl;
        return;
    }
        cout<<"NO"<<endl;




}
