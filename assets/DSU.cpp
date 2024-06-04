#include<bits/stdc++.h>
using namespace std;
#define ll long long

class DSU{public:
    long long size=0;  vector<long long> vec;
    DSU(long long n)
    {
        size=n;
        for(long long i=0;i<n;i++)        vec.push_back(i);
    }
    void join(long long x,long long y){
        vector<long long> a,b;
        while(vec[x]!=x)
        {
            a.push_back(x);
            x=vec[x];
        }
        while(vec[y]!=y)
        {
            b.push_back(y);
            y=vec[y];
        }
        for(auto &i:a)    vec[i]=y;
        for(auto &i:b)    vec[i]=y;
        vec[x]=y;
    }
    long long parent(long long a)
    {
        vector<long long> arr;
        while(vec[a]!=a)
        {

         a=vec[a];
         arr.push_back(a);
        }
        for(auto &i:arr)
        {
            vec[i]=a;

        }
        return a;
    }
    void print()
    {
        for(auto & i:vec)cout<<i<<" ";cout<<endl;
    }
    long long clusters()
    {
        set<long long> st;
        for(long long i=0;i<size;i++)    st.insert(parent(i));
        return st.size();
    }
    void printClusters()
    {
        map<long long,vector<long long>> mp;
        for(int i=0;i<size;i++)
        {
            mp[parent(i)].push_back(i);
        }
        for(auto &[a,b]:mp)
        {
            cout<<a<<"    ->    ";
            for(auto  &j:b)
            {
                cout<<j<<" ";
            }
            cout<<"\n";

        }
    }

};





int main()
{
    auto d=new DSU(10);
    d->print();

d->join(3,5);
d->join(3,7);
d->join(9,5);
d->print();
cout<<(d->clusters());
d->join(9,3);

cout<<(d->clusters());
d->join(9,5);
cout<<(d->clusters());





    return 0;
}