#include<bits/stdc++.h>
using namespace std;

// long long msb(long long t)
// {
//     long long cnt=0;
//     while(t)
//     {
//         t>>=1;
//         cnt++;

//     }
//     return cnt;
// }
// class BinaryUplifting{
//     public:
//     long long  max_size=0;
//     vector<vector<long long>> vec;
//     BinaryUplifting(vector<vector<long long >> & graph)
//     {
//         max_size=msb(graph.size())+1;
//         for(long long i=0;i<graph.size();i++) 
//         {

//             vec.push_back({});
//             for(long long j=0;j<max_size;j++)
//             {   
//                 vec[i].push_back(-1);
//             }
//         }
//         for(int i=0;i<graph.size();i++)
//         {
//             for(int j=0;j<graph[0].size();j++)
//             {
//                 vec[j][1]=i;
//             }
//         }
      

//         for(long long i =2;i<max_size;i++)
//         {


//             for(long long node=0;node<graph.size();node++)
//             {
//                 long long parent=vec[node][i-1];
//                 if(parent!=-1)
//                 {
//                     vec[node][i]=vec[parent][i-1];
//                 }

//             }
//         }

//     }


// };





#define ll long long 
struct BinaryLifting {
    int n;
    int maxLog;
    ll maxRequirement;
    vector<vector<int>> parent;
    BinaryLifting(int n1, vector<int> *edges, ll requirement, int root) {
        n = n1;
        parent.resize(n1);
        maxLog = log2(requirement + 1);
        maxRequirement = requirement;
        for (int i = 0; i < n; i++) {
            parent[i].resize(maxLog + 1);
            for (int j = 0; j <= maxLog; j++) {
                parent[i][j] = -1;
            }
        }
        fillParentTable(root, edges);
    }
    void fillParentTable(int root, vector<int> *edges) {
        vector<bool> visited(n);
        dfsBinaryLifting(root, edges, visited);
        int intermediate = -1;
        for (int i = 1; i <= maxLog; i++) {
            for (int j = 0; j < n; j++) {
                intermediate = parent[j][i - 1];
                if (intermediate != -1) {
                    parent[j][i] = parent[intermediate][i - 1];
                }
            }
        }
    }
    void dfsBinaryLifting(int root, vector<int> *edges, vector<bool> &visited) {
        visited[root] = true;
        for (auto i : edges[root]) {
            if (!visited[i]) {
                parent[i][0] = root;
                dfsBinaryLifting(i, edges, visited);
            }
        }
    }
    int kthParent(int x, int k) {
        for(int i = 0; i <= maxLog; i++){
            if((k >> i) & 1){ 
                if(x == -1)
                    return x;
                x = parent[x][i];
            }
        }
        return x;
    }
};




int main()
{
    





    return 0 ;
}