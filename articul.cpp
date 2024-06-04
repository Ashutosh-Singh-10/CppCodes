// // // C++ program to find articulation points in an undirected
// // // graph
// // #include <bits/stdc++.h>
// // using namespace std;

// // // A recursive function to traverse the graph without
// // // considering the ith vertex and its associated edges
// // void dfs(vector<int> adj[], int V, vector<int>& vis,
// //          int i, int curr)
// // {
// //     vis[curr] = 1;
// //     for (auto x : adj[curr]) {
// //         if (x != i) {
// //             if (!vis[x]) {
// //                 dfs(adj, V, vis, i, x);
// //             }
// //         }
// //     }
// // }

// // // Function to find Articulation Points in the graph
// // void AP(vector<int> adj[], int V)
// // {

// //     // Iterating over all the vertices and for each vertex i
// //     // remove the vertex and check whether the graph remains
// //     // connected.
// //     for (int i = 1; i <= V; i++) {

// //         // To keep track of number of components of graph
// //         int components = 0;

// //         // To keep track of visited vertices
// //         vector<int> vis(V + 1, 0);

// //         // Iterating over the graph after removing vertex i
// //         // and its associated edges
// //         for (int j = 1; j <= V; j++) {
// //             if (j != i) {

// //                 // If the jth vertex is not visited it will
// //                 // form a new component.
// //                 if (!vis[j]) {

// //                     // Increasing the number of components.
// //                     components++;

// //                     // dfs call for the jth vertex
// //                     dfs(adj, V, vis, i, j);
// //                 }
// //             }
// //         }
// //         // If number of components is more than 1 after
// //         // removing the ith vertex then vertex i is an
// //         // articulation point.
// //         if (components > 1) {
// //             cout << i << "\n";
// //         }
// //     }
// // }

// // // Utility function to add an edge
// // void addEdge(vector<int> adj[], int u, int v)
// // {
// //     adj[u].push_back(v);
// //     adj[v].push_back(u);
// // }

// // // Driver Code
// // int main()
// // {
// //     // Create graphs given in above diagrams
// //     int n;cin>>n;
// //     cout << "Articulation points in the graph \n";
// //     vector<int> adj1[n+1];
// //     for(int i=0;i<n-1;i++)
// //     {
// //         int a,b;cin>>a>>b;
// //         a++;b++;
// //     addEdge(adj1, a,b);
// //     }
// //     // addEdge(adj1, 2, 3);
// //     // addEdge(adj1, 1, 3);
// //     // addEdge(adj1, 3, 4);
// //     // addEdge(adj1, 4, 5);
// //     AP(adj1, n);

// //     return 0;
// // }



// int n; // number of nodes
// vector<vector<int>> adj; // adjacency list of graph

// vector<bool> visited;
// vector<int> tin, low;
// int timer;

// void dfs(int v, int p = -1) {
//     visited[v] = true;
//     tin[v] = low[v] = timer++;
//     int children=0;
//     for (int to : adj[v]) {
//         if (to == p) continue;
//         if (visited[to]) {
//             low[v] = min(low[v], tin[to]);
//         } else {
//             dfs(to, v);
//             low[v] = min(low[v], low[to]);
//             if (low[to] >= tin[v] && p!=-1)
//                 IS_CUTPOINT(v);
//             ++children;
//         }
//     }
//     if(p == -1 && children > 1)
//         IS_CUTPOINT(v);
// }

// void find_cutpoints() {
//     timer = 0;
//     visited.assign(n, false);
//     tin.assign(n, -1);
//     low.assign(n, -1);
//     for (int i = 0; i < n; ++i) {
//         if (!visited[i])
//             dfs (i);
//     }
// }










#include <bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int>adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return { -1};
        return ans;
    }
};
int main() {

    int n;cin>>n;

    vector<vector<int>> edges;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        
        edges.push_back({a,b});
    }
    

    vector<int> adj[n];
    for (auto it : edges) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> nodes = obj.articulationPoints(n, adj);
    for (auto node : nodes) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
