#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> vec(4,INT_MAX);
    vec[0]=0;
    vector<vector<pair<int,int>>> graph={
        {{1,1},{2,4}},
        {{2,-3},{3,2}},
        {{3,3}},
        {}
    };
    for(int i=1;i<vec.size();i++)
    {
        for(int j=0;j<graph.size();j++)
        {
            if(vec[j]!=INT_MAX)
            {
                for(auto &p:graph[j])
                {
                    vec[p.first]=min(vec[p.first],vec[j]+p.second);
                }
            }
        }
    }
    for(auto &i:vec)
    {
        cout<<i<<"  ";
    }





    return 0;
}