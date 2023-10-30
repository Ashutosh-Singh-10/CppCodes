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
vector <int>  topological_sorting(Graph * my_graph)
{
    vector<int>  ans;
    int size=my_graph->adjancency_list.size();
    int arr[size]{0};
    for (auto &i: my_graph->adjancency_list)
    {
        for(auto & num :i)
        {
            arr[num]++;
        }
    }
stack<int> st ; 
for(int i=0;i<size;i++)
{   
    if(arr[i]==0)st.push(i);

}
while(! st.empty())
{
    int element=st.top();
    ans.push_back(element);
    st.pop();
    for(auto &i : my_graph->adjancency_list[element])
    {
        arr[i]--;
        if(arr[i]==0)
        st.push(i);
    }

}




    return ans;





    // for(int i=0;i<size;i++)
    // {
    //     cout<<arr[i]<<"  ";
    // }
    
}

int main()
{
    Graph * my_graph =new Graph(6);
    int arr[]={1,3,1,4,1,5,2,3,4,3,4,2,0,1};
    my_graph->add_edge(arr,14);
    my_graph->show_list();
    
    vector <int>  ans;
    ans=topological_sorting(my_graph);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"  ";
        
    }
    return 0;
}

