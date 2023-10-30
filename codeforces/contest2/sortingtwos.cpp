#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,k,sz,ans,sum;
    cin>>t;
    int n;
    
    for(int l=0;l<t;l++)
    {
    int pos=1;
    int k=1;
    int cnt=1,temp,prev=INT_MIN;

        cin>>n;
    for(int i=0;i<n;i++)
    {

        cin>>temp;
        if(temp<prev)
        {
            pos=0;
        }
        prev=temp;
        if(cnt==k)
        {
            k*=2;
            prev=INT_MIN;
             
        }
        cnt++;
    }
        // cout<<endl;
        if(pos) cout<<"Yes";
        else cout<<"NO";
        cout<<endl;
        // cout<<endl;
        

        
      
    }
    return 0;

}