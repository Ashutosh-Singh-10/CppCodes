#include<bits/stdc++.h>
using namespace std;
void fun(vector<int>&vec)
{
    for(auto i:vec)
    {
        cout<<i<<" ";
        i+=5;

    }
}
int main()
{

    vector<int> vec={1,3,5};
    fun(vec);
    cout<<endl; 
    for(auto &i:vec)
    {
        cout<<i<<" ";
    }
    return 0;
}