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

void dfs_sorting(Graph * my_graph, bool * inserted,stack<int> * st,int index)
{
    
    if(inserted[index]) return ;
    for(auto & i : my_graph->adjancency_list[index])
    {

        dfs_sorting(my_graph,inserted,st,i);
    }
    cout<<index<<endl;
    st->push(index);
    inserted[index]=1;

}
stack<int> *topological_sorting(Graph * my_graph)
{
    bool *inserted=new bool[my_graph->size]();
    stack<int> * st=new stack<int>;


    for(int i=0;i<my_graph->size;i++)
    {
        dfs_sorting(my_graph,inserted,st,i);
    }
return st;
    // while(!st->empty())
    // {
    //     cout<<st->top();
    //     st->pop();
    // }
}

void shortest_path_DAG_topological(Graph * my_graph , int * path )
{
    stack<int> * st=new stack<int>;
     st=topological_sorting(my_graph);
    cout<<"hii";
    while(!st->empty())
    {   int element=st->top();
        st->pop();
        for(auto & i: my_graph->adjancency_list[element])
        {
            if(path[element]<path[i]-1)
            {
                path[i]=path[element]+1;
            }
        }
    }

}


int main()
{
    Graph * my_graph =new Graph(6);
        int arr[]={1,3,1,4,1,5,2,3,4,3,4,2,0,1};

    my_graph->add_edge(arr,14);
    int * path=new int[my_graph->size]();
    
    my_graph->show_Graph();
for(int i=0;i<my_graph->size;i++)
{
    path[i]=INT_MAX;
}  
path[0]=0;
shortest_path_DAG_topological(my_graph,path);

for(int i=0;i<my_graph->size;i++)
{
    cout<<path[i];
}
   
    return 0;
}
