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



int solve(int n vector<int> vec,int k)
{
    map<int,int> mp,tp;
    int ans=
    for(auto &el:vec)
    {
        int i=2;
        while(i*i<=el)
        {
            if(el%i==0)
            {
                el/=i;
                mp[i]++;

            }
            else i++;
        }
        mp[el]++;
    }
    int i=2;
    while(i*i<=k)
    {
        if(k%i==0)
        {
            k/=i;
            tp[i]++;

        }
        else i++;
    }
    tp[k]++;
    for(auto &i:tp)
    {
        ans=min(ans,mp[i.first]/i.first);
    }
    return ans;
}
int main()
{
    int n;cin>>n;
    vector<int> vec;
    loop(i,0,n)
    {
        ll t;cint>>t;
        vec.push_back(t);
    }
    ll k;cin>>k;
    solve(n,vec,k); 
    

}