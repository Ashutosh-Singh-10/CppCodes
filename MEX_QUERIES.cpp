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
    vector<ll> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }
    vec.push_back(0);
    ll op=0;
    // for(auto &i:vec) cout<<i<<" ";cout<<endl;
    loop(i,0,n+1)
    {
        if(i==0)
        {
            cout<<vec[0]<<" ";
        }
        else if(vec[i-1]==0)
        {
            cout<<-1<<" ";

        }
        else 
        {
            cout<<op+vec[i]<<" ";
        }
        ll idx=i/2;
        ll temp=1;
        while(vec[i]==0)
        {
            if(vec[idx]>=2)
            {
                vec[idx]--;
                vec[i]++;
                op+=temp;;

            }
            temp++;
            if(idx==0)
            {
                break;
            }
            idx/=2;
        }
        if(i && vec[i-1]==0)
        {
            vec[i]=0;
        }
    }
    // cout<<endl;
    // for(auto &i:vec) cout<<i<<" ";cout<<endl;

    cout<<endl;

}
