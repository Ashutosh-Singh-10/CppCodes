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

// getbits setbits countbits ispoweroftwo  shiftbits iota
void solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{   
    ll n,t;
    cin>>n;
    char im;
    cin>>im;
    map<char,set<int>> mp;
    vector<ll> vec;
    loop(i,0,2*n)
    {
        string s;
        cin>>s;
        if(s[1]==im)
        {
            vec.push_back(s[0]-'0');
        }
        else mp[s[1]].insert(s[0]-'0');
    }
    So(vec);
    vector<vector<string>> ans,lst;

    // for(auto &i:mp) for(auto  &j:i.second) cout<<j<<" ";
    // cout<<"HII";
    for(auto  &i:mp)
    {
        char ch=i.first;
        if(i.second.size()%2)
        {
            if(vec.size()==0)
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
            string k=to_string(*vec.rbegin());
            k.push_back(im);
            lst.push_back({to_string(*i.second.begin())+i.first,k});
            vec.pop_back();
            i.second.erase(i.second.begin());
        }
        auto it=i.second.begin();
        while(it!=i.second.end())
        {
            auto tt=it;
            it++;
            string a=to_string(*tt);
            a.push_back(i.first);
            string b=to_string(*it);
            b.push_back(i.first);

            ans.push_back({a,b});
            it++;
        }
    }
    for(int i=0;i<vec.size();i+=2)
    {
        string a=to_string(vec[i]);
        a.push_back(im);
        string b=to_string(vec[i+1]);
        b.push_back(im);
        lst.push_back({a,b});
    }


    for(auto  &i:ans)
    {
        cout<<i[0]<<" "<<i[1]<<"\n";
    }
    for(auto  &i:lst)
    {
        cout<<i[0]<<" "<<i[1]<<"\n";
    }
    



  
}

