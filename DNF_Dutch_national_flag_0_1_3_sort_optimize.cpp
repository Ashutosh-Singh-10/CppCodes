#include <iostream>
using namespace std;
int main()
{
    int arr[11]={1,2,0,0,1,1,2,1,2,0,0};
    int start=0,mid=0,end=10;
    while(!(end-mid==1))
    {
        if(arr[mid]==2)
        {
            arr[mid]=arr[end];
            arr[end]=2;
            end--;
        }
        else
        {
            if(arr[mid]==0)
            {
                arr[start]=0;
                start++;
                arr[mid]=1;
            }
            mid++;
            
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<"  ";
    }
}