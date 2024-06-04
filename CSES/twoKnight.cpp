#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long l;
    cin>>l;
    long long sub=0;
    cout<<0<<endl;
    for(long long n=2;n<=l;n++)
    {
        sub+=4*(2*n-1)-12;
        cout<<(n*n*(n*n-1))/2-sub<<endl;       
    }

    return 0;
}