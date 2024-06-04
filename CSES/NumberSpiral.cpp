#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t ;
    while(t--)
    {
        long long x,y;
        cin>>x>>y;
        if(x>y)
        {
            if(x%2==1)
            {
                cout<<((x-1)*(x-1))+y;
            }
            else 
            {
                cout<<(x)*(x)-y+1;

            }


        }
        else 
        {
            if(y%2==0)
            {
                cout<<((y-1)*(y-1))+x;
            }
            else 
            {
                cout<<(y)*(y)-x+1;

            }
        }
        cout<<endl;
    }
    return 0;
}