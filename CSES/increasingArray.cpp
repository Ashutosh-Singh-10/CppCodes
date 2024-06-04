#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long prev=0;
    long long n,t,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t<prev)
        {
            ans+=prev-t;
            t=prev;
        }
        prev=t;
    }
    cout<<ans;

    return 0;
}