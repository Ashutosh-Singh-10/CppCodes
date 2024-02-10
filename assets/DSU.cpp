#include<bits/stdc++.h>
using namespace std;
#define ll long long
void join(vector<ll> & vec,ll x,ll y)
{
    vector<ll> a;
    while(x!=vec[x])
    {
        x=vec[x];
        a.push_back(x);
    }
    while(y!=vec[y])
    {
        a.push_back(y);
        y=vec[y];
    }
    for(auto &i:a)
    {
        vec[i]=y;
    }
    
}
ll parent(vector<ll> & vec,ll x)
{
while(x!=vec[x]) x=vec[x];
return x;
}


int main()
{
    return 0;
}