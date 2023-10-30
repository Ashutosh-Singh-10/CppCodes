#include <bits/stdc++.h>
using namespace std;
class Graph{
protected:
bool directed=1;
public:

vector<vector<int>> adjancency_list;
Graph(int points,int is_directed=1)
{
    directed=is_directed;
    while(points--) adjancency_list.push_back({}); return ;

}
void add_point(int points=1)
{
    while(points--) adjancency_list.push_back({}); return ;
    
}
void add_edge(int a,int b)
{
    adjancency_list[a].push_back(b);
    if(!directed) adjancency_list[b].push_back(a); return ;
}
void add_edge(int *arr,int n)
{
    if(n%2==1) n--;
    for(int i=0;i<n;i+=2)     adjancency_list[arr[i]].push_back(arr[i+1]);
    if(!directed) for(int i=0;i<n;i+=2) adjancency_list[i+i].push_back(i); 
    return ;

}
void show_list()
{
    for(auto &vect : adjancency_list)
    {
        for(auto & i : vect)
        {
            cout<<i<<"   ";
        }
        cout<<endl;

    }
}


};
bool dfs_cycle_detection(Graph * my_graph,int *visited,int  in_stack[],int size,int index)
{
    if(visited[index]==1 )
    return 0;
    if( in_stack[index]==1) return 1;
    visited[index]=1;
    in_stack[index]=1;
    for(auto & i: my_graph->adjancency_list[index])
    {
        if(dfs_cycle_detection(my_graph,visited,in_stack,size,i)) return 1;

    }
    
return 0;
}

bool cycle_detection(Graph * my_graph)
{
    int size=my_graph->adjancency_list.size();
    int *visited=new int[size]();
    int  in_stack[size]{0};
    for(int i=0;i<size;i++)
    {
        if(! visited[i])
        {
            if(dfs_cycle_detection(my_graph, visited,in_stack,size,i)) return 1;
        }
    }
    
    return 0;
    


}
int main()
{
    
    Graph * my_graph =new Graph(6);
    int arr[]={1,3,1,4,1,5,2,3,4,3,4,2,0,1,5,1};
    my_graph->add_edge(arr,16);
    my_graph->show_list();

    cout<<" The graph is " << cycle_detection(my_graph);
return 0;

}
