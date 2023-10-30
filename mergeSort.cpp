#include <iostream>
using namespace std;
int merge(int *arr,int start,int mid,int end)
{  
    int temparr[end-start];
    int fptr=start,mptr=mid;
    int i=0;
    for(int i=0;i<(end-start);i++)
    {
        if (fptr!=mid && mptr!=end)
        {
            if(arr[fptr]>arr[mptr])
            {   
                 temparr[i]=arr[mptr];
                mptr++;
            }
            else {
                temparr[i]=arr[fptr];
                fptr++;
            }
        }
        else if(fptr!=mid)
        {
            temparr[i]=arr[fptr];
            fptr++;
        }
        else 
        {
            temparr[i]=arr[mptr];
            mptr++;
        }
    }
    for (int i=0;i<(end-start) ; i++)
    {
        arr[start+i]=temparr[i];
    }

    
}
void mergeSort(int *arr,int start ,int end)
{

    if (end-start==2)
    {
        if(arr[start]>arr[start+1])
        {
            arr[start]+=arr[start+1];
            arr[start+1]=arr[start]-arr[start+1];
            arr[start]=arr[start]-arr[start+1];
        }
        return ;
    }
    if(end-start==1)    return ;
    int mid=(start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid,end);
    merge(arr,start,mid,end);
    return ;
    
}
int main()
{
    int arr[11]={1,4,2,5,3,6,3,6,3,6,3};
    mergeSort(arr,0,11);
    cout<<endl<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}