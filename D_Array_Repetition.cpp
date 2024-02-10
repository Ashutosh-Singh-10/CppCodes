        #include <bits/stdc++.h>
        using namespace std;
        using std::cout;
        using std::cin;
        using std::endl;    
        #define ll unsigned long long
        #define loop(i,a,b) for(int i=a;i<b;i++)
        #define longloop(i,a,b) for(long long i=a;i<b;i++)
        #define roop(i,a,b) for(int i=a-1;i>=b;i--)
        #define all(p) p.begin(),p.end()
        #define pb(p) push_back(p);
        int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
        template<class T> using _pq = priority_queue<T>;
        template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
        template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
        template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}

        template<class T> void vec_out(vector<T> &p,int ty=0){
        if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
        else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}

        template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
        template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;} 

        template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
        template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
        template<class T> T vec_sum(vector<T> &a){assert(!a.empty());T ans=a[0]-a[0];for(auto &x:a) ans+=x;return ans;}

        template<class T>  void matcout(vector<vector<T>> &a){for(auto &i:a){ for(auto &j:i){cout<<j<<"  ";}cout<<"\n";}cout<<"\n";}

        template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
        template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}

int boo=0;
void solve(int ty);
int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        solve(t);
    }
    return 0;
}
void solve(int ty)
{   
    ll n,q,a,b;
    // if(ty== && n==56)
    // {
    //     boo=1;
    // }
    ll unim=ULLONG_MAX;
    cin>>n>>q;
    vector<pair<ll,ll>> op;
    map<ll,vector<ll> > qu;
    ll sz=0;
    bool flag=1;
    // ll mxi=1e18;
    int pip=n;
    if(boo==1 && ty==5998)
    {
        cout<<n<<"  "<<q<<endl;
    }
    loop(i,0,n)
    {
        cin>>a>>b;

    if(boo==1 && ty==5998)
    {
        cout<<a<<" "<<b<<"   ";
    }
        op.push_back({a,b});
        if(flag==0) continue;
        if(a==1)
        {
            if(sz+1<=unim  && flag==1)
            {

            sz++;

            }
            else
            {
            flag=0;
                pip=min(pip,i);
            } 
            
            

        }
        else 
        {

            ll tpp=(sz)*(b+1);
            if(flag==0 || tpp/(b+1)!=sz)
            {
                pip=min(pip,i);
                flag=0;
            }
            else 
            sz*=b+1;
        }

    }

    loop(i,0,q)
    {
        cin>>a;
    // if(boo==1 && ty==5998)
    // {
    //     cout<<a<<"  ";
    // }
        qu[a].push_back(i);
    }
    vector<pair<ll,ll>> ans;
    auto it=qu.upper_bound(sz);

    while(it!=qu.end())
    {
        for(auto &inir:it->second)
        {
            qu[(it->first-1)%(sz)+1].push_back(inir);
        }
        it++;
    }
    it=qu.upper_bound(sz);
    qu.erase(it,qu.end());



    roop(i,pip,0)
    {
        if(op[i].first==1)
        {
            auto it=qu.lower_bound(sz);
            if(it!=qu.end() && (*it).first==sz)
            {
                for(auto &inir:(*it).second)
                {
                    ans.push_back({inir,op[i].second});
                }
                qu.erase(it);
            }
            sz--;
        }
        else 
        {
            ll nz=sz/(op[i].second+1);
            while(qu.size() && nz>0 &&  (*qu.rbegin()).first>nz)
            {
                vector<ll> tec;
                for(auto &kia:qu.rbegin()->second)
                {
                    tec.push_back(kia);
                }
                
                if(qu.size())
                {
                auto ittt=qu.end();

                ittt--;
                qu.erase(ittt);
                ll nw=((ittt->first-1)%nz)+1;
                for(auto &jis:tec)
                {
                    qu[nw].push_back(jis);
                }
                }
                
            }
            sz/=(op[i].second+1);

        }
    }

    sort(all(ans));

if(boo==0)
{

    loop(i,0,ans.size())
    {
        cout<<ans[i].second<<" ";
    }
    cout<<endl;
}



  
}

    