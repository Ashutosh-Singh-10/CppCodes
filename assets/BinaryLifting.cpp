#include<bits/stdc++.h>
using namespace std;


class BinaryLifting{
public:
int n, l;
vector<vector<int>> adj;
int timer=0;
vector<int> tin, tout;
vector<vector<int>> up;
BinaryLifting(int root,vector<vector<int>> vec) {
    adj=vec;
    n=vec.size();
    tin.resize(n);tout.resize(n);
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1,-1));
    dfs(root, root);
}
BinaryLifting(int root,vector<int> parent) {
    n=parent.size();
    adj.resize(n);
    for(int i=0;i<n;i++)
    {
        if(parent[i]!=-1)
        adj[parent[i]].push_back(i);

    }
    
    tin.resize(n);tout.resize(n);
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1,-1));
    dfs(root, -1);
}

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        if(up[v][i-1]!=-1)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}



int getKthAncestor(int node, int k) {
        if(k>=n) return -1;
        int len = (int)log2(k); // Calculate the maximum exponent of 2 in k

        for (int i = 0; i <= len; ++i) {
            if (k & (1 << i)) { // If the i-th bit of k is set
                node = up[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }

};
