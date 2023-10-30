#include <bits/stdc++.h>
using namespace std;

class queue_list
{
    public:
    struct linked_list{
        int data;
        linked_list * next=NULL;
        linked_list(int x)
        {
         data=x;
        }

    };
    linked_list *start=NULL;
    linked_list *end;
    void add(int x)
    {
        if(start==NULL) 
        {
            start=new linked_list(x);
            end=start;
            return ;
        }
        linked_list * temp=new linked_list(x);
        end->next=temp;
        end=temp;
        
    }
    void show()
    {
        linked_list * temp=start;
        while(temp!=NULL)
        {
            cout<<temp->data<<"   ";
            temp=temp->next;

        }
    }
    int pop()
    {
        if(start==NULL) return -1;
        linked_list* temp=start;
        start=start->next;
        return temp->data;
    }
    int front()
    {
        if(start==NULL) return -1;
        return start->data;
    }
    bool is_empty()
    {
        if(start==NULL) return 1;
        return 0;
    }

};

class graph
{
public:
    int *arr;
    int **matrix;
    int size;
    graph(int data[], int n)
    {
        size = n;
        arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = data[i];
        }
        matrix = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    void add_edges(pair<int, int> edges[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[edges[i].first][edges[i].second] = 1;
            matrix[edges[i].second][edges[i].first] = 1;
        }
    }
    void show()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
    int dfs(int data, int pos, int *visited)
    {
        if (visited[pos] == 1)
            return 0;
        if (arr[pos] == data)
            return 1;
        visited[pos] = 1;
        cout << arr[pos] << endl;
        for (int i = 0; i < size; i++)
        {
            if (matrix[pos][i])
            {
                if (dfs(data, i, visited))
                    return 1;
            }
        }
        return 0;
    }
    int ans = INT_MAX;
    int min_diff_using_dfs(int data, int pos, int *visited, int path)
        {
            cout << "the current path is" << path << endl;

            int temp = INT_MAX;
            if (arr[pos] == data)
            {
                ans=min(ans,path);
                return 1;
            }
            visited[pos] = -1;
            for (int i = 0; i < size; i++)
            {
                if (matrix[pos][i])
                {
                    if (arr[i] == data)
                    {
                        ans = min(ans, path + 1);
                    }
                    else if (arr[i] == 0)
                    {
                        temp = min(temp, min_diff_using_dfs(data, i, visited, path + 1));
                    }
                    else if (arr[i] > 0)
                    {
                        temp = min(temp, arr[i] + 1);
                    }
                }
            }
            ans = min(ans, path + temp);
            arr[path] = temp;
            return temp + 1;
        }
    int shortest_path(int data, int pos)
    {
        ans=INT_MAX;
        
        int visited[5]{0};
        min_diff_using_dfs(data,pos, visited, 0);
        if (ans==INT_MAX) return -1;
        return ans;

        
    }

    int bfs(int data,int pos)
    {
        queue_list curr_level;
        curr_level.add(pos);
        int visited[size]{0};

    there:
        if(arr[curr_level.front()]==data) return curr_level.front();
        visited[curr_level.front()]=1;
        for(int i=0;i<size;i++)
        {
            if(visited[i]==0 && matrix[curr_level.front()][i])
            {
                curr_level.add(i);
            }
        }
        curr_level.pop();
        if(curr_level.is_empty()) return -1;
        goto there;




    }

    // int min_diff_using_dfs(int data,int pos,int *visited,int path)
    // {
    //     cout<<"first"<<endl;
    //     int temp=INT_MAX;
    //     if(arr[pos]==data)
    //     {
    //         return 1;
    //     }
    //     if(visited[pos]==-1) return 0;

    //     if(visited[pos]>0)
    //     {
    //         if(ans<path+visited[pos])
    //         ans=path+visited[pos];
    //         return visited[pos]+1;

    //     }
    //     else{

    //         for(int i=0;i<size;i++)
    //         {
    //             if(matrix[pos][i]==1 && visited[i]==0)
    //             {
    //             temp=min(temp,min_diff_using_dfs(data,i,visited,path+1));
    //             }
    //             if(matrix[pos][i]==1 && visited[i]>0)
    //             {
    //                 if(ans<path+1+visited[i])
    //                 ans=path+1+visited[i];
    //                 temp=min(temp,visited[pos]+1);
    //             }

    //         }
    //         if(temp==0) visited[pos]=-1;
    //         else visited[pos]=temp;
    //     }

    //     return temp+1;
    // }
};

int main()
{

    int arr[] = {4, 2, 6, 7, 9};
    pair<int, int> edges[5];
    edges[0] = make_pair(3, 2);
    edges[1] = make_pair(4, 2);
    edges[2] = make_pair(0, 1);
    edges[3] = make_pair(3, 0);

    int visited[5]{0};

    class graph *mygraph = new graph(arr, 5);
    mygraph->add_edges(edges, 4);
    // mygraph->show();
    cout<<mygraph->shortest_path(9,4);
    // mygraph->min_diff_using_dfs(9, 0, visited, 0);
    // cout << mygraph->ans;
    // cout<<mygraph->dfs(7,0,visited);

    cout<<"The bfs is as follows   ";
    cout<<mygraph->bfs(9,0);
    cout<<endl<<"end";
    return 0;
}