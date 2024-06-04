#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    if(((n*(n+1))/2)&1)
    {
        cout<<"NO";
        return 0;
    }
    vector<int> a;
    vector<int>b;
    long long s=0,t=0;
    cout<<"YES"<<endl;
    for(int i=n;i>=1;i--)
    {
        if(s<t)
        {
            a.push_back(i);
            s+=i;
        }

        else
        {
            t+=i;
            b.push_back(i);
        }
    }
    cout<<a.size()<<endl;
    for(auto &i:a) cout<<i<<" ";
    cout<<endl;
    cout<<b.size()<<endl;
    for(auto &i:b) cout<<i<<" ";
    cout<<endl;
    
    
    return 0;
}