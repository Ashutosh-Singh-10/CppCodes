#include <bits/stdc++.h>
using namespace std;
void three_some(int arr[],int n,int req)
{
    sort(arr,arr+n);
    int i=0;
    while(arr[i]<req)
    {
        int start=i+1,end=n-1;
        while(start<end)
        {
            if(arr[i]+arr[start]+arr[end]==req)
            {
                cout<<arr[i]<<"    "<<arr[start]<<"    "<<arr[end]<<endl;
                return ;
                
            }
            else if(arr[i]+arr[start]+arr[end]>req) end--;
            
            else start++;
        }
        

        i++;
    }cout<<"no number found";
    
}
int main()
{
    int arr[]={1,2,4,6,2,8};
    three_some(arr,6,0);
    return 0;
}