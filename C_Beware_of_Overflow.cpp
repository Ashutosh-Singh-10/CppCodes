    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
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
    
        solve(0);
    
    
    return 0;
}


void som(vector<ll> &vec,ll start,ll end)
{
    if(start==end) return;
    if(end-start)
    {
        cout<<"? "<<start<<" "<<end<<endl;
        ll tmp;cin>>tmp;
        if(tmp==0)
        {
            swap(start,end);
        }
        return ;
    }
    ll mid=start+(end-start)/2;
    som(vec,start,mid);
    som(vec,mid+1,end);
    vector<ll> tec;
    ll x=start,y=mid+1;
    while(x<=mid && y<=end)
    {
        cout<<"? "<<start<<" "<<end<<endl;
        ll tmp;cin>>tmp;
        if(tmp)
        {
            tec.push_back(y);
            y++;
        }
        else 
        {
            tec.push_back(x);
            x++;
        }
    
    }
    while(x<=mid)
    {
        tec.push_back(x);
        x++;
    }
    while(y<=end)
    {
        tec.push_back(y);
        y++;
    }


    
}
void solve(ll tc)
{
    ll n;cin>>n;
    vector<ll> vec;
    loop(i,0,n)
    {
        vec.push_back(i+1);
    }
    som(vec,0,n-1);
    vector<ll> tec;
    ll i=0,j=n-1;
    while(i<=j)
{
    tec.push_back(i);
    i++;
    if(i<=j)
    {
        tec.push_back(j);
        j--;
    }

}
   
    


}
