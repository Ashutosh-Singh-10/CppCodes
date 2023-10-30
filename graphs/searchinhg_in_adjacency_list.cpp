#include <bits/stdc++.h>
using namespace std;
class Graph{
    protected:
     bool dfs_search(int pos,int data,bool * visited)
    {
        if(vertices[pos]==data) return 1;
        visited[pos]=1;
        for(auto &i : adj_list[pos])
        {
            if(!visited[i]) 
            {
                if(dfs_search(i,data,visited)) return 1;
            }
        }

        return 0;
    }
public:
vector<int> vertices;
vector<vector<int> > adj_list;
void add_vertex(int x)
{
    vertices.push_back(x);
    adj_list.push_back({});
    return ;
}
void add_edge(int a,int b)
{
    if(max(a,b)>=vertices.size()) return ;
    adj_list[a].push_back(b);
    return ;
}
void show_vertice()
{
    for(auto &i: vertices)
    {
        cout<<i<<"  ";
    }cout<<endl;return ;
}
void show_adjacency_list()
{
    for(auto &vect: adj_list)
    {
        for(auto &i : vect)
        cout<<i<<"  ";
        cout<<endl;
    }
}


int  dfs(int pos,int data)
{
    bool visited[vertices.size()]{0};
    return dfs_search(pos,data,visited);    
}

};
int main()
{
    Graph my_graph;
    my_graph.add_vertex(9);
    my_graph.add_vertex(2);
    my_graph.add_vertex(6);
    my_graph.add_vertex(5);
    my_graph.add_vertex(11);
    my_graph.add_vertex(23);
    my_graph.add_vertex(15);
    my_graph.show_vertice();


    my_graph.add_edge(0,2);
    my_graph.add_edge(1,3);
    my_graph.add_edge(5,6);
    my_graph.add_edge(1,0);
    my_graph.add_edge(1,5);
    my_graph.add_edge(2,5);
    my_graph.add_edge(5,8);

    
    my_graph.show_adjacency_list();
    cout<<"Wheather path exist or not";
    cout<<my_graph.dfs(1,6);

    return 0;
}