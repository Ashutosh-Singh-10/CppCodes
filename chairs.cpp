#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> & gr,int u,int p, int &a, int &b,vector<int> & c1,vector<int> & c2,vector<int> &vis)
{
    if(vis[u]==1) return ;
    a+=c1[u];
    b+=c1[u];
    vis[u]=1;
    for(auto &i:gr[u])
    {
        if(i!=p)
        {
            dfs(gr,i,u,a,b,c1,c2,vis);
        }
    }

    

}
int solve( int n,int m,vector<int> type,vector<vector<int>> doors)
{
        int ans=0;
        vector<int> c1(n,0),c2(n,0),vis(n,0);
        vector<vector<int>> gr;
    for(auto &i:doors)
    {
        auto a=i[0]-1;
        auto b=i[1]-1;
        auto t1=type[a];
        auto t2=type[b];
        if((t1==1 && t2==2)  || ( t1==2 && t2==1))
        {
            ans++;
        }

        if((t1==0 && t2==1)) c1[a]++;
        if((t1==1 && t2==0)) c1[b]++;

        if((t1==0 && t2==2)) c2[a]++;
        if((t1==2 && t2==0)) c2[b]++;

        if(t1==0 && t2==0)
        {
            gr[t1].push_back(t2);
            gr[t2].push_back(t1);

        }

    }
    for(int i=0;i<n;i++)
    {
        if(type[i]==0)
        {
            int a=0,b=0;
            dfs(gr,i,-1,a,b,c1,c2,vis);
            ans+=min(a,b);
        }
    }


return ans;

    

}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        vec.push_back(t);
    }
    vector<vector<int>> door;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        door.push_back({a,b});
    }
   cout<< solve(n,m,vec,door);


    return 0;
}


#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isValid(int n, int cur,int cursum,vector<int> & arr,int limit,vector<set<int>> &st){


    

    
	   
	
}

int main(){
	
	ll n,m;
	cin>>n>>m;
	
	vector<ll>arr(n);
	
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	
	sort(arr.begin(),arr.end());
	
	ll low=0;
	ll high=1e9;
	ll ans=-1;
	
	while(low<=high){
		  
		  ll mid=low+(high-low)/2;
		  if(isValid(mid,arr,m)){
		  	ans=mid;
		  	high=mid-1;
		  }else{
		  	low=mid+1;
		  }
	}
	
	cout<<ans<<endl;
	
}