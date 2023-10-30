// #include <bits/stdc++.h>
// using namespace std;

// class Graph
// {
  
//     public:
//     bool directed=true;
//     vector<vector<int>> adjancency_list;
//     int size=0;
//     Graph(int points,bool is_directed=true)
//     {
//         directed=is_directed;
//         size=points;
//         while(points--)
//         {
//             adjancency_list.push_back(vector<int> ());
//         }
//     }
//     void add_edge(int *arr,int n)
//     {
//         if(n%2) n--;

//         for(int i=0;i<n;i+=2)
//         {
//             adjancency_list[arr[i]].push_back(arr[i+1]);
//         }
//         if(! directed)
//         {
//                 for(int i=0;i<n;i+=2)
//                 {
//                     adjancency_list[arr[i+1]].push_back(arr[i]);
//                 }
//         }
//     }
//     void show_Graph()
//     {
//         for(auto &vect : adjancency_list)
//         {
//             for(auto &i: vect)
//             {
//                 cout<<i<<"    ";
//             }
//             cout<<endl;
//         }
//     }

// };

// void dfs_sorting(Graph * my_graph, bool * inserted,stack<int> * st,int index, int visited[6])
// {
    
//     if(inserted[index]) return ;
//     // if(visited[index]) return ;
//     for(auto & i : my_graph->adjancency_list[index])
//     {
//         visited[i]=1;
//         dfs_sorting(my_graph,inserted,st,i,visited);
//     }
//     cout<<index<<endl;
//     st->push(index);
//     inserted[index]=1;

// }
// void topological_sorting(Graph * my_graph)
// {
//     bool *inserted=new bool[my_graph->size]();
//     stack<int> * st=new stack<int>;
// int visited[]={0,0,0,0,0,0};

//     for(int i=0;i<my_graph->size;i++)
//     {
//         cout<<"the arr is  ";
//         for(int j=0;j<my_graph->size;j++)
//         {
//             cout<<visited[j];
//         }
//         cout<<endl;
//         dfs_sorting(my_graph,inserted,st,i,visited);
//     }

//     while(!st->empty())
//     {
//         cout<<st->top();
//         st->pop();
//     }
// }
// int main()
// {


//     Graph * my_graph =new Graph(6);
//     int arr[]={1,3,1,4,1,5,2,3,4,3,4,2,0,1};
//     my_graph->add_edge(arr,14);
//     my_graph->show_Graph();
    
//     // vector <int>  ans;
//     topological_sorting(my_graph);
//     // for(int i=0;i<ans.size();i++)
//     // {
//     //     cout<<ans[i]<<"  ";
        
//     // }
     
//      return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void func(int arr[],int i)
{
    arr[i]=1;
    

}
void temp()
{
    int arr[]={0,0,0,0,0};

for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {
        cout<<arr[i];
        
    }
    cout<<endl;
    func(arr,i);
}
}
int main()
{
    temp();
    return 0;
    
}