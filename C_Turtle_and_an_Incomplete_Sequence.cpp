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
void fun(vector<ll> &vec,ll cnt,ll el)
{
    while(cnt)
    {
        cnt--;
        if(el/2ll>0)
        {
            el/=2ll;
            vec.push_back(el);

        }
        else 
        {
            el*=2ll;
            vec.push_back(el);
        }
    }


}
ll countbit(ll x)
{
    ll cnt=0;
    while(x) {x>>=1ll;cnt++;}
    return cnt;
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
    ll cnt=0;
    for(auto &i:vec) if(i==-1) cnt++;
    if(cnt==n)
    {
        
        loop(i,0,n)
        {
            if(i%2)
            {
                cout<<1<<" ";
            }
            else cout<<2<<" ";
        }
        cout<<endl;
        return;
    }


    ll p=-1;
    cnt=0;
    vector<ll> ans;
    loop(i,0,n)
    {
        if(vec[i]==-1)
        {
            cnt++;
            continue;
        }
        else 
        {

            if(p==-1)
            {
                p=vec[i];
                ans.push_back(vec[i]);
                cnt=0;
            }
            else
            {
                if(cnt==0)
                {
                    ans.push_back(vec[i]);
                    
                }
                else 
                {

                ll mn=min(p,vec[i]);
                ll mx=max(p,vec[i]);
                ll c=cnt;
                vector<ll> tmp;
                ll c1=countbit(mx);
                ll c2=countbit(mn);
               while(c1>c2)
               {
                    mx/=2ll;
                    tmp.push_back(mx);
                    c1--;
                    if(c<0)
                    {
                        cout<<-1<<endl;
                        return ;
                    }
               }
               cout<<tmp.size()<<"->";
               for(auto &i:tmp)
               {
                cout<<i<<" ";
               }
               cout<<endl;
               while(mn!=mx)
               {
                    mx>>=1;
                    mn>>=1;
                    tmp.push_back(mx);
                    c--;
                    if(c<0)
                    {
                        cout<<-1<<endl;
                        return ;
                    }
            
               }
               
               mn=min(p,vec[i]);
                 
                 c1=countbit(mx);
                 c2=countbit(mn);
                c1=c2-c1;

                while(mx!=mn)
                {
                    mx*=2ll;
                    if(mn&(1ll<<c1))
                    {
                        mx++;
                    }
                    if(mx!=mn)
                    tmp.push_back(mx);
                    if(tmp.size()>cnt)
                    {
                       
                  
                        cout<<-1<<endl;
                        return ;
                    }

                }
               
                if(c>0)
                {
                    if(tmp.size() && tmp.size()<cnt && tmp.back()!=mn)
                    {

                     tmp.push_back(mn);
                    }
                }
                while(tmp.size()<cnt)
                {
                    if(mn!=mx)
                    {
                        mx=mn;
                        tmp.push_back(mx);

                    }
                    else if((mx/2ll)>0)
                    {
                        mx=mx/2ll;
                        tmp.push_back(mx);
                    }
                    else 
                    {
                        mx*=2ll;
                        tmp.push_back(mx);
                    }
                    
                    
                }


             
  

                if(vec[i]>p)
                {
                    reverse(all(tmp));
                }
                for(auto &i:tmp)
                {
                    ans.push_back(i);
                }
                ans.push_back(vec[i]);
                
            }

                }
        p=vec[i];
        cnt=0;

        }
        
    }
     cnt=0;
    while(vec.back()==-1)
    {
        cnt++;
        vec.pop_back();

    }
    if(cnt)
    {
        fun(ans,cnt,vec.back());
    }
    reverse(all(vec));
    reverse(all(ans));

    cnt=0;
    while(vec.back()==-1)
    {
        cnt++;
        vec.pop_back();

    }
    if(cnt)
    {
        fun(ans,cnt,vec.back());
    }
    reverse(all(ans));
    loop(i,1,n)
    {
        if(ans[i]!=ans[i-1]/(ll)2 && ans[i-1]!=ans[i]/(ll)2)
        {
            cout<<-1<<endl;
            return;
        }
        if(ans[i]==0 || ans[i-1]==0)
        {
            cout<<-1<<endl;
            return;

        }
    }
    if(ans.size()!=n)
    {
        cout<<-1<<endl;
        return ;
    }
    for(auto &i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;



}
