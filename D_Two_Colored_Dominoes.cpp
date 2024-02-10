        #include <bits/stdc++.h>
        using namespace std;
        using std::cout;
        using std::cin;
        using std::endl;    
        #define ll long long
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

void solve(int t,int ov);
int main()
{
    int t;
    cin>>t;
    int ov=t;
    for(int i=0;i<ov;i++)
    {
        solve(i,ov);
    }
    return 0;
}
void solve(int t,int ov)
{   
    ll n,m;
    cin>>n;
    cin>>m;
    string s;
    vector<string> vec;
    loop(i,0,n)
    {
        cin>>s;
        // if(t==72 && ov==1000) cout<<s<<endl;
        vec.push_back(s);
    }
    ll cnt=0;
    vector<ll> tot(m,0);
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            if(vec[i][j]=='.')
            {
                continue;
            }
            if(vec[i][j]=='L')
            {
                if(tot[j]<=0)
                {

                vec[i][j]='W';
                vec[i][j+1]='B';
                
                tot[j]++;
                tot[j+1]--;
                }
                else
                {
                vec[i][j]='B';
                vec[i][j+1]='W';

                tot[j]--;
                tot[j+1]++;

                }
                j++;

            }
            else if(vec[i][j]=='W')
            {
                cnt++;
            }
            else if(vec[i][j]=='B')
            {
                cnt--;
            }
            else 
            {
                if(cnt<=0)
                {
                    vec[i][j]='W';
                    vec[i+1][j]='B';
                    cnt++;

                }
                else
                {
                     vec[i][j]='B';
                     vec[i+1][j]='W';
                     cnt--;

                }
            }

            

        }

        if(cnt!=0 && ov!=1000)
        {
            cout<<-1<<endl;
            return ;
        }
        
    }
    // if(ov==1000) return ;
        for(auto &i:tot)
        {
            if(i)
            {
                cout<<-1<<endl;
                return ;
            }
        }
        // cout<<endl; 
    for(auto &i:vec)
    {
        cout<<i<<endl;
    }
        // cout<<endl;
        // cout<<endl;
        // cout<<endl;



  
}

    