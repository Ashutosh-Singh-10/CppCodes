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



// void solve(ll tc);
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
    
//         solve(0);
    
    
//     return 0;
// }
// void solve(ll tc)
// {
//     ll n,sum=0,mx=0;cin>>n;
//     loop(i,0,n)
//     {
//         ll a,b;cin>>a>>b;
//         sum+=a;
//         mx=max(mx,b-a);
//     }
//     cout<<sum+mx;

  
    
// }

// #define ll long long
// int solve(vector<int> vec,int n ,int M)
// {
//     map<ll,ll> mp;
//     ll m=M;
//     mp[0]=0;
//     ll x=0;
//     ll ans=0;
//     for(auto &i:vec)
//     {
//         x+=i;
//         if(mp.count(x%m)==0)
//         {
//             mp[x%m]=x;
//         }
//         else 
//         {
//             ans=max(ans,x-mp[x%m]);
//         }

//     }
//     return ans;
// }


// int checking(vector<int> &vec,int k)
// {

//     int mn=INT_MAX;
//     int mx=INT_MIN;
//     for(auto i:vec)
//     {
//         while( (i%2==1) && ((i<<1) <= k))
//         {
//             i<<=1;
//         }
//         while(i>k && i%2==0 )
//         {
//             i>>=1;
//         }
//         mn=min(mn,i);
//         mx=max(mx,i);

//     }
//     // cout<<k<<" ";
//     // cout<<mx<<"->"<<mn<<" ";
//     return mx-mn;

// }

// int solve(vector<int> vec)
// {
//     int ans=INT_MAX;
//     for(int i=0;i<30;i++)
//     {
//         ans=min(ans,checking(vec,1<<i));
//     }
//     return ans;
// }

// int main()
// {
//     int n;cin>>n;
//     vector<int> vec;
//     loop(i,0,n)
//     {
//         ll t;cin>>t;
//         vec.push_back(t);
//     }
//     cout<<solve(vec);
//     return 0;
// }
// int check(vector<vetor<int>> & vec)
// {
//     int n,m;
//     queue<pair<int,int>> qu;
//     qu.push({0,0});
//     qu.push({-10,0});
//     vector<vector<int>> done(n,vector<int> (m,0));
//     while(qu.size()>=2)
//     {
//         auto  a=qu.front();
//         int b=a.first,c=a.second;
//         qu.pop();
//         if(b==-10)
//         {
//             qu.push({-10,0});
//             cnt++;
//             continue;
//         }
        
//         done[b][c]=1;
//         if(b+1==n && c+1==m) 
//         return cnt;

//         int g=vec[b][c*2];
//         int h=vec[b][c*2+1];
//         if(g+b>=0 && g+b<n && c+h>=0 &&  c+h<m)
//         {
//             if(done[g+b][c+h]==0)
//             {
//                 qu.push({g+b,c+h});
//                 done[g+b][c+h]=1;
//             }
//         }
//         if(g-b>=0 && g-b<n && c+h>=0 &&  c+h<m)
//         {
//             if(done[g-b][c+h]==0)
//             {
//                 qu.push({g-b,c+h});
//                 done[g-b][c+h]=1;
//             }
//         }
//         if(g+b>=0 && g+b<n && c-h>=0 &&  c-h<m)
//         {
//             if(done[g+b][c-h]==0)
//             {
//                 qu.push({g+b,c-h});
//                 done[g+b][c-h]=1;
//             }
//         }
//         if(g-b>=0 && g-b<n && c-h>=0 &&  c-h<m)
//         {
//             if(done[g-b][c-h]==0)
//             {
//                 qu.push({g-b,c-h});
//                 done[g-b][c-h]=1;
//             }
//         }
//         if(h-b>=0 && h-b<n && c-g>=0 &&  c-g<m)
//         {
//             if(done[h-b][c-g]==0)
//             {
//                 qu.push({h-b,c-g});
//                 done[h-b][c-g]=1;
//             }
//         }
//         if(h+b>=0 && h+b<n && c-g>=0 &&  c-g<m)
//         {
//             if(done[h+b][c-g]==0)
//             {
//                 qu.push({h+b,c-g});
//                 done[h+b][c-g]=1;
//             }
//         }
//         if(h+b>=0 && h+b<n && c+g>=0 &&  c+g<m)
//         {
//             if(done[h+b][c+g]==0)
//             {
//                 qu.push({h+b,c+g});
//                 done[h+b][c+g]=1;
//             }
//         }
//         if(h-b>=0 && h-b<n && c+g>=0 &&  c+g<m)
//         {
//             if(done[h-b][c+g]==0)
//             {
//                 qu.push({h-b,c+g});
//                 done[h-b][c+g]=1;
//             }
//         }

//     }
//     return -1;
// }
int count(vector<int> a, vector<int> b)
{
    map<int,vector<int>>mp;
    int ans=0;
    int x=a.size();
    for(int j=0;j<x;j++)
    {
        auto el=a[j];
        int i=2;
        while(i*i<=el)
        {
            if(el%i==0)
            {
                mp[i].push_back(x);
            }
            while(el%i==0)
            {

                el/=i;
            }
            i++;
        }

        if(el!=1)
        {
            mp[el].push_back(j);
        }
    }
    for(auto &el:b)
    {
        int i=2;
        set<int> st;
        while(i*i<=el)
        {
            if(el%i==0)
            {
                for(auto &j:mp[i])
                {
                    st.insert(j);
                }
            }
            while(el%i==0)
            {

                el/=i;
            }
            i++;
        }

        if(el!=1)
        {
            
            for(auto &j:mp[el])
            {
                st.insert(j);
            }
            
        }
        ans+=st.size();

    }
    return ans;
}
int main()
{
    vector<int> a={2,4};vector<int> b={4,2};
    cout<<count(a,b);
    return 0;

}




