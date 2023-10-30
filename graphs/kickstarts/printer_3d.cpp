#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,temp;
    int arr[4]{0};
    cin>>t;
    int ans[4]{0};
    int k=1000000;
    int sum=0;
    for(int cases=1;cases<=t;cases++)
    {
        cout<<"Case #"<<cases<<":";
        sum=0;
        for(int i=0;i<4;i++)
        {
            arr[i]=INT_MAX;
            ans[i]=0;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                cin>>temp;
                if(arr[j]>temp)
                {
                    arr[j]=temp;
                }
            }
        }
        for(int i=0;i<4;i++)
        {
            if(sum+arr[i]<=k)
            {
                ans[i]=arr[i];
                sum+=arr[i];
            }
            else{
                ans[i]=k-sum;
                sum=k;
                break;
            }
            
        }
        for(int i=0;i<4;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        if(sum<k)
        {
            cout<<" IMPOSSIBLE"<<endl;
            
        }
        else 
        {
            for(int i=0;i<4;i++)
            {
                cout<<" "<<ans[i];
            }
        }
        cout<<endl;
        
    }
    
    
    return 0;
}