#include <bits/stdc++.h>
using namespace std;
#define V 9
vector<pair<int,int> >dijkstra(int graph[V][V],int pos)
{
    vector<pair <int,int> >shortest_path;
    int  path[V];
    for(int i=0;i<V;i++) path[i]=INT_MAX;
    path[pos]=0;
    int shortest;
    int elements=V;
    while(elements--)
    {
        shortest=0;
        for(int i=0;i<V;i++)
        {
            if(path[shortest]==-1) shortest=i;
            if(path[shortest]>path[i] && path[i]>=0) shortest=i;
        }
    for(int i=0;i<V;i++)
    {
        if (graph[shortest][i]>0 && path[i]>=0)
        {
            if(path[i]>path[shortest]+graph[shortest][i])
            path[i]=path[shortest]+graph[shortest][i];
        }

    }
    
    shortest_path.push_back(make_pair(shortest,path[shortest]));
    path[shortest]=-1;


    }
    for(int i=0;i<V;i++)
    {
        cout<<shortest_path[i].first<<"  "<<shortest_path[i].second<<endl;
    }


    return shortest_path;
}



int main()
{
    
        int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph,0);
    cout<<"int max is "<<INT_MAX;
        
    return 0;
}