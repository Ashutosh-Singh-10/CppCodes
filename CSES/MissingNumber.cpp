#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long t,sum=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>t;
        sum+=t;
    }
    cout<<((n*(n+1))/2)-sum;
    return 0;
}