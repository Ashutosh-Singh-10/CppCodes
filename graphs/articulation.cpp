#include <bits/stdc++.h>
using namespace std;
int algo(vector<vector<int>> & graph,vector<int> &vis,vector<int> &index,int curr,int &in,vector<int> & ans,int prev)
{
    if(vis[curr]==1)
    {
        return index[curr];
    }
    int myin=in;
    int mn=-1;  
    index[curr]=in; 
    vis[curr]=1;
    int cnt=0;
    for(int i=0;i<graph[curr].size();i++)
    {
        
            in++;
            cnt++;
        mn=max(mn,algo(graph,vis,index,graph[curr][i],in,ans,curr));

        
    }
    // if(mn==-1) min
    if(mn>myin && cnt>1)
    {   
        
        ans.push_back(curr);
        
    }
    return mn;
    

}
int main()
{
    int k=10;
    vector<int> index(k,0);
    vector<int> vis(k,0);
    vector<int> ans;
    vector<vector<int>> graph={
        {1,3,5},
        {0,2,6,9},
        {1},
        {0,4,5},
        {3},
        {0,3},
        {1,7,8,9},
        {6,10},
        {6,10},
        {1,6},
        {7,8}
    };
    int cnt=0;
    int p=0;
    vis[p]=1;
    int in=1;
    for(int i=0;i<graph[p].size();i++)
    {

        if(vis[graph[p][i]]==0)
        {
            cnt++;
            algo(graph,vis,index,graph[p][i],in,ans,p);


        }
        
    }
    cout<<endl; 
    for(auto &i:vis)
    {
        cout<<i<<"  ";
    }cout<<endl;
    cout<<"The cnt is "<<cnt<<endl;
    if(cnt>1)
    {
        ans.push_back(p);
    }
    for(auto &i:ans)
    {
        cout<<i<<"  ";
    }
    cout<<"HII";
    




    return 0;
}