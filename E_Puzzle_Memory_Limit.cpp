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
ll cost(vector<pair<ll,ll>> &vec,ll k)
{
    map<ll,ll> mp,order;
    ll time=0;
    // cout<<"k is ->"<<k<<endl;
    loop(i,0,vec.size())
    {
        // cout<<mp.size()<<"-> ";
        auto [f,s]=vec[i];
        if(mp.count(f))
        {
            
            order.erase(order.find(i));

            if(s==-1)
            {
                mp.erase(mp.find(f));
            }
            else 
            {
                mp[f]=s;
                order[s]=f;
            }

        }
        else 
        {
            time++;
                if(mp.size()>k-1)
                {
                    auto it=order.end();
                    it--;
                    ll exc=it->second;
                
                    order.erase(it);

                    mp.erase(mp.find(exc));
                    
                }

                if(s!=-1)
                {
                    
                        mp[f]=s;
                        order[s]=f;
                    
                }
            
        }
        // cout<<mp.size()<<"     ";


    }
    cout<<endl;
    return time;
}
void solve(ll tc)
{
    ll n;cin>>n;ll time;cin>>time;
    map<ll,ll> mp;
    vector<pair<ll,ll>> vec;
    loop(i,0,n)
    {
        ll t;cin>>t;
        vec.push_back({t,-1});
        if(mp.count(t))
        {
            vec[mp[t]].second=i;
        }
        mp[t]=i;
    }
    // for(auto &[a,b]:vec)
    // {
    //     cout<<a<<"--> "<<b<<endl;
    // }
    ll low=1,high=n,mid;
    ll ans=LONG_LONG_MAX;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(cost(vec,mid)>time)
        {
            low=mid+1;
        }
        else
        {
            ans=min(ans,mid);
            high=mid-1;
        }


    }
    if(ans==LONG_LONG_MAX)
    {
        cout<<-1<<endl;return ;
    }
    cout<<ans<<endl;
    
    
 
}
