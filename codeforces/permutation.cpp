#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t=0;
    cin>>t;
    long long n,x,y;
    long long a,b,c,cm,temp,ans;
    for(int l=0;l<t;l++)
    {
        ans=0;
        cin>>n;
        cin>>x;
        cin>>y;
        a=n/x;
        b=n/y;
        cm=(x*y)/__gcd(x,y);
        c=n/cm;
        a-=c;
        b-=c;
        
            ans+=(a*((2*n)-a+1))/2;    
            ans-=(b*(b+1))/2;
            
        cout<<ans<<endl;


    }
    return 0;
}