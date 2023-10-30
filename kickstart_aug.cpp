#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     int T;
//     cin>>T;
//     int n;
//     int ans;
//     while(T--)
//     {
//         cin>>n;
//         if(n<3)
//         {
//             cout<<ans;
//             continue;
//         }
//         ans=n/4;
//         if(n%4>1)
//         {
//             ans++;
//         }
//         cout<<ans;
        
//     }
//     return 0;
// }

int main()
{
    long long int T;
    cin>>T;
     long long int N;
    for(int k=1;k<T;k++)
    {
        cout<<"Case #"<<k<<": ";
        cin>>N;
         long long int arr1[N];
     
        for(int i=0;i<N;i++)
        {
            cin>>arr1[i];

        }
         
        long long int tempans=-1;
        for(long long int i=0;i<N;i++)
        {
            tempans=-1;
           
            for( long long int j=0;j<N;j++)
            {
                if(i==j)
                {
                    continue;
                }
                 else if(arr1[j]<=2*arr1[i])
                {
                    if(tempans<arr1[j])
                    {tempans=arr1[j];}
                }
    
            }
            cout<<tempans<<" ";
     

        }cout<<endl;


    }

    
    return 0;
    
}