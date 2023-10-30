#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,temp,m1=INT_MAX,m2=INT_MAX,sm1=0,sm2=0;
    cin>>t;
    for(int l=0;l<t;l++)
    {
    cin>>n;
    m1=INT_MAX;m2=INT_MAX;sm1=0;sm2=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sm1+=temp;
        m1=min(m1,temp);
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sm2+=temp;
        m2=min(m2,temp);
    }
    cout<<min(sm2+(m1*n),(m2*n)+sm1)<<endl;
    }
    return 0;

}