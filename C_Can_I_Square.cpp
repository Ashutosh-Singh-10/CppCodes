// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int temp,sum=0;;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            sum+=temp;
        }
        int sq=sqrt(sum);
        if(sq*sq==sum)
        {
            cout<<"YES";

        }
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}