    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
    #define endl '\n'    
    #define ll long long
    #define int long long 
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
int32_t main()
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
// ll fun(vector<ll> &vec,ll k,ll mid)
// {
//     ll n=vec.size();
//     for(auto &i:vec)
//     {
//         if(i<mid)
//         {
//             if(mid-i>k) return -1;
//             k-=mid-i;
//         }
//     }
//     return (n*mid)-n+1;


// }
// ll fun2(vector<ll> &vec,ll k,ll mid)
// {
//     ll n=vec.size();
    
//     if(mid-vec[0]-1>k) return-1;
//     if(vec[0]<mid-1)
//     {
//         k-=mid-vec[0]+1;

//     }
    
//     for(int j=1;j<vec.size();j++)
//     {
//         ll i=vec[j];
//         if(i<mid)
//         {
//             if(mid-i>k) return -1;
//             k-=mid-i;
//         }
//     }
//     return (n*mid)-n;


// }
void solve(ll tc)
{
    ll n,k;cin>>n>>k;
    vector<ll> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back(t);
    }
    ll ans=0;
    So(vec);
    ll cmx=vec[0];
    ll cnt=0;
    for(int i=0;i<n-1;i++)
    {
        ll diff=vec[i+1]-vec[i];
            cnt=i;
        if(diff*(i+1)<=k)
        {
            cmx=vec[i+1];
            k-=diff*(i+1);
        }
        else 
        {
            ll temp=k/(i+1);
            k-=temp*(i+1);
            cmx+=temp;
            break;
        }


    }
    for(ll i=0;i<=cnt;i++)
    {
        vec[i]=cmx;
        
    }
    if(k>=n)
    {
        ll temp=k/n;
        k%=n;
        for(auto &i:vec) i+=temp;
        
    }

    // for(auto  &i:vec) cout<<i<<" ";
    // cout<<k;
    // cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(k>0)
            {
                vec[i]++;
                k--;
            }
    }
    So(vec);
    ll mn=vec[0];
    ll x=0,y=0;
    for(auto &i:vec)
    {
        if(i==mn) x++;
        else y++;
    }
    ans=(mn*n)+y-n+1;




    // ll low=0;
    // ll high=1e13+10;
    
    // while(low<=high)
    // {
    //     ll mid=low+((high-low)/2);
    //     ll x=fun(vec,k,mid);
    
    //     if(x>0)
    //     {
    //         ans=max(ans,x);
    //         low=mid+1;
    //     }
    //     else high=mid-1;
    // }
    // low=0;
    //  high=1e13+10;
    
    // while(low<=high)
    // {
    //     ll mid=low+((high-low)/2);
    //     ll x=fun2(vec,k,mid);
    //     // cout<<mid<<" ";
    //     // cout<<x<<" "<<high<<" ";
    //     if(x>0)
    //     {
    //         ans=max(ans,x);
    //         low=mid+1;
    //     }
    //     else high=mid-1;
    // }
    cout<<ans<<"\n";


}
