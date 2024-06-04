#include <bits/stdc++.h>
using namespace std;
class Graph{
protected:
bool directed=1;
public:
int ans=0;
int temp=0;

vector<vector<int>> adjancency_list;
Graph(int points,int is_directed=1)
{

    while(points--) adjancency_list.push_back({}); 
    return ;

}
void add_point(int points=1)
{
    while(points--) adjancency_list.push_back({}); return ;
    
}
void add_edge(int a,int b)
{
    cout<<adjancency_list.size();
    if(!adjancency_list[a-1].size())
    {
        cout<<"1";
        vector<int> temp_vect;
        cout<<"mid";
        cout<<endl<<"the value of b is "<<b<<endl;
        temp_vect.push_back(90);
        cout<<"2";
        adjancency_list[a-1]=temp_vect;
        return ;
    }
    cout<<"3";
    adjancency_list[a-1].push_back(b-1);
return ;
}

int algo(int n,int * data)
{
    ans=0;
    int *arr =new int(n);
    int *saved;
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            saved=new int(n);
            for(int i=0;i<n;i++)
            {
                saved[i]=0;
            }
            temp=0;
            count(i,saved,arr,data);
            if(temp>ans)
            {
                ans=temp;
            }

        }
    }
    return ans;
    
}
void count (int num,int *saved,int *arr,int *data)
{
    
    temp++;
    for(int i=0;i<adjancency_list[num].size();i++)
    {
        
        if(data[num]>data[i] && saved[i]==0)
        {
            arr[i]=1;
            saved[i]=1;
            count(i,saved,arr,data);
        }
    }
    return ;
}

};
   
int main()
{
    int t;
    cin>>t;
    int *data;
    int n,a,b;
    int data_taking;
    Graph *mygraph;
    for(int i=0;i<t;i++)
    {
        
        cin>>n;
        mygraph=new Graph(n);
        data=new int(n);
        for(int i=0;i<n;i++)
        {
            cin>>data_taking;
                data[i]=data_taking;
        }
        for(int i=0;i<n-1;i++)
        {
            cin>>a;
            cin>>b;
            mygraph->add_edge(a,b);            
        }
        mygraph->algo(n,data);
        cout<<mygraph->ans;

        

    }


return 0;
}



























