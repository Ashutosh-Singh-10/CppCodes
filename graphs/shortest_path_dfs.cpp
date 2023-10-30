#include <bits/stdc++.h>
using namespace std;

class Graph
{
  
    public:
    bool directed=true;
    vector<vector<int>> adjancency_list;
    int size=0;
    Graph(int points,bool is_directed=true)
    {
        directed=is_directed;
        size=points;
        while(points--)
        {
            adjancency_list.push_back(vector<int> ());
        }
    }
    void add_edge(int *arr,int n)
    {
        if(n%2) n--;

        for(int i=0;i<n;i+=2)
        {
            adjancency_list[arr[i]].push_back(arr[i+1]);
        }
        if(! directed)
        {
                for(int i=0;i<n;i+=2)
                {
                    adjancency_list[arr[i+1]].push_back(arr[i]);
                }
        }
    }
    void show_Graph()
    {
        for(auto &vect : adjancency_list)
        {
            for(auto &i: vect)
            {
                cout<<i<<"    ";
            }
            cout<<endl;
        }
    }

};


void shortest_path(Graph * my_Graph, int * visited, int *path,int node, int dist)
{
        if(path[node]>dist) path[node]=dist;
    else if(visited[node])
    {
        return;
    }
    visited[node]=1;
    // for (auto i:my_Graph->adjancency_list[node])
    for(int i=0;i<my_Graph->adjancency_list[node].size();i++)
    
    {
        // cout<<my_Graph->adjancency_list[node][i]<<"   ";
        shortest_path(my_Graph,visited,path,my_Graph->adjancency_list[node][i],dist+1);
    }
return ;
}


int main()
{
    Graph * my_graph =new Graph(5,0);
    int arr[]={0,1,0,3,0,4,1,2,3,2,4,2};
    my_graph->add_edge(arr,12);
    int * path=new int[my_graph->size]();
    int * visited=new int[my_graph->size]();
    // my_graph->show_Graph();

    for(int i=0;i<my_graph->size;i++)
    {
        cout<<"THE index is"<<i<<endl;
        path[i]=INT_MAX-1;
    my_graph->show_Graph();    
    }
    cout<<path+4<<endl;

    
    cout<<&my_graph->adjancency_list[1][0];
    
    
    shortest_path(my_graph,visited,path,0,0);
    for(int i=0;i<my_graph->adjancency_list.size();i++)
    {
        cout<<path[i]<<"   ";
    }
    return 0;
}