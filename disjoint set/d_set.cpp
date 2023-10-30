#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    int v=0;
    vector<int> vec;
    DisjointSet(int x)
    {
        v=x;
        for(int i=0;i<v;i++)
        {
            vec.push_back(i);
        }
    }
    void make_union(int a,int b)
    {
        while(true)
        {
            if(vec[b]==b)
            {
                break;
            }
            b=vec[b];
        }
        while(true)
        {
            if(vec[a]==a)
            {
                break;
            }
            a=vec[a];
        }
        vec[b]=a;
        show();

    }
    void show()
    {
        for(const auto &i:vec)
        {
            cout<<i<<"  ";
        }
        cout<<endl;
    }
    int parent(int x)
    {
        while(true)
        {
            if(vec[x]==x) return x;
            x=vec[x];
        }
        
    }


};
int main()
{
    cout<<__gcd(75,88)<<endl;
    cout<<__gcd(21,88);
    // DisjointSet * ds=new DisjointSet(5);
    // ds->make_union(0,3);
    // ds->make_union(1,2);
    // ds->make_union(1,3);
    // for(int i=0;i<5;i++)
    // {
    //     cout<<ds->parent(i);
    // }

    
    return 0;
}