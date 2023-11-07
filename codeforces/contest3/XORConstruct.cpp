#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int prev=0;
    int temp,ans=0;
    // cout<<0<<" ";
    int mx=0;
    vector<int> vec={0};
    int mxi=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>temp;
        ans=temp^ans;
        vec.push_back(ans);
        // mxi=mx^i;
        // mx=max(ans,mx);
     
        // prev=temp;
        
    }
    int ls=0;
    for(auto &i:vec)
    {
        if(i>=n-1)
        {
            ls=ls^i;
        }
    }
    // int bt=mx^(n-1);
    cout<<endl<<ls<<endl;
    for(auto &i:vec)
    {
        ans=ls^i;
        cout<<ans<<"  ";
    }

    return 0;
}