#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the upper limit of range from which you want to generate the prime twin -   ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
    }
    int iter;
    int temp;
    for(int i=3;i<=(n+1)/2;i+=2)
    {
        if(arr[i]==0)
        {
            iter=3;
            while(1)
            {
                temp=iter*i;
                if(temp>=n) break;
                arr[temp]=1;
                iter+=2;
            }
        }
    }
    iter=0;
    for(int i=3;i<n;i+=2)
    {
        if(arr[i]==0)
        {
            
            if(arr[i+2]==0)
            iter=i;
        }
    }
    if(iter)
    cout<<iter<<" "<<iter+2<<endl;
    else cout<<"No such pair exists";

}