#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    // binary search;
    ll ans=0,start,end;
    while(start<=end)
    {
        ll mid=start+(end-start)/2;
        if(cost(mid))
        {
            ans=min(ans,mid);
            end=mid-1;
        }
        else start=mid+1;

    }
    return 0;
}