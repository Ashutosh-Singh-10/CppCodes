#include <bits/stdc++.h>
using namespace std;

int search_sorted_roatated_array(int arr[],int element,int n)
{
    int start=0;
    int end=n-1;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        cout<<arr[mid]<<endl;
        if(arr[mid]==element)
        {
            return mid;
        }
        else if(arr[mid]<element)
        {
            if(arr[start]<element)
            {
             start=mid+1;
            }
            else     end=mid-1;

        }
        else
        {
            if(arr[end]>element)
            {
                end=mid-1;
            }
            else  start=mid+1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={5, 6, 7, 8, 9, 10, 1, 2, 3};
    cout<<search_sorted_roatated_array(arr,10,9);


    return 0;
}