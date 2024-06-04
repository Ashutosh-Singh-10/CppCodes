//     #include <bits/stdc++.h>
//     using namespace std;
//     using std::cout;
//     using std::cin;
//     #define endl '\n'    
//     #define ll long long
//     #define loop(i,a,b) for(long long i=a;i<b;i++)
//     #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
//     #define all(p) p.begin(),p.end()
//     #define pb(p) push_back(p);
//     long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
//     template<class T> using _pq = priority_queue<T>;
//     template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
//     template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
//     template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}



// void solve(ll tc);
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     ll t;
//     cin>>t;
//     loop(i,0,t)
//     {
//         solve(i);
//     }
    
//     return 0;
// }
// bool isOk(deque<ll> &a,deque<ll> &b)
// {
//     loop(i,0,a.size())
//     {
//         if(a[i]>b[i]) return 0;
//     }
//     return 1;
// }
// void solve(ll tc)
// {
//     ll n;cin>>n;
//     deque<ll> vec,a;
//     vector<ll> x,y;
//     loop(i,0,n)
//     {
//         ll t;cin>>t;
//         x.push_back(t);
//     }
//     loop(i,0,n)
//     {
//         ll t;cin>>t;
//         y.push_back(t);
//     }

//     So(x);
//     So(y);
//     for(auto i:x) a.push_back(i);
//     for(auto i:y) vec.push_back(i);
//     ll ans=0;
//     loop(i,0,n)
//     {
//         if(isOk(a,vec))
//         {
//             break;

//         }
//         ans++;
//         a.pop_back();
//         a.push_front(-1);
        

//     }
    
//     cout<<ans<<endl;
    


// }


// CPP program to find
// sum of given series
#include <bits/stdc++.h>
using namespace std;

// function to find sum of series
long long int sum(long long int n)
{
	long long int root = sqrt(n);
	long long int ans = 0;

	for (int i = 1; i <= root; i++) 
		ans += n / i;
	
	ans = 2 * ans - (root * root);
	return ans;
}

// driver code
int main()
{
	long long int n = 1e6;
	cout << sum(n);
	return 0;
}
