#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    int x=5;
    while(x<=n)
    {
        ans+=n/x;
        x*=5;
    }
    cout<<ans;
    return 0;
}