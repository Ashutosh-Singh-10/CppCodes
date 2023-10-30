#include <bits/stdc++.h>
using namespace std;
// int algo(vector<vector<int>> &vec,vector<int> &vis,int curr)
// {
//     vis[curr]=1;
//     int ans=vec[curr].size();
//     for(auto &i:vec[curr])
//     {
//         if(vis[i/10]==0)
//         {
//             ans+=algo(vec,vis,i/10);
//         }
//         if(vis[i%10]==0)
//         {
//             ans+=algo(vec,vis,i%10);
//         }
//     }

//     return ans;


// }
int solution(vector<int> & A)
{
    int M=A.size();
    vector<vector<int>> vec(10);
    int num,x,temp,a,b;
    for(int i=0;i<M;i++)
    {
        num=A[i];
        a=num%10;
        b=num/10;
        vec[a].push_back(num);
        vec[b].push_back(num);
    }
    vector<int> vis(10,0);
    int ans=0;
    for(int i=0;i<10;i++)
    {
                

    }

return ans;
}
int main(){
    int A[]={50,30,15,51,10,20,15};
    // cout<<solution(A,7);
    return 0;
}



